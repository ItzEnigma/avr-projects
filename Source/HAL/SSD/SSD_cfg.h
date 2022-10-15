/*
 * SSD_cfg.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Dell
 */

#ifndef HAL_SSD_SSD_CFG_H_
#define HAL_SSD_SSD_CFG_H_

#define SSD0_DATA_PORT PORTC_ID
#define SSD0_EN_PORT PORTC_ID
#define SSD0_EN_PIN PIN7_ID

#define SSD1_DATA_PORT PORTD_ID
#define SSD1_EN_PORT PORTD_ID
#define SSD1_EN_PIN PIN7_ID

/*MODEs
 * SSD_MODE_ONE // SSD_MODE_TWO
 * CATHOD // ANODE
 */

#define SSD_MODE SSD_MODE_ONE
#define SSD_COMM CATHODE

#endif /* HAL_SSD_SSD_CFG_H_ */
