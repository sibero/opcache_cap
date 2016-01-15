##Fake opcache for drupal 8

Tested on centos 6 and php 5.6

  Install.
  Copy opcache_cap.so /usr/lib64/php/modules/
  add to /etc/php.d/opcache_cap.ini
  extension=opcache_cap.so
