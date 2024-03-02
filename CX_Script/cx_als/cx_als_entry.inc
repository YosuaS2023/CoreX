#define _cx_als_entry

public OnCorexInit()
{
    #if defined CX_DEBUG_MODE
    CoreXLog("[CoreX]: (als) Successfully loaded als");
    #endif
    LoadCoreXScript(COREX_ALS);
    @als() do("OnCorexInit", "");
    if(funcidx("cx_als_OnCorexInit") != -1)
    {
        CallLocalFunction("cx_als_OnCorexInit", "");
    }
}

#if defined _ALS_OnCorexInit
    #undef OnCorexInit
#else
    #define _ALS_OnCorexInit
#endif

#define OnCorexInit cx_als_OnCorexInit

forward cx_als_OnCorexInit();

public OnCorexExit()
{
    #if defined CX_DEBUG_MODE
    CoreXLog("[CoreX] (als) Successfully unloaded als");
    #endif
    UnloadCoreXScript(COREX_ALS);
    @als() do("OnCorexExit", "");
    if(funcidx("cx_als_OnCorexExit") != -1)
    {
        CallLocalFunction("cx_als_OnCorexExit", "");
    }
}

#if defined _ALS_OnCorexExit
    #undef OnCorexExit
#else
    #define _ALS_OnCorexExit
#endif

#define OnCorexExit cx_als_OnCorexExit

forward cx_als_OnCorexExit();