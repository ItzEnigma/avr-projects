/*
 * Computer Interface Lap.c
 *
 * Created: 10/21/2022 10:46:14 PM
 * Author : john
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "../LIB/std_types.h"
#include "LogicAnalyzer/LogicAnalyzer_int.h"
#include "Osc/Osc.h"

int main(void)
{
 

 LogicAnalyzer_vInit();
 
    while (1) 
    {
		LogicAnalyzer_vUpdate();
    }
}

