
#define MAX_CLIENT_MSG_LENGTH (144)
#define MAX_FUNC_NAME (32)

#define CMD_SUCCESS 1
#define CMD_FAILURE 0

#define cmd_%0\32; cmd_
#define cmd_func_%0\32; cmd_func_
#define role_%0\32; role_

#define @CX_CMD@%0\32; @CX_CMD@

#define @cmd(%0.type%1= @CX_CMD@

#define @CX_CMD@SLASH_COMMAND%3)%0(%1) forward cmd_%0(%1); public cmd_%0(%1)
#define @CX_CMD@FLAGGED_COMMAND%4,%5.flag%6=%3)%0(%1,%2[%7]%8) RoleCommand:%0(%4Role:%3,%1,%2[%7]%8)

#define @flag(%0.variable%4=%5(%3)%6)%1(%2); \
    CreateRoleCmd:%1(%2, %3)

// syntax : RoleCommand:NameCmd(Role:RoleFunction, playerid, params[])
#define RoleCommand:%0(%7Role:%6,%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3 public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])
  
// syntax : CreateRoleCmd:NameFunc(playerid, VariableRole[playerid] == 3)
#define CreateRoleCmd:%1(%2,%3) \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }
    
#if defined CX_COMPATIBILITY_MODE
	#define CMD:%0(%1) forward cmd_%0(%1); public cmd_%0(%1)
	#define COMMAND:%0(%1) forward cmd_%0(%1); public cmd_%0(%1)
	#define YCMD:%0(%1) forward cmd_%0(%1); public cmd_%0(%1)
#endif

#if !defined isnull
        #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif