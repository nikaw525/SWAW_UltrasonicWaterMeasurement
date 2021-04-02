/*
 * hcsr04.h
 *
 *  Created on: Mar 7, 2021
 *      Author: rzeszutko
 */

#ifndef INC_HCSR04_H_
#define INC_HCSR04_H_

#define HCSR04_PWM_CHANNEL TIM_CHANNEL_3
#define HCSR04_START_CHANNEL TIM_CHANNEL_1
#define HCSR04_STOP_CHANNEL TIM_CHANNEL_2

/* TO DO: Kalman fiter  */

float kalman_filter(float u);

#endif /* INC_HCSR04_H_ */
