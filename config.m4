dnl $Id$
dnl config.m4 for extension opcache_cap

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(opcache_cap, for opcache_cap support,
dnl Make sure that the comment is aligned:
dnl [  --with-opcache_cap             Include opcache_cap support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(opcache_cap, whether to enable opcache_cap support,
[  --enable-opcache_cap           Enable opcache_cap support])

if test "$PHP_OPCACHE_CAP" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-opcache_cap -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/opcache_cap.h"  # you most likely want to change this
  dnl if test -r $PHP_OPCACHE_CAP/$SEARCH_FOR; then # path given as parameter
  dnl   OPCACHE_CAP_DIR=$PHP_OPCACHE_CAP
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for opcache_cap files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       OPCACHE_CAP_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$OPCACHE_CAP_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the opcache_cap distribution])
  dnl fi

  dnl # --with-opcache_cap -> add include path
  dnl PHP_ADD_INCLUDE($OPCACHE_CAP_DIR/include)

  dnl # --with-opcache_cap -> check for lib and symbol presence
  dnl LIBNAME=opcache_cap # you may want to change this
  dnl LIBSYMBOL=opcache_cap # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $OPCACHE_CAP_DIR/$PHP_LIBDIR, OPCACHE_CAP_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_OPCACHE_CAPLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong opcache_cap lib version or lib not found])
  dnl ],[
  dnl   -L$OPCACHE_CAP_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(OPCACHE_CAP_SHARED_LIBADD)

  PHP_NEW_EXTENSION(opcache_cap, opcache_cap.c, $ext_shared)
fi
