/*
 * STM_pri.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Dell
 */

#ifndef HAL_STM_STM_PRI_H_
#define HAL_STM_STM_PRI_H

/*
 * @brief
 * the sequence of the row is
 * ORANGE // YELLOW // PINK // BLUE
 */

static const u8 G_u8HalfStepSeq[8][4] = {{1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}};
/*orange yellow pink blue */
static const u8 G_u8FullStepSeq[4][4] = {
	{0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}};

#define STEP_ANGLE_FULL_STEP 0.1758 /* (11.25/64) */
#define STEP_ANGLE_HALF_STEP 0.0879 /* (5.625/64) */

#endif /* HAL_STM_STM_PRI_H_ */
