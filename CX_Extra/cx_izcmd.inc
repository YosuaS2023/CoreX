/*******************************************************************************************************************************
 a88888b.                            dP    dP
d8'   `88                            Y8.  .8P
88        .d8888b. 88d888b. .d8888b.  Y8aa8P 
88        88'  `88 88'  `88 88ooood8 d8'  `8b
Y8.   .88 88.  .88 88       88.  ... 88    88
 Y88888P' `88888P' dP       `88888P' dP    dP
 
	 Credit:
		 - Zeex : for zcmd
		 - Yashas : for izcmd ( Improved ZCMD )
		 - Oxy : for cx_izcmd
*******************************************************************************************************************************/
#if defined _I_ZCMD_INCLUDED
	#error [CoreX]: cx_izcmd.inc is not compatible with izcmd.inc
#endif

#if defined _zcmd_included
	#error [CoreX]: cx_izcmd.inc is not compatible with zcmd.inc
#endif

#if defined PAWNCMD_INC_
	#error [CoreX]: cx_izcmd.inc is not compatible with pawncmd.inc
#endif

#if defined _cx_izcmd_inc
	#endinput
#endif
#define _cx_izcmd_inc

#include <CX_Script\cx_als>
#if defined CX_DEBUG_MODE
	#warning [Corex]: (dev-mode) have cx_izcmd installed
#endif
#include <CX_Core\cx_entry>
#include <CX_Extra\cx_izcmd\cx_izcmd_macro>
#include <CX_Extra\cx_izcmd\cx_izcmd_impl>