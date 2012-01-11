DESCRIPTION
===========

Template repo for a new drupal project built on top of a vagrant vm.

REQUIREMENTS
============

* Not windows (haven't tested it yet, but you can try)
* [VirtualBox](http://www.virtualbox.org/] >= 4.1
* Ruby 1.9 (just use rvm to manage your ruby version)
* [chef](http://wiki.opscode.com/display/chef/Installing+Chef+Client+and+Chef+Solo) gem >= 0.10
* [vagrant](http://www.vagrantup.com/) gem
* [librarian](https://github.com/applicationsonline/librarian) gem

BASIC USAGE
===========

1. Start on the host by provisioning and logging into a vm:

        host$ git clone git://github.com/xforty/vagrant-drupal-project.git
        host$ cd vagrant-drupal-project
        host$ librarian-chef install
        host$ vagrant up
        host$ vagrant ssh

2. Then build and install a drupal site on the vm:

        vm$ sudo drush make --prepare-install /vagrant/example.make /srv/www
        vm$ cd /srv/www
        vm$ sudo drush site-install --db-url=mysql://dbuser:password@localhost/drupal

3. Go to <tt>[http://localhost:4567](http://localhost:4567)</tt> and log in to the drupal site with the
   credentials specified in the site-install output.

ADVANCED USAGE
==============

By default the remote origin is the github vagrant-drupal-project.  It is
designed to function after you clone it for development and testing purposes.
This means you can commit to your local repository and track upstream changes.
This is useful for single user development workflow.  However we also kept in
mind people work on teams and need to share these repositories for each project
they are working on.  To do this we recommend the following.

* Rename the remote origin

        host$ git remote rename origin github

* Create your bare repo

* Add your own remote origin

        host$ git remote add origin git@scm.xforty.com:www.xforty.com.git

* Push your changes to your bare repo

        host$ git push origin master

If you are cloning from the www.xforty.com.git repo it won't contain the
original github project. You need to add that remote. Here is how:

    host$ git remote add xforty git://github.com/xforty/vagrant-drupal-project.git

NOTE: This is a read-only repository.

It is common to modify the Vagrantfile.  Consider using our
[https://github.com/xforty/xforty-drupal](https://github.com/xforty/xforty-drupal)
project as a starting point for your drupal make files.
