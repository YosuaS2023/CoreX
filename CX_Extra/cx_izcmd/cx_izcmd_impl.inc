
public OnPlayerCommandText(playerid, cmdtext[])
{
	#if defined OnPlayerCommandReceived
	    if(!OnPlayerCommandReceived(playerid, cmdtext)) return 1;
	#endif
	static funcname[MAX_CLIENT_MSG_LENGTH] = "cmd_";

	#if defined IZCMD_ENABLE_CASE_SENSITIVITY
		static pos;

		if((pos = strfind(cmdtext, " ", false, 1)) == -1)
		{
      		funcname[4] = 0;
			strcat(funcname, cmdtext[1], MAX_FUNC_NAME - 4);

		   	#if defined OnPlayerCommandPerformed
		 		return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, "\1"));
			#else
				return CallLocalFunction(funcname, "is", playerid, "\1");
			#endif
		}
		else
		{
			funcname[4] = 0;
			strcat(funcname, cmdtext[1], pos + 4);

	    	while (cmdtext[pos] == ' ') pos++;

			if(cmdtext[pos])
			{
		  		#if defined OnPlayerCommandPerformed
					return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, cmdtext[pos]));
				#else
					return CallLocalFunction(funcname, "is", playerid, cmdtext[pos]);
				#endif
			}
			else
			{
			   	#if defined OnPlayerCommandPerformed
					return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, "\1"));
				#else
					return CallLocalFunction(funcname, "is", playerid, "\1");
				#endif
			}
		}
	#else
		new pos = 1, tmp;

		while((tmp = cmdtext[pos]) > ' ')
			if('A' <= tmp <= 'Z') funcname[pos++ + 3] = tmp | 0x20;
			else funcname[pos++ + 3] = tmp;

		funcname[pos + 3] = 0;

		while (cmdtext[pos] == ' ') pos++;
	
		if(cmdtext[pos])
		{
	  		#if defined OnPlayerCommandPerformed
				return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, cmdtext[pos]));
			#else
				return CallLocalFunction(funcname, "is", playerid, cmdtext[pos]);
			#endif
		}
		else
		{
		   	#if defined OnPlayerCommandPerformed
				return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, "\1"));
			#else
				return CallLocalFunction(funcname, "is", playerid, "\1");
			#endif
		}
	#endif
}

@als() function OnCorexInit()
{
	#if defined CX_DEBUG_MODE
	CoreXLog("[CoreX]: (izcmd) Successfully loaded command.");
	#endif
	LoadCoreXScript(COREX_COMMANDS);
	return 1;
}

@als() function OnCorexExit()
{
	#if defined CX_DEBUG_MODE
	CoreXLog("[CoreX]: (izcmd) Successfully unloaded command.");
	#endif
	UnloadCoreXScript(COREX_COMMANDS);
	return 1;
}

#if defined OnPlayerCommandReceived
	forward OnPlayerCommandReceived(playerid,cmdtext[]);
#endif
#if defined OnPlayerCommandPerformed
	forward OnPlayerCommandPerformed(playerid,cmdtext[], success);
#endif