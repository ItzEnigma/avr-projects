/*
 * Computer Interface Lap.c
 *
 * Created: 10/21/2022 10:46:14 PM
 * Author : john
 */ 

#include "./LAB2/lab2_int.h"
#include <avr/delay.h>


int main(void)
{
    lab2_vSetup();
    while (1) 
    {
		lab2_vloop();
		_delay_ms(500);
    }
}

