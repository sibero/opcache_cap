##Fake opcache for drupal 8

Tested on centos 6 and php 5.6

Install. <br>
Copy opcache_cap.so /usr/lib64/php/modules/ <br>
add to /etc/php.d/opcache_cap.ini <br>
extension=opcache_cap.so

Configure <br>
phpize <br>
./configure --enable-opcache-cap <br>
make <br>
make install <br>

