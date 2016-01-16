<?php
echo ini_get('opcache.enable') . "\n";
echo ini_get('opcache.save_comments') . "\n";
var_dump(opcache_get_status());
