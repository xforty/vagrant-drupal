## DESCRIPTION

Template repo for a new drupal project built on top of a vagrant vm.

## REQUIREMENTS

* [This project's source](https://github.com/xforty/vagrant-drupal)
* Not windows (haven't tested it yet, but you can try)
* Ruby >= 1.9.2 (do yourself a favor and use
  [rvm](http://beginrescueend.com/) to manage your ruby environment)
* [VirtualBox](http://www.virtualbox.org/)
* [vagrant](http://www.vagrantup.com/) gem
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

## ADVANCED USAGE

By default the remote origin is the github vagrant-drupal.  It is
designed to function after you clone it for development and testing purposes.
This means you can commit to your local repository and track upstream changes.
This is useful for single user development workflow.  However we also kept in
mind people work on teams and need to share these repositories for each project
they are working on.  To do this we recommend the following.

* Rename the remote origin: `git remote rename origin github`
* Create your bare repo
* Add your own remote origin: `git remote add origin [your_repo_name]`
* Push your changes to your bare repo: `git push origin master`

If you are cloning directly from your repo it won't contain the original
github project. In that case, you will need to add the upstream remote:
`git remote add xforty git://github.com/xforty/vagrant-drupal.git`

It is common to modify the Vagrantfile. We encourage you to read through the
comments in the Vagrantfile as well as the official
[Vagrant documentation](http://www.vagrantup.com) for other possible
configurations.

Also consider using our [xforty-drupal](https://github.com/xforty/xforty-drupal)
project as a starting point for your own drupal make files.

## RESOURCES

* [Wiki](https://github.com/xforty/vagrant-drupal/wiki)
* [Issues](https://github.com/xforty/vagrant-drupal/issues)

--------------------------------------------------------------------- 
&copy; 2011, [xforty technologies](http://www.xforty.com)
