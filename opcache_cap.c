/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_opcache_cap.h"

/* If you declare any globals in php_opcache_cap.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(opcache_cap)
*/

/* True global resources - no need for thread safety here */
static int le_opcache_cap;

PHP_INI_BEGIN()
    PHP_INI_ENTRY("opcache.enable", "1", PHP_INI_ALL, NULL)
    PHP_INI_ENTRY("opcache.save_comments", "1", PHP_INI_ALL, NULL)
    PHP_INI_ENTRY("opcache.messages", "Server use xcache", PHP_INI_ALL, NULL)
PHP_INI_END()

PHP_FUNCTION(opcache_get_status)
{
    array_init(return_value);
    add_assoc_bool(return_value, "opcache_enabled", 1);
}

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(opcache_cap)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(opcache_cap)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(opcache_cap)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(opcache_cap)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(opcache_cap)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "opcache_cap support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ opcache_cap_functions[]
 *
 * Every user visible function must have an entry in opcache_cap_functions[].
 */
const zend_function_entry opcache_cap_functions[] = {
	PHP_FE(opcache_get_status,     NULL)
        PHP_FE_END	/* Must be the last line in opcache_cap_functions[] */
};
/* }}} */

/* {{{ opcache_cap_module_entry
 */
zend_module_entry opcache_cap_module_entry = {
	STANDARD_MODULE_HEADER,
	"opcache_cap",
	opcache_cap_functions,
	PHP_MINIT(opcache_cap),
	PHP_MSHUTDOWN(opcache_cap),
	PHP_RINIT(opcache_cap),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(opcache_cap),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(opcache_cap),
	PHP_OPCACHE_CAP_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_OPCACHE_CAP
ZEND_GET_MODULE(opcache_cap)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
