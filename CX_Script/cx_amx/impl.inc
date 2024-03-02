#define _cx_amx_impl
#include <CX_Script\cx_als>
#define amx_space  
#define @a_amx$%1$ new hdr%1[AMX_HDR];new returnFunc_%1[30];
#define @b_amx$%5$ GetAmxHeader(hdr%5);
#define @c_amx$%5$ new totalPublics%5 = GetNumPublics(hdr%5);
#define @d_amx$%5$ for (new i%5 = 0; i%5 < totalPublics%5; i%5++)
#define @e_amx$%5$ {GetPublicNameFromIndex(i%5, returnFunc_%5);if(strfind(returnFunc_%5, #%5) != 0) {continue;}

@als() function OnCorexInit()
{
	#if defined CX_DEBUG_MODE
	LoadCoreXScript(COREX_AMX);
	#endif
	printf("*** [CoreX] (amx) - Successfully loaded cx_amx.inc");
	return 1;
}

@als() function OnCorexExit()
{
	#if defined CX_DEBUG_MODE
	UnloadCoreXScript(COREX_AMX);
	#endif
	printf("*** [CoreX] (amx) - Successfully unloaded cx_amx.inc");
	return 1;
}