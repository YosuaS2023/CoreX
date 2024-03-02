/*
 a88888b.                            dP    dP
d8'   `88                            Y8.  .8P
88        .d8888b. 88d888b. .d8888b.  Y8aa8P 
88        88'  `88 88'  `88 88ooood8 d8'  `8b
Y8.   .88 88.  .88 88       88.  ... 88    88
 Y88888P' `88888P' dP       `88888P' dP    dP
*/

#if defined cx_init_included
    #endinput
#endif

#define cx_init_included

#if defined CX_DEV_MODE

#tryinclude <a_samp>

#if !defined _samp_included
    #error [CoreX]: (error) - You need to have a_samp.inc file in your includes folder.
#endif

#endif

// define CX_STATIC_MODE

#define __CX_STATIC stock

#if defined CX_STATIC_MODE

    #undef __CX_STATIC
    #define __CX_STATIC static

#endif

//public const detutils_ver = 0x1;

stock CoreXLog(logText[])
{
    new
		sz_logEntry[256],
		File: logfile,
		logFile[300],
		i_dateTime[2][3];

	gettime(i_dateTime[0][0], i_dateTime[0][1], i_dateTime[0][2]);
	getdate(i_dateTime[1][0], i_dateTime[1][1], i_dateTime[1][2]);
	
	logFile = "corex.txt";
	format(sz_logEntry, sizeof(sz_logEntry), "[%i/%i/%i - %i:%02i:%02i] %s\r\n", i_dateTime[1][2], i_dateTime[1][1], i_dateTime[1][0], i_dateTime[0][0], i_dateTime[0][1], i_dateTime[0][2], logText);
	if(logfile) fclose(logfile);
	if(!fexist(logFile)) logfile = fopen(logFile, io_write);
	else logfile = fopen(logFile, io_append);
	if(logfile)
	{
		new tick = GetTickCount();
		fwrite(logfile, sz_logEntry);
		fclose(logfile);
		printf("(%i ms) %s", (GetTickCount() - tick), logText);
	}
}

#define COREX_COMMANDS 0
#define COREX_ALS 1
#define COREX_FOREACH 2
#define COREX_TIMERS 3
#define COREX_AMX 4

stock LoadCoreXScript(scriptid)
{
    if(scriptid == COREX_COMMANDS)
    {
        print("*** [CoreX]: (module) - Loaded: cx_izcmd.inc");
        CoreXLog("[CoreX]: (module) - Loaded: cx_izcmd.inc");
    }
    if(scriptid == COREX_ALS)
    {
        print("*** [CoreX]: (module) - Loaded: cx_als.inc");
        CoreXLog("[CoreX]: (module) - Loaded: cx_als.inc");
    }
    if(scriptid == COREX_FOREACH)
    {
        print("*** [CoreX]: (module) - Loaded: cx_foreach.inc");
        CoreXLog("[CoreX]: (module) - Loaded: cx_foreach.inc");
    }
    if(scriptid == COREX_TIMERS)
    {
        print("*** [CoreX]: (module) - Loaded: cx_timers.inc");
        CoreXLog("[CoreX]: (module) - Loaded: cx_timers.inc");
    }
    if(scriptid == COREX_AMX)
    {
        print("*** [CoreX]: (module) - Loaded: cx_amx.inc");
        CoreXLog("[CoreX]: (module) - Loaded: cx_amx.inc");
    }
}

stock UnloadCoreXScript(scriptid)
{
    if(scriptid == COREX_COMMANDS)
    {
        print("*** [CoreX]: (module) - Unloaded: cx_izcmd.inc");
        CoreXLog("[CoreX]: (module) - Unloaded: cx_izcmd.inc");
    }
    if(scriptid == COREX_ALS)
    {
        print("*** [CoreX]: (module) - Unloaded: cx_als.inc");
        CoreXLog("[CoreX]: (module) - Unloaded: cx_als.inc");
    }
    if(scriptid == COREX_FOREACH)
    {
        print("*** [CoreX]: (module) - Unloaded: cx_foreach.inc");
        CoreXLog("[CoreX]: (module) - Unloaded: cx_foreach.inc");
    }
    if(scriptid == COREX_TIMERS)
    {
        print("*** [CoreX]: (module) - Unloaded: cx_timers.inc");
        CoreXLog("[CoreX]: (module) - Unloaded: cx_timers.inc");
    }
    if(scriptid == COREX_AMX)
    {
        print("*** [CoreX]: (module) - Unloaded: cx_amx.inc");
        CoreXLog("[CoreX]: (module) - Unloaded: cx_amx.inc");
    }
}

#define @CX_TAGS: {Float,_,bool}:

