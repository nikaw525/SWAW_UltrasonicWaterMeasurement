/*
 * hcsr04.h
 *
 *  Created on: Mar 7, 2021
 *      Author: rzeszutko
 */

#ifndef INC_HCSR04_H_
#define INC_HCSR04_H_

#include <stdbool.h>
#include <stdint.h>

#define DEBOUNCE_CYCLES UINT16_MAX

typedef float dist;

typedef struct Prefault
{
	bool invalid_msg;
	uint16_t debounce_counter;
	volatile dist distance;
}Prefault_distance_T;

#define HCSR04_PWM_CHANNEL TIM_CHANNEL_3
#define HCSR04_START_CHANNEL TIM_CHANNEL_1
#define HCSR04_STOP_CHANNEL TIM_CHANNEL_2

dist kalman_filter(const dist u);

void reset_counter(Prefault_distance_T *self);


#endif /* INC_HCSR04_H_ */
