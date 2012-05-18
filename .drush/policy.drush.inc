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
 * Implementation of drush_hook_COMMAND_validate().
 *
 * Prevent catastrophic braino. Note that this file has to be local to the machine
 * that intitiates sql-sync command.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if ($destination == '@prod') {
    return drush_set_error(dt('Per policy.drush.inc, you may never overwrite the production database.'));
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate().
 *
 * Prevent catastrophic braino. Note that this file has to be local to the machine
 * that intitiates core-rsync command.
 */
function drush_policy_core_rsync_validate($source, $destination, $additional_options = array()) {
  if ($destination == '@prod') {
    return drush_set_error(dt('Per policy.drush.inc, you may never overwrite the production files folder.'));
  }
}
