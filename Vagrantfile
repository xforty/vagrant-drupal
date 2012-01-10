# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant::Config.run do |config|
  
  #
  # Name of imported base box.
  #
  config.vm.box = "lucid32"
  
  #
  # Download url of base box if it has not been previously imported.
  # See http://vagrantbox.es/ for more pre-built base boxes or
  # build your own using https://github.com/jedi4ever/veewee
  #
  config.vm.box_url = "http://files.vagrantup.com/lucid32.box"
  
  #
  # Set the VM's private IP address.
  #
  config.vm.network "172.21.21.21"

  #
  # Create /srv if it doesn't exist and share with VM.
  # The /srv path is owned by www-data so apache can write to it.
  #
  srv_path = File.expand_path(File.dirname(__FILE__)) + "/srv"
  if !File::directory?(srv_path) then Dir::mkdir(srv_path) end
  config.vm.share_folder("srv", "/srv", srv_path, :owner => "www-data", :group => "www-data")

  #
  # Provision a new VM using chef-solo. The librarian gem controls
  # the "cookbook" folder, do not touch it.  If you need to create
  # site-specific cookbooks, place them in "site-cookbooks".
  #
  config.vm.provision :chef_solo do |chef|
    #chef.log_level = :debug
    chef.cookbooks_path = ["cookbooks", "site-cookbooks"]
    chef.add_recipe "xforty"
    chef.add_recipe "drupal"
    chef.add_recipe "initdb"
  
    # Specify custom JSON node attributes:
    chef.json.merge!(
      :drupal => {
        :project_name => "drupal"
      },
      :drush => {
        :version => "5.0.0"
      },
      :mysql => {
        :server_root_password => "root"
      },
      :initdb => {
        :mysql => {
          :connection => {
            :username => "root",
            :password => "root",
            :host     => "localhost"
          },
          :databases => {
            "drupal" => {
              :action => :create
            }
          },
          :users => {
            "db_user" => {
              :action        => :grant,
              :database_name => "drupal",
              :host          => "localhost",
              :password      => "password"
            }
          }
        }
      }
    )
  end
end
