/*
 * PowerMgr.h
 *
 *  Created on: May 29, 2021
 *      Author: rzesz
 */

#ifndef INC_POWERMGR_H_
#define INC_POWERMGR_H_

#include <stdint.h>

#define V_REF 					9.0f
#define SUPPLAY_VOLTAGE 		3.3f
#define ADC_RESOLUTION			4095
#define AVG_SLOPE				4.3f
#define V25						1.43f

#define VOLTAGE_THRESHOLD		7.1f


typedef enum
{
  OFF = -1,
  INIT = 0,
  FULL_OPERATIONAL,
  STOP_MODE,
  ERROR_MODE = 255
} PowerMode;


void Switch_PowerMode(volatile PowerMode *flag);
float Calculate_BatteryVoltage(const uint16_t adc_read);
void BatteryVoltageMonitor(float Vbat, PowerMode  *flag);

#endif /* INC_POWERMGR_H_ */
