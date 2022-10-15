/*
 * SWITCHES_cfg.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Dell
 */

#ifndef HAL_SWITCHES_SWITCHES_CFG_H_
#define HAL_SWITCHES_SWITCHES_CFG_H_

#define SWT0_PORT PORTD_ID
#define SWT0_PIN PIN0_ID

#define SWT1_PORT PORTD_ID
#define SWT1_PIN PIN1_ID

#define SWT2_PORT PORTD_ID
#define SWT2_PIN PIN2_ID

#define SWT3_PORT PORTD_ID
#define SWT3_PIN PIN3_ID

#define SWT4_PORT PORTD_ID
#define SWT4_PIN PIN4_ID

#define SWT5_PORT PORTD_ID
#define SWT5_PIN PIN5_ID

#define SWT6_PORT PORTD_ID
#define SWT6_PIN PIN6_ID

#define SWT7_PORT PORTD_ID
#define SWT7_PIN PIN7_ID

/*Pulling Abstraction*/
/**
 * @brief
 * The Parameters are
 * INTERNAL_PULLUP - EXTERNAL_PULLUP
 */
#define SWT_PULLING INTERNAL_PULLUP
#endif /* HAL_SWITCHES_SWITCHES_CFG_H_ */
