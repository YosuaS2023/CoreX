#include <CX_Core\cx_entry>
#include <CX_Core\cx_functiongen>

#if defined _CX_als_inc

    #endinput

#endif

#define _CX_als_inc

#tryinclude <CX_Core\cx_compile.inc>
#tryinclude <CoreX\cx_compile.inc>
#if !defined INC_cx_compile
	#error [CoreX]: CX_Core\cx_compile is not installed
#endif

#tryinclude <CX_Script\cx_als\cx_als_macros>
#if !defined _cx_als_macros
	#warning [CoreX]: CX_Script\cx_als_macros not available in the include list
#endif

#tryinclude <CX_Script\cx_als\cx_als_impl>
#if !defined _cx_als_impl
	#warning [CoreX]: CX_Script\cx_als_impl not available in the include list
#endif

#tryinclude <CX_Script\cx_als\cx_als_entry>
#if !defined _cx_als_entry
	#warning [CoreX]: CX_Script\cx_als_entry not available in the include list
#endif