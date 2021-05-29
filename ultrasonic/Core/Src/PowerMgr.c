/*
 * PowerMgr.c
 *
 *  Created on: May 29, 2021
 *      Author: rzesz
 */

#include "PowerMgr.h"
#include "main.h"


void Switch_PowerMode(volatile PowerMode *flag)
{
    if (FULL_OPERATIONAL == *flag)
    {
      *flag = STOP_MODE;
      HAL_SuspendTick();
      HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
      HAL_PWR_EnableSleepOnExit ();
      HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFI);
    }
    else if (STOP_MODE == *flag)
    {
      HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	  HAL_ResumeTick ();
      *flag = FULL_OPERATIONAL;
      HAL_PWR_DisableSleepOnExit();
    }
    else
    {
      /* Do nothing */
    }
}

void BatteryVoltageMonitor(float Vbat, PowerMode  *flag)
{
	if(Vbat < VOLTAGE_THRESHOLD && Vbat != 0)
	{
		Switch_PowerMode(flag);
	}
}

float Calculate_BatteryVoltage(const uint16_t adc_read)
{
	return ((adc_read *SUPPLAY_VOLTAGE/ ADC_RESOLUTION) * 3);
}
