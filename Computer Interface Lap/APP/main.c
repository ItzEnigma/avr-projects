/*
 * Computer Interface Lap.c
 *
 * Created: 10/21/2022 10:46:14 PM
 * Author : john
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "WaveGen/WaveGen_int.h"


int main(void)
{
    WaveGen_vInit();
    while (1) 
    {
		WaveGen_vUpdate();
    }
}

