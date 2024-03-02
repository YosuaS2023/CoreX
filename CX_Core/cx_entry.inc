#if defined cx_core_included

    #endinput

#endif

#if defined CX_DEV_MODE
    
    #if !defined CX_TESTING_MODE
    
        #define CX_TESTING_MODE

    #endif

    #if !defined CX_DEBUG_MODE
    
        #define CX_DEBUG_MODE

    #endif

#endif
#define cx_core_included

#if defined CX_DEV_MODE

    #warning [CoreX]: (system) - dev :: Developer mode has been enabled.

#endif

#if defined CX_COMPATIBILITY_MODE
    
    #warning [CoreX]: (system) - compat :: Compatibility mode has been enabled.

#endif

// Include the these first
// becase they contain important
// information and functions
// used by the rest of the core
// itself.
#include "cx_compile"
#include "cx_version"
#include "cx_memory"

// And now the rest of the core.
#include "cx_init"


// Debugging is really important.
#include "cx_debug"

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

public OnCorexInit()
{
    if(funcidx("cx_core_oncorexinit") != -1)
    {
        CallLocalFunction("cx_core_oncorexinit", "");
    }
    return 1;
}

#if defined _ALS_OnCorexInit
    #undef OnCorexInit
#else
    #define _ALS_OnCorexInit
#endif

#define OnCorexInit( cx_core_oncorexinit(

forward cx_core_oncorexinit();

// cleanup

public OnCorexExit()
{
    if(funcidx("d_core_OnCorexExit") != -1)
    {
        CallLocalFunction("cx_core_OnCorexExit", "");
    }
    return 1;
}

#if defined _ALS_OnCorexExit
    #undef OnCorexExit
#else
    #define _ALS_OnCorexExit
#endif

#define OnCorexExit( cx_core_OnCorexExit(

forward cx_core_OnCorexExit();