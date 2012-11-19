vagrant-drupal
==============
version 0.5.x - [changelog](https://github.com/xforty/vagrant-drupal/blob/master/CHANGELOG.md)

A project template for building reproducible and portable local Drupal
development environments. If you want to learn more about the project,
see the [resources](https://github.com/xforty/vagrant-drupal#resources)
section below.

### Requirements

* [Not Windows](https://github.com/xforty/vagrant-drupal/wiki/Windows)
* [Vagrant-drupal](https://github.com/xforty/vagrant-drupal)
* [Ruby](http://www.ruby-lang.org/) >= 1.9.2 (on both host and base box)
* [VirtualBox](http://www.virtualbox.org/) >= 4.1.0
* [Vagrant gem](http://www.vagrantup.com/) >= 1.0.3
* [Chef gem](http://wiki.opscode.com/) >= 0.10.8
* [Librarian gem](https://github.com/applicationsonline/librarian) >= 0.0.24
* [Ubuntu base box](https://github.com/xforty/vagrant-drupal/wiki/Base-Boxes) >= 10.04 (default base box already defined)

### Basic Usage

1. Start on the host by provisioning and logging into a vm:

        host$ git clone git://github.com/xforty/vagrant-drupal.git
        host$ cd vagrant-drupal
        host$ vagrant up
        host$ vagrant ssh

2. Then build and install a drupal site on the vm:

        vm$ drush make --prepare-install /vagrant/example.make /srv/www
        vm$ cd /srv/www
        vm$ drush site-install --db-url=mysql://username:password@localhost/drupal

3. Go to [http://localhost:4567](http://localhost:4567) and log in
   to the drupal site with the credentials specified in the site-install
   output.

### Vagrantfile

It is common to modify the Vagrantfile to meet project needs.
We encourage you to read through the comments in the
[Vagrantfile](https://github.com/xforty/vagrant-drupal/blob/master/Vagrantfile)
as well as the [official documentation](http://vagrantup.com/v1/docs/vagrantfile.html)
for other possible configurations.

### Resources

* [xforty-drupal](https://github.com/xforty/xforty-drupal) - extendable and
  overridable drush make files
* [Project Wiki](https://github.com/xforty/vagrant-drupal/wiki) - HowTos,
  FAQs, and advanced usage
* [Project Issues](https://github.com/xforty/vagrant-drupal/issues) - submit
  bugs, support questions, and feature requests
* [Base Boxes](https://github.com/xforty/vagrant-drupal/wiki/Base-Boxes) -
  links to resources for finding pre-built boxes or building your own
* [Development](https://github.com/xforty/vagrant-drupal/wiki/Development) -
  details on the project's development workflow

--------------------------------------------------------------------- 
Maintained by [xforty technologies](http://www.xforty.com)
