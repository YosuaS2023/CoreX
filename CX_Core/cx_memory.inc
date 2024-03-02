/*
 a88888b.                            dP    dP
d8'   `88                            Y8.  .8P
88        .d8888b. 88d888b. .d8888b.  Y8aa8P 
88        88'  `88 88'  `88 88ooood8 d8'  `8b
Y8.   .88 88.  .88 88       88.  ... 88    88
 Y88888P' `88888P' dP       `88888P' dP    dP
 */


// Entry point.
#define @cxmemory%0\32;%1\10;%3 ModifyDETUtilsMemory(%1);

// Internal.

enum CX_e_Memory
{
	entryInit
}

new CX_g_EntryMemory[CX_e_Memory];

// Operands:
#define SysInit 0

// Funcs.
stock ModifyDETUtilsMemory(operand, value)
{
	if(operand == SysInit)
	{
		CX_g_EntryMemory[entryInit] = value;
		printf("*** [CoreX]: (memory) - Operand \"SysInit\" has been updated to: \"%i\"", CX_g_EntryMemory[entryInit]);
	}
	return 1;
}