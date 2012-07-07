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
 * Implementation of drush_hook_COMMAND_validate() for sql-sync.
 *
 * Prevent catastrophic braino. Note that this file has to be local to
 * the machine that intitiates the sql-sync command.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if (_drush_policy_parse_alias($destination) == '@prod') {
    return drush_set_error(dt('Per policy.drush.inc, you may never overwrite '
        . 'the production database.'));
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate() for core-rsync.
 *
 * Prevent catastrophic braino. Note that this file has to be local to
 * the machine that intitiates the core-rsync command.
 */
function drush_policy_core_rsync_validate($source, $destination, $additional_options = array()) {
  if (_drush_policy_parse_alias($destination) == '@prod') {
    return drush_set_error(dt('Per policy.drush.inc, you may never overwrite '
        . 'the production code or files folder.'));
  }
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
function _drush_policy_parse_alias($alias_string) {
  $pieces = explode(':', $alias_string, 2);
  return $pieces[0];
}
