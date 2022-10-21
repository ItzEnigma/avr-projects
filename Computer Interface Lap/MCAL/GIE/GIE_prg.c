/*
 * GIE_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "GIE_reg.h"
#include "GIE_int.h"

void GIE_vSetGlobalInterrupt(){
	SET_BIT(SREG,I);
}
void GIE_vDisableGlobalInterrupt(){
	CLR_BIT(SREG,I);
}
