/*
 * TRANSISTORS_int.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Dell
 */

#ifndef HAL_TRANSISTORS_TRANSISTORS_INT_H_
#define HAL_TRANSISTORS_TRANSISTORS_INT_H_

typedef enum
{
    TRANS0,
    TRANS1,
    TRANS2,
    TRANS3,
};

void TRANSISTOR_vInit(u8 A_u8TransID);
void TRANSISTOR_vTurnOn(u8 A_u8TransID);
void TRANSISTOR_vTurnOff(u8 A_u8TransID);

#endif /* HAL_TRANSISTORS_TRANSISTORS_INT_H_ */
