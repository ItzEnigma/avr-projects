/*
 * Computer Interface Lap.c
 *
 * Created: 10/21/2022 10:46:14 PM
 * Author : john
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "LAB3/LAB3_int.h"


int main(void)
{
    LAB3_vInit();
    while (1) 
    {
		LAB3_vUpdate();
    }
}

