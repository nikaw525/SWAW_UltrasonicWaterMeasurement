/*
 * hcsr04.c
 *
 *  Created on: 2 kwi 2021
 *      Author: rzeszutko
 */

#include "hcsr04.h"
#include "PowerMgr.h"
#include <math.h>
#include <string.h>

#define NUMBER_OF_SAMPLES 10U

static dist buffor[NUMBER_OF_SAMPLES] = {0};

static dist average(dist *tab, int N)
{
    dist avg;

    for(int i = 0; i < N; i++)
    {
        avg+=tab[i];
    }

    return (avg/(dist)N);
}

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

dist moving_average(const dist distance)
{
    dist retVal = 0;

    dist tmp[NUMBER_OF_SAMPLES] = {0};

    tmp[0] = distance;

    for(int i=1; i< NUMBER_OF_SAMPLES; i++)
    {
        tmp[i] = buffor[i-1];
    }

    memcpy(buffor, tmp, sizeof(int) * NUMBER_OF_SAMPLES);

    retVal = average(buffor, NUMBER_OF_SAMPLES);

    return retVal;
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
