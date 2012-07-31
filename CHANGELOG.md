vagrant-drupal changelog
========================

### 0.3.0 (unreleased)


### 0.2.1 (July 31, 2012)

  * Fix error installing squid due to old package name [GH-65]

### 0.2.0 (May 28, 2012)

  * Performance improvements for 0.2.0 [GH-43]

  * Set default vm box to ubuntu-10.04.4-server-amd64 [GH-39]

  * Update chef-drupal cookbook to remove :server_name [GH-34]

  * Update chef-drush cookbook for drush 5 [GH-33]

  * Turn off ssh host key checking [GH-29]

  * Add a policy file for drush commands [GH-27]

  * Update Cheffile to use opscode's new cookbooks structure [GH-26]

  * Moved owner to vagrant for shared_folders [GH-25]

  * Update db credentials in Vagrantfile to default Drupal settings.php [GH-23]

  * Set vagrant dep to >= 1.0.3 [GH-21]

  * Add .drush directory with default alias file [GH-16]

  * Add squid proxy recipe [GH-12]

  * Add NFS option for shared folders, commented out [GH-6]

### Previous

The changelog began with version 0.2.0 so any changes prior to that
can be seen by checking the tagged releases and reading git commit
messages.
