<?php 
$aliases['local'] = array(
  'uri' => 'local.drupal', // local.[project_name_from_vagrantfile]
  'root' => '/srv/www',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/tmp/sql-sync-local.sql', // Arbitrary location for temp files
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '0',
      'structure-tables' => array(
        'custom' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
      ),
    ),
    'rsync' => array (
      'simulate' => '0',
      'mode' => 'rlptDz',
    ),
  ),
);

/*
$aliases['dev'] = array(
  'uri' => 'dev.[project_name]',
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '[path_to_tmp]/sql-sync-dev.sql',
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);
#*/

/*
$aliases['test'] = array(
  'uri' => 'test.[project_name]',
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '[path_to_tmp]/sql-sync-test.sql',
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);
#*/

/*
$aliases['staging'] = array(
  'uri' => 'staging.[project_name]',
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '[path_to_tmp]/sql-sync-staging.sql',
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);
#*/

/*
$aliases['prod'] = array(
  'uri' => 'www.[project_name]', // could also be any other subdomain
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '[path_to_tmp]/sql-sync-prod.sql',
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);
#*/
