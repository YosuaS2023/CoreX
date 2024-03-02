#if defined CX_AMX_INC
#endinput
#endif

#tryinclude <CX_Core\cx_entry>
#if !defined CX_USE_AMX
#define CX_USE_AMX
#endif
#tryinclude <CX_Core\cx_thirdpartyinclude>

#if !defined INC_cx_compile
	#error [CoreX]: CX_Core\cx_compile is not installed
#endif

#if !defined INC_cx_thirdpartyinclude
	#error [CoreX]: CX_Core\cx_thirdpartyinclude is not installed
#endif

#tryinclude <CX_Script\cx_amx\macros.inc>

#if !defined _cx_amx_macros
	#error [CoreX]: CX_Script\cx_amx\macros.inc not available in include
#endif

#tryinclude <CX_Script\cx_amx\impl.inc>
#if !defined _cx_amx_impl
	#error [CoreX]: CX_Script\cx_amx\impl.inc not available in include
#endif