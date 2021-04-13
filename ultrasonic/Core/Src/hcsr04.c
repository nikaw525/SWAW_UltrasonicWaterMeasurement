/*
 * hcsr04.c
 *
 *  Created on: 2 kwi 2021
 *      Author: rzeszutko
 */

#include "hcsr04.h"

Prefault_distance_T Prefault_distance={
		.invalid_msg = false,
		.debounce_counter = 0,
		.distance = 0
};

dist kalman_filter(const dist u)
{
	// parametrs init
	const float R = 40;
	const float H = 1.0;
	static float Q = 10;
	static float P = 0;
	static float U_pri = 0;
	static float K = 0;

	K = P * H / (H * P * H + R);		 // update Kalman gain
	U_pri = U_pri + K * (u - H * U_pri); // update estimated

	P = (1 - K * H) * P + Q; // update error covariance

	return U_pri;
}

void reset_counter(Prefault_distance_T *self)
{
    self->debounce_counter = 0;
    self->invalid_msg = false;
}
