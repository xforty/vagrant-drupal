<?php

/**
 * @file
 *   Policy commandfile.
 *
 *   Validates commands as they are issued and returns an error
 *   or changes options when policy is violated.
 *
 *   You can copy this file to any of the following
 *     1. A .drush folder in your HOME folder.
 *     2. Anywhere in a folder tree below an active module on your site.
 *     3. /usr/share/drush/commands (configurable)
 *     4. In an arbitrary folder specified with the --include option.
 *     5. Drupal's sites/all/drush folder.
 */

/**
 * Implements hook help alter.
 *
 * When a hook extends a command with additional options, it must
 * implement help alter and declare the option(s).  Doing so will add
 * the option to the help text for the modified command, and will also
 * allow the new option to be specified on the command line.  Without
 * this, Drush will fail with an error when a user attempts to use
 * the option.
 */
function policy_drush_help_alter($command) {
  switch ($command['command']) {
    case 'sql-sync':
    case 'core-rsync':
      $command['options']['override'] = 'Allows you to override the '
          . 'policy file and overwrite the production site and database. '
          . 'You must specify a confirmation code for the --override '
          . 'command option. The code is found in the policy file. '
          . 'Be careful! Overriding production is rarely the correct '
          . 'course of action. Typically, it should only be used for the '
          . 'initial push to production. If you use this option and the '
          . 'correct confirmation code, you will be prompted one last time '
          . 'before the command is executed.';
      break;
    default:
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate() for sql-sync.
 *
 * Prevent catastrophic braino. Note that this file has to be local to
 * the machine that intitiates the sql-sync command.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  $result = true;
  $destination = _drush_policy_parse_alias($destination);

  if ($destination == '@prod') {
    $result = _drush_policy_override_validate($destination, 'database');
  }

  return $result;
}

/**
 * Implementation of drush_hook_COMMAND_validate() for core-rsync.
 *
 * Prevent catastrophic braino. Note that this file has to be local to
 * the machine that intitiates the core-rsync command.
 */
function drush_policy_core_rsync_validate($source, $destination, $additional_options = array()) {
  $result = true;
  $destination = _drush_policy_parse_alias($destination);

  if ($destination == '@prod') {
    $result = _drush_policy_override_validate($destination, 'files and/or code');
  }

  return $result;
}

/**
 * Separates and returns the full drush alias from the alias string.
 *
 * Path-aliases may be attached to a drush alias. They are separated
 * from the drush alias by a colon (:). We need to return just the
 * drush alias so we know exactly which drush alias was called.
 * Just checking if the drush alias starts with the desired string
 * will not suffice.
 *
 * Format:   @<alias>:%<path-alias>
 * Example:  drush rsync @prod:%files @local:%files
 */
function _drush_policy_parse_alias($alias) {
  $pieces = explode(':', $alias, 2);
  return $pieces[0];
}

/**
 * Confirms override option was specified with the correct confirmation code.
 *
 * If override option is not specified or the confirmation code is not correct,
 * an error is displayed to the user. Otherwise, a prompt is displayed asking
 * the user for one last confirmation.
 */
function _drush_policy_override_validate($alias, $component) {
  $result = true;
  $code = 'dgT34kdFs8'; // confirmation code
  $override = drush_get_option('override');

  if (is_null($override)) {
    $result = drush_set_error(dt("Overwriting $alias requires a confirmation "
        . 'code to override policy.drush.inc. Use --help to learn more about '
        . 'override option.'));
  } elseif ($override == 1 || $override == '') {
    $result = drush_set_error(dt('No confirmation code specified for '
        . 'override option. Look in policy.drush.inc for the correct code.'));
  } elseif ($override == $code) {
    $response = drush_prompt(dt("Are you sure you want to overwrite the "
        . "$component for the alias $alias? This cannot be undone! "
        . "Y[es] or N[o]"));
    $response = strtolower(trim($response));
    if ($response == 'y' || $response == 'yes') {
      $result = true;
    } else {
      $result = drush_user_abort();
    }
  } else {
    $result = drush_set_error(dt('Incorrect confirmation code specified for '
        . 'override option. Look in policy.drush.inc for the correct code.'));
  }

  return $result;
}
