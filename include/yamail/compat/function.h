#ifndef _YAMAIL_COMPAT_FUNCTION_H_
#define _YAMAIL_COMPAT_FUNCTION_H_
#include <yamail/config.h>
#include <yamail/compat/config.h>
#include <yamail/compat/namespace.h>
/*
 * function.h
 *
 *  [std|boost]::function compatibility wrapper header
 */

#if defined(HAVE_STD_FUNCTION) && HAVE_STD_FUNCTION
# include <functional>
#else
# include <boost/function.hpp>
#endif // __HAVE_STD_FUNCTION

YAMAIL_FQNS_COMPAT_BEGIN

#if defined(HAVE_STD_FUNCTION) && HAVE_STD_FUNCTION
using std::function;
#else
using boost::function;
#endif // __HAVE_STD_FUNCTION

YAMAIL_FQNS_COMPAT_END

#endif /* _YAMAIL_COMPAT_FUNCTION_H_ */
