#include a_samp
#define CX_DEBUG_MODE
#include <CX_Extra\cx_izcmd>

new Var[MAX_PLAYERS];

// Code 1
@flag(.variable = (Var[playerid] == 1)) AnjayMabar(playerid);
@cmd(.type = FLAGGED_COMMAND, .flag = AnjayMabar) help(playerid, params[])
{
	SendClientMessage(playerid, -1, "success");
	return 1;
}

@cmd(.type = SLASH_COMMAND) set(playerid, params[])
{
	SendClientMessage(playerid, -1, "Snja");
	Var[playerid] = 1;
	return 1;
}

// Code 2
CreateRoleCmd:AnjayMabar(playerid, Var[playerid] == 1)
RoleCommand:help(Role:AnjayMabar, playerid, params[])
{
	SendClientMessage(playerid, -1, "success");
	return 1;
}