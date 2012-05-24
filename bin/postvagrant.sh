#!/bin/bash

# Turn off StrictHostKeyChecking for vagrant user.
# See http://drupal.org/node/1567528 and
# https://github.com/xforty/vagrant-drupal/issues/29
touch /home/vagrant/.ssh/config
grep -q 'StrictHostKeyChecking' /home/vagrant/.ssh/config || echo 'StrictHostKeyChecking no' >> /home/vagrant/.ssh/config

# Make sure all files under .ssh are owned by vagrant
chown -R vagrant:vagrant /home/vagrant/.ssh
