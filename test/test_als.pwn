#pragma compat 0
#include <a_samp>

#define CX_DEBUG_MODE // debug in compiler ( warning 217 )
#include <CX_Script/cx_als>

main(){}

@als() register(.callback=OnGameModeInit,.function="gamemodeIn",.params={},.arg={""})
/* define
public OnGameModeInit()
{
	@als() do("gamemodeIn", "")
	return 1;
}
*/
#include <CX_Script/cx_als>
@als() function gamemodeIn() // hook ongamemodeIn
{
	print("First hook");
	return 1; // als() continue;
}

#include <CX_Script/cx_als>
@als() function gamemodeIn() // hook ongamemodeIn
{
	print("End hook");
	return 0; // als() break;
}