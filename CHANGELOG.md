vagrant-drupal changelog
========================

### 0.4.2 (January 9, 2013)

  * Update reference to xforty-drupal xforty.make

### 0.4.1 (November 19, 2012)

  * Use initdb cookbook version 1.0.1

### 0.4.0 (August 14, 2012)

  * Use upstream drush cookbook [GH-70]

  * Bump required librarian gem version to 0.24 [GH-69]

  * Pin cookbook versions [GH-68]

  * Change attributes from symbols to strings [GH-61]

### 0.3.0 (August 3, 2012)

  * Standardized chef debug flag name [GH-66]

  * Edited project overview in readme to better reflect purpose [GH-63]

  * Updated policy.drush.inc to work with path-aliases [GH-60]

  * `librarian-chef install` is only called during `vagrant up` [GH-58]

  * Added avahi (zeroconf) for automatic dns [GH-59]

  * Host name of vm set [GH-54]

  * Resolved collisions with sql dump filenames [GH-52]

  * Tuned down apache prefork options [GH-46]

  * Added ability to override @prod security policy [GH-45]

  * example.make uses xforty-drupal for base make file [GH-40]

  * `librarian-chef install` is called automatically [GH-28]

  * HTTP request status now works with host-only networking [GH-10]

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
