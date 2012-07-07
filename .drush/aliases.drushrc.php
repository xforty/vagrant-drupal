<?php 

$project_name = 'drupal'; // value of :project_name from Vagrantfile

$aliases['local'] = array(
  'uri' => "local.$project_name",
  'root' => '/srv/www',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/tmp/sql-sync-local.sql',
  ),
  'command-specific' => array (
    'sql-sync' => array (
      'structure-tables' => array(
        'custom' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
      ),
    ),
    'rsync' => array (
      'mode' => 'rlptDz',
    ),
  ),
);

/*
$aliases['old'] = array(
  'uri' => "old.$project_name",
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/home/<remote_user>/tmp/sql-sync-old.sql',
  ),
);
//*/

/*
$aliases['dev'] = array(
  'uri' => "dev.$project_name",
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/home/<remote_user>/tmp/sql-sync-dev.sql',
  ),
);
//*/

/*
$aliases['test'] = array(
  'uri' => "test.$project_name",
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/home/<remote_user>/tmp/sql-sync-test.sql',
  ),
);
//*/

/*
$aliases['staging'] = array(
  'uri' => "staging.$project_name",
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/home/<remote_user>/tmp/sql-sync-staging.sql',
  ),
);
//*/

/*
$aliases['prod'] = array(
  'uri' => "[www.]$project_name",
  'root' => '',
  'remote-host' => '',
  'remote-user' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%dump' => '/home/<remote_user>/tmp/sql-sync-prod.sql',
  ),
);
//*/