forward LoadCoreX();
public LoadCoreX()
{
    new CX_g_Version[26];
    format(CX_g_Version, sizeof(CX_g_Version), "%i.%i.%i-R%i", 
        CX_VERSION_MAJOR, 
        CX_VERSION_MINOR, 
        CX_VERSION_PATCH,
        CX_VERSION_RELEASE);
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                CoreX                ");
    print("        System is now loading...        ");
    print("                                        ");
    printf("          Version: %s              ", CX_g_Version);
    print("                                        ");
    print("               By: Oxy              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    #if defined CX_DEBUG_MODE
    print(">> SYSTEM | CoreX - Debug mode is: <ON>");
    #endif
    #if defined CX_FILTERSCRIPT_MODE
    print(">> SYSTEM | CoreX - Filterscript mode is: <ON>");
    #endif
    #if defined CX_TESTING_MODE
    print(">> SYSTEM | Corex - Testing mode is: <ON>");
    #endif
    #if defined CX_STATIC_MODE
    print(">> SYSTEM | CoreX - Static mode is: <ON>");
    #endif
    #if defined CX_COMPATIBILITY_MODE
    print(">> SYSTEM | CoreX - Compatibility mode is: <ON>");
    #endif
    print("                                        ");
    #if defined CoreXBeta
    print("*** [DETUtils]: (beta) - Note that this version is a beta release, which means that this release doesn't represent the final quality of the version.");
    #endif
    print("                                        ");
    print("                                        ");
    #if defined CX_DEV_MODE
    print(">> SYSTEM | CoreX - System is loaded in developer mode.");
    #endif
    print("                                        ");
    print("                                        ");
    return 1;
}

forward UnloadCoreX();
public UnloadCoreX()
{
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                CoreX                ");
    print("          System is unloading...        ");
    print("                                        ");
    print("               By: Oxy              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    #if defined CX_DEBUG_MODE
    print(">> SYSTEM | CoreX - Debug mode is: <ON>");
    #endif
    #if defined CX_FILTERSCRIPT_MODE
    print(">> SYSTEM | CoreX - Filterscript mode is: <ON>");
    #endif
    #if defined CX_TESTING_MODE
    print(">> SYSTEM | Corex - Testing mode is: <ON>");
    #endif
    #if defined CX_STATIC_MODE
    print(">> SYSTEM | CoreX - Static mode is: <ON>");
    #endif
    #if defined CX_COMPATIBILITY_MODE
    print(">> SYSTEM | CoreX - Compatibility mode is: <ON>");
    #endif
    print("                                        ");
    #if __CoreXBeta == 1
    print("*** [DETUtils]: (beta) - Note that this version is a beta release, which means that this release doesn't represent the final quality of the version.");
    #endif
    print("                                        ");
    print("                                        ");
    #if defined CX_DEV_MODE
    print(">> SYSTEM | CoreX - System is unloaded in developer mode.");
    #endif
    print("                                        ");
    print("                                        ");
    #if __CoreX != 0x103
    printf("[CoreX] (version) The CoreX include version does not match");
    SendRconCommand("exit");
    #endif
    return 1;
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    if(funcidx("a_init_OnGameModeInit") != -1)
    {
        CallLocalFunction("a_init_OnGameModeInit","");
    }
   CallLocalFunction("OnCorexInit", "");
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_init_OnGameModeInit

forward a_init_OnGameModeInit();

//

public OnGameModeExit()
{
    if(funcidx("a_init_OnGameModeExit") != -1)
    {
        CallLocalFunction("a_init_OnGameModeExit","");
    }
    CallLocalFunction("OnCorexExit", "");
    return 1;
}

#if defined _ALS_OnGameModeExit
    #undef OnGameModeExit
#else
    #define _ALS_OnGameModeExit
#endif

#define OnGameModeExit a_init_OnGameModeExit

forward a_init_OnGameModeExit();

#else

public OnFilterScriptInit()
{
    if(funcidx("a_init_OnFilterScriptInit") != -1)
    {
        CallLocalFunction("a_init_OnFilterScriptInit", "");
    }
    CallLocalFunction("OnCorexInit", "");
    return 1;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_init_OnFilterScriptInit

forward a_init_OnFilterScriptInit();

//

public OnFilterScriptExit()
{
    if(funcidx("a_init_OnFilterScriptExit") != -1)
    {
        CallLocalFunction("a_init_OnFilterScriptExit","");
    }
    CallLocalFunction("OnCorexExit", "");
    return 1;
}

#if defined _ALS_OnFilterScriptExit
    #undef OnFilterScriptExit
#else
    #define _ALS_OnFilterScriptExit
#endif

#define OnFilterScriptExit a_init_OnFilterScriptExit

forward a_init_OnFilterScriptExit();

#endif

// Internal callbacks!

forward OnCorexInit();
public OnCorexInit()
{
    #if defined CX_DEBUG_MODE 
    	#if defined CX_SERVERNAME_TEST
	    SendRconCommand("hostname [CoreX]: (test) - "CX_SERVERNAME_TEST);
	    SetGameModeText("SA:MP | CORE-X");
		#elseif !defined CX_SERVERNAME_TEST
		SendRconCommand("hostname [CoreX]: (test) - CoreX");
	    SetGameModeText("SA:MP | CORE-X");
		#endif
		#if defined CX_DEV_MODE
		SendRconCommand("password "CX_DEV_MODE);
		printf("*** [CoreX] (dev-mode) The server is currently in developer mode");
		printf("*** [CoreX] (dev-mode) password : "CX_DEV_MODE);
		#elseif !defined CX_DEV_MODE
		SendRconCommand("passsord ");
		#endif
    #endif
    LoadCoreX();
    @cxmemory SysInit, 1
    if(funcidx("a_init_OnCorexInit") != -1)
    {
        CallLocalFunction("a_init_OnCorexInit", "");
    }
    return 1;
}

#if defined _ALS_OnCorexInit
    #undef OnCorexInit
#else
    #define _ALS_OnCorexInit
#endif

#define OnCorexInit a_init_OnCorexInit

forward a_init_OnCorexInit();

forward OnCorexExit();
public OnCorexExit()
{
    UnloadCoreX();
    if(funcidx("a_init_OnCorexExit") != -1)
    {
        CallLocalFunction("a_init_OnCorexExit", "");
    }
    return 1;
}

#if defined _ALS_OnCorexExit
    #undef OnCorexExit
#else
    #define _ALS_OnCorexExit
#endif

#define OnCorexExit a_init_OnCorexExit

forward a_init_OnCorexExit();