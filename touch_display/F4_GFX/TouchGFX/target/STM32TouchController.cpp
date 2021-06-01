/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include "MASTERS_TFT_TS.h"


using namespace touchgfx;

void STM32TouchController::init()
{

    /* Initialize the TS driver structure */
	BSP_TS_Init(480, 272);
    /* Initialize the TS driver */

}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /* Checking if the screen has been touched */

	  TS_StateTypeDef state = { 0 };
	    BSP_TS_GetState(&state);
	    if (state.touchDetected)
	    {
	        x = state.touchX[0];
	        y = state.touchY[0];

	        return true;
	    }
	    return false;
}

/**
  * @brief  Manages error callback by re-initializing I2C.
  * @param  i2c_handler : I2C handler
  * @param  Addr: I2C Address
  * @retval None
  */


/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
