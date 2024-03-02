/*
 * 
 * CoreX
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *   
 *
 *
 */

#define __line,) __line)

#define __COREX_DEBUG_STRSIZE 1024

new
    __CoreXDebug_[__COREX_DEBUG_STRSIZE],
    __CoreXError_[__COREX_DEBUG_STRSIZE],
    __CoreXWarning_[__COREX_DEBUG_STRSIZE],
    __CoreXInfo_[__COREX_DEBUG_STRSIZE];

#if defined CX_DEBUG_MODE

    #if defined __CoreXDebug
        #undef __CoreXDebug
    #endif

    #define __CoreXDebug%0(%1,%2) \
    format(__CoreXDebug_,__COREX_DEBUG_STRSIZE,"[CoreX]: (debug: %s:%i) - "%1,%2)&& \
    print(__CoreXDebug_)&&CoreXLog(__CoreXDebug_)

#elseif !defined CX_DEBUG_MODE

    #define __CoreXDebug%0(%1)%2;

#endif

#if defined __CoreXWarning
    #undef __CoreXWarning
#endif

#define __CoreXWarning%0(%1,%2) \
    format(__CoreXWarning_,__COREX_DEBUG_STRSIZE,"*** [CoreX]: (warning: %s:%i) - "%1,%2)&& \
    print(__CoreXWarning_)&&CoreXLog(__CoreXWarning_)


#if defined __CoreXError
    #undef __CoreXError
#endif

#define __CoreXError%0(%1,%2) \
    format(__CoreXError_,__COREX_DEBUG_STRSIZE,"*!* [CoreX]: (error: %s:%i) - "%1,%2)&& \
    print(__CoreXError_)&&CoreXLog(__CoreXError_)

#if defined __CoreXInfo
    #undef __CoreXInfo
#endif

#define __CoreXInfo%0(%1,%2) \
    format(__CoreXInfo_,__COREX_DEBUG_STRSIZE,"** [CoreX]: (info: "%1,%2)&& \
    print(__CoreXInfo_)&&CoreXLog(__CoreXInfo_)