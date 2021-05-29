/*
 * hcsr04.c
 *
 *  Created on: 2 kwi 2021
 *      Author: rzeszutko
 */

#include "hcsr04.h"
#include "PowerMgr.h"
#include <math.h>

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

static float Calculate_MCU_Temperature(const uint16_t adc_read)
{
	float Vsense;
	Vsense = (SUPPLAY_VOLTAGE * adc_read)/ADC_RESOLUTION;

	return (((V25 - Vsense)/AVG_SLOPE) + 25.0f);
}


float Calculate_SoundSpeed(const uint16_t adc_read)
{
	float temperature = Calculate_MCU_Temperature(adc_read);
	return (V_IN_AIR_AT_0 * sqrt(1+(temperature/273.0f)));
}

void reset_counter(Prefault_distance_T *self)
{
    self->debounce_counter = 0;
    self->invalid_msg = false;
}
