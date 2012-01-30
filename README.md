## DESCRIPTION

Builds a Drupal environment and site on top of a Vagrant vm. This repo
can be used as is to get a Drupal site up and running quickly or as a
template for your own Drupal projects.

## REQUIREMENTS

* [This project's source](https://github.com/xforty/vagrant-drupal)
* Not windows (haven't tested it yet, but you can try)
* Ruby >= 1.9.2 (do yourself a favor and use
  [rvm](http://beginrescueend.com/) to manage your ruby environment)
* [VirtualBox](http://www.virtualbox.org/)
* [vagrant](http://www.vagrantup.com/) gem 0.9.x
* [chef](http://wiki.opscode.com/) gem
* [librarian](https://github.com/applicationsonline/librarian) gem

## BASIC USAGE

1. Start on the host by provisioning and logging into a vm:

        host$ git clone git://github.com/xforty/vagrant-drupal.git
        host$ cd vagrant-drupal
        host$ librarian-chef install
        host$ vagrant up
        host$ vagrant ssh

2. Then build and install a drupal site on the vm:

        vm$ sudo drush make --prepare-install /vagrant/example.make /srv/www
        vm$ cd /srv/www
        vm$ sudo drush site-install --db-url=mysql://dbuser:password@localhost/drupal

3. Go to [http://localhost:4567](http://localhost:4567) and log in
   to the drupal site with the credentials specified in the site-install
   output.

## Vagrant

It is common to modify the Vagrantfile. We encourage you to read through the
comments in the Vagrantfile as well as the official
[Vagrant documentation](http://www.vagrantup.com) for other possible
configurations.

## RESOURCES

* [xforty-drupal](https://github.com/xforty/xforty-drupal) - extendable and
  overridable drupal make files
* [Project Wiki](https://github.com/xforty/vagrant-drupal/wiki) - HowTos,
  FAQs, and advanced usage
* [Project Issues](https://github.com/xforty/vagrant-drupal/issues) - submitting
  bugs and feature requests

--------------------------------------------------------------------- 
Maintained by [xforty technologies](http://www.xforty.com)
