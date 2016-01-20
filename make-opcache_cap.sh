#!/bin/bash
# coded by sibero.
export PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin

echo 'phpize exec'
phpize
echo
echo 'configure --enable-opcache_cap  exec'
./configure --enable-opcache_cap
echo
echo 'make exec'
make
