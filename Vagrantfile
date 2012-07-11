# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant::Config.run do |config|

  #################################
  # Base box and vm configuration #
  #################################

  # Set the vm's host name (displays in shell prompt)
  # (Hint: Consider setting this to the name of your
  # project. The hostname "ubuntu.local" is automatically
  # available.)
  config.vm.host_name = "drupal"

  # Name of base box to be used
  config.vm.box = "ubuntu-10.04.4-server-amd64"

  # Url of base box in case vagrant needs to download it
  config.vm.box_url = "http://dl.dropbox.com/u/56687100/ubuntu-10.04.4-server-amd64.box"

  # Set the memory size
  config.vm.customize ["modifyvm", :id, "--memory", "1024"]

  # VirtualBox performance improvements
  config.vm.customize ["modifyvm", :id, "--nictype1", "virtio"]
  config.vm.customize ["modifyvm", :id, "--nictype2", "virtio"]
  config.vm.customize ["storagectl", :id, "--name", "SATA Controller", "--hostiocache", "off"]

  #################################
  # Networking                    #
  #################################

  # Use port-forwarding. Un-comment this line to use.
  # Web site will be at http://localhost:4567
  #
  # config.vm.forward_port(80, 4567, :auto => true)

  # Use host-only networking. The site is automatically 
  # available at "config.vm.host_name".local.
  # (ie. ubuntu-10.local)
  config.vm.network :hostonly, :dhcp, :ip => "172.21.21.1"

  # Use a host-only static IP address. Required for NFS.
  #
  # config.vm.network :hostonly, "172.21.21.21"

  #################################
  # Shared Folders                #
  #################################

  # Path to our shared folder for project files.
  srv_path = File.expand_path(File.dirname(__FILE__)) + "/srv"

  # Use vboxfs for shared folder.
  config.vm.share_folder("srv", "/srv", srv_path, :owner => "vagrant", :group => "www-data", :create => true)

  # Use nfs for shared folder. Just un-comment this line and turn on static
  # host-only networking. vboxfs is known to have performance issues
  # on non-windows hosts. http://vagrantup.com/docs/nfs.html
  #
  # config.vm.share_folder("srv", "/srv", srv_path, :nfs => true, :create => true);

  #################################
  # Librarian                     #
  #################################

  # Only run if "up" was called
  if ARGV.first == "up"

    # Path to our cookbooks folder
    cookbooks_path = File.expand_path(File.dirname(__FILE__)) + "/cookbooks"

    # Run librarian if cookbooks folder does not exist or is empty
    if !Dir::exists?(cookbooks_path) || (Dir.entries(cookbooks_path).size < 3)
      puts 'Running "librarian-chef install"...'
      puts `librarian-chef install`
    end
  end

  #################################
  # Provisioners                  #
  #################################

  # Provision a new vm using chef-solo
  config.vm.provision :chef_solo do |chef|

    # To turn on chef debug output, run "vdb=1 vagrant up" from command line
    chef.log_level = :debug if ENV['vdb']

    # The librarian gem controls the "cookbook" folder, do not touch it. If you
    # need to create site-specific cookbooks, place them in "site-cookbooks".
    chef.cookbooks_path = ["cookbooks", "site-cookbooks"]

    # Default top-level chef recipes
    chef.add_recipe "squid"
    chef.add_recipe "xforty"
    chef.add_recipe "drupal"
    chef.add_recipe "initdb"

    # Specify custom JSON node attributes
    chef.json.merge!(
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
            "username" => {
              :action        => :grant,
              :database_name => "drupal",
              :host          => "localhost",
              :password      => "password"
            }
          }
        }
      },
      'apache' => {
        'prefork' => {
          'startservers'        => 4,
          'minspareservers'     => 4,
          'maxspareservers'     => 4,
          'serverlimit'         => 4,
          'maxclients'          => 4,
          'maxrequestsperchild' => 1000
        }
      }
    )
  end

  # Run any necessary shell commands on the vm
  config.vm.provision :shell, :path => "bin/postvagrant.sh"

end
