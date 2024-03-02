#if defined INC_cx_thirdpartyinclude
	#undef INC_cx_thirdpartyinclude
#endif

#define INC_cx_thirdpartyinclude

#if defined CX_USE_AMX
	#tryinclude <amx_assembly\amx_header>
	#tryinclude <amx\amx_header>
	
	#if !defined AMX_HEADER_INC
		#define AMX_INCLUDING_FAILED
	#endif
	#if defined AMX_INCLUDING_FAILED
		#error Could not include "https://github.com/Zeex/amx_assembly" - ensure its files are in "includes\amx_assembly\ or includes\amx"
	#endif
#endif