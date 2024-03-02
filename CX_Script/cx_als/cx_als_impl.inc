#define _cx_als_impl
#define @a_cxals$ new funcname[32];for(new hookindex;hookindex<1000;hookindex++){

#if defined CX_DEBUG_MODE

    #define @b_cxals$%0$ format(funcname,32,"@%i@%s",hookindex,%0); \
    __CoreXInfo("Attempted to call: %s", funcname); \
    if(funcidx(funcname)!= -1){if(CallLocalFunction(funcname,%0)==0) break;}

#endif

#if !defined CX_DEBUG_MODE

    #define @b_cxals$%0$ format(funcname,32,"@%i@%s",hookindex,%0); if(funcidx(funcname)!= -1){if(CallLocalFunction(funcname,%0)==0)break;}

#endif

#define @c_cxals$%0$
#define @d_cxals$..%0$ %0}%0