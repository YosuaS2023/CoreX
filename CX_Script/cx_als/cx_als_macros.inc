#define _cx_als_macros

#define @CX_ALS@%0\32; @CX_ALS@
#define @als%0(%1) @CX_ALS@
 
#if defined CX_COMPATIBILITY_MODE
	#define hook%1(%2) forward FUNCTION_GENERATOR<%1...%2>; FUNCTION_GENERATOR<%1...%2>
#endif

#define @CX_ALS_SPACE@

#define @CX_ALS@break (0)
#define @CX_ALS@continue (1)

#define @CX_ALS@function%1(%2) forward FUNCTION_GENERATOR<%1...%2>; FUNCTION_GENERATOR<%1...%2>

#define @CX_ALS@do%1(%0,%2)%4; @CX_ALS_SPACE@ @a_cxals$ @CX_ALS_SPACE@ @b_cxals$%0$ @CX_ALS_SPACE@ @c_cxals$%2$ @CX_ALS_SPACE@ @d_cxals$..%4$

#define NULL
#define @CX_ALS@register%1(.callback=%0,.function=%4,.params={%2},.arg={%3}) public %0(%2) {new funcname[32];for(new hookindex;hookindex<1000;hookindex++){format(funcname,32,"@%i@%s",hookindex,%4);if(funcidx(funcname)!= -1){if(CallLocalFunction(funcname,%3)==0)break;}}return 1;}