/**
  ******************************************************************************
  * @file    ft5336.c
  * @author  MCD Application Team
  * @brief   This file provides a set of functions needed to manage the FT5336
  *          touch screen devices.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#include "FT5426.h"

/* Touch screen driver structure initialization */
TS_DrvTypeDef ft5336_ts_drv =
{
  ft5336_Init,
  ft5336_ReadID,
  ft5336_Reset,

  ft5336_TS_Start,
  ft5336_TS_DetectTouch,
  ft5336_TS_GetXY,

  ft5336_TS_EnableIT,
  ft5336_TS_ClearIT,
  ft5336_TS_ITStatus,
  ft5336_TS_DisableIT

};


static ft5336_handle_TypeDef ft5336_handle = { FT5336_I2C_NOT_INITIALIZED, 0, 0};

static uint8_t ft5336_Get_I2C_InitializedStatus(void);

static void ft5336_I2C_InitializeIfRequired(void);

static uint32_t ft5336_TS_Configure(uint16_t DeviceAddr);

void ft5336_Init(uint16_t DeviceAddr)
{
  TS_IO_Delay(200);
  ft5336_I2C_InitializeIfRequired();
}

void ft5336_Reset(uint16_t DeviceAddr)
{

}

uint16_t ft5336_ReadID(uint16_t DeviceAddr)
{
  volatile uint8_t ucReadId = 0;
  uint8_t nbReadAttempts = 0;
  uint8_t bFoundDevice = 0;

  ft5336_I2C_InitializeIfRequired();

  for(nbReadAttempts = 0; ((nbReadAttempts < 3) && !(bFoundDevice)); nbReadAttempts++)
  {
    ucReadId = TS_IO_Read(DeviceAddr, FT5336_CHIP_ID_REG);
    if(ucReadId == FT5336_ID_VALUE)
    {
      bFoundDevice = 1;
    }
  }

  return (ucReadId);
}

void ft5336_TS_Start(uint16_t DeviceAddr)
{
  FT5336_ASSERT(ft5336_TS_Configure(DeviceAddr));
  ft5336_TS_DisableIT(DeviceAddr);
}

uint8_t ft5336_TS_DetectTouch(uint16_t DeviceAddr)
{
  volatile uint8_t nbTouch = 0;
  nbTouch = TS_IO_Read(DeviceAddr, FT5336_TD_STAT_REG);
  nbTouch &= FT5336_TD_STAT_MASK;

  if(nbTouch > FT5336_MAX_DETECTABLE_TOUCH)
  {
    nbTouch = 0;
  }

  ft5336_handle.currActiveTouchNb = nbTouch;
  ft5336_handle.currActiveTouchIdx = 0;

  return(nbTouch);
}

void ft5336_TS_GetXY(uint16_t DeviceAddr, uint16_t *X, uint16_t *Y)
{
  volatile uint8_t ucReadData = 0;
  static uint16_t coord;
  uint8_t regAddressXLow = 0;
  uint8_t regAddressXHigh = 0;
  uint8_t regAddressYLow = 0;
  uint8_t regAddressYHigh = 0;

  if(ft5336_handle.currActiveTouchIdx < ft5336_handle.currActiveTouchNb)
  {
    switch(ft5336_handle.currActiveTouchIdx)
    {
    case 0 :
      regAddressXLow  = FT5336_P1_XL_REG;
      regAddressXHigh = FT5336_P1_XH_REG;
      regAddressYLow  = FT5336_P1_YL_REG;
      regAddressYHigh = FT5336_P1_YH_REG;
      break;

    case 1 :
      regAddressXLow  = FT5336_P2_XL_REG;
      regAddressXHigh = FT5336_P2_XH_REG;
      regAddressYLow  = FT5336_P2_YL_REG;
      regAddressYHigh = FT5336_P2_YH_REG;
      break;

    case 2 :
      regAddressXLow  = FT5336_P3_XL_REG;
      regAddressXHigh = FT5336_P3_XH_REG;
      regAddressYLow  = FT5336_P3_YL_REG;
      regAddressYHigh = FT5336_P3_YH_REG;
      break;

    case 3 :
      regAddressXLow  = FT5336_P4_XL_REG;
      regAddressXHigh = FT5336_P4_XH_REG;
      regAddressYLow  = FT5336_P4_YL_REG;
      regAddressYHigh = FT5336_P4_YH_REG;
      break;

    case 4 :
      regAddressXLow  = FT5336_P5_XL_REG;
      regAddressXHigh = FT5336_P5_XH_REG;
      regAddressYLow  = FT5336_P5_YL_REG;
      regAddressYHigh = FT5336_P5_YH_REG;
      break;

    case 5 :
      regAddressXLow  = FT5336_P6_XL_REG;
      regAddressXHigh = FT5336_P6_XH_REG;
      regAddressYLow  = FT5336_P6_YL_REG;
      regAddressYHigh = FT5336_P6_YH_REG;
      break;

    case 6 :
      regAddressXLow  = FT5336_P7_XL_REG;
      regAddressXHigh = FT5336_P7_XH_REG;
      regAddressYLow  = FT5336_P7_YL_REG;
      regAddressYHigh = FT5336_P7_YH_REG;
      break;

    case 7 :
      regAddressXLow  = FT5336_P8_XL_REG;
      regAddressXHigh = FT5336_P8_XH_REG;
      regAddressYLow  = FT5336_P8_YL_REG;
      regAddressYHigh = FT5336_P8_YH_REG;
      break;

    case 8 :
      regAddressXLow  = FT5336_P9_XL_REG;
      regAddressXHigh = FT5336_P9_XH_REG;
      regAddressYLow  = FT5336_P9_YL_REG;
      regAddressYHigh = FT5336_P9_YH_REG;
      break;

    case 9 :
      regAddressXLow  = FT5336_P10_XL_REG;
      regAddressXHigh = FT5336_P10_XH_REG;
      regAddressYLow  = FT5336_P10_YL_REG;
      regAddressYHigh = FT5336_P10_YH_REG;
      break;

    default :
      break;

    }
    ucReadData = TS_IO_Read(DeviceAddr, regAddressXLow);
    coord = (ucReadData & FT5336_TOUCH_POS_LSB_MASK) >> FT5336_TOUCH_POS_LSB_SHIFT;

    ucReadData = TS_IO_Read(DeviceAddr, regAddressXHigh);
    coord |= ((ucReadData & FT5336_TOUCH_POS_MSB_MASK) >> FT5336_TOUCH_POS_MSB_SHIFT) << 8;

    *Y = coord ;

    ucReadData = TS_IO_Read(DeviceAddr, regAddressYLow);
    coord = (ucReadData & FT5336_TOUCH_POS_LSB_MASK) >> FT5336_TOUCH_POS_LSB_SHIFT;

    ucReadData = TS_IO_Read(DeviceAddr, regAddressYHigh);
    coord |= ((ucReadData & FT5336_TOUCH_POS_MSB_MASK) >> FT5336_TOUCH_POS_MSB_SHIFT) << 8;

    *X = coord;

    ft5336_handle.currActiveTouchIdx++;

  }
}

void ft5336_TS_EnableIT(uint16_t DeviceAddr)
{
   uint8_t regValue = 0;
   regValue = (FT5336_G_MODE_INTERRUPT_TRIGGER & (FT5336_G_MODE_INTERRUPT_MASK >> FT5336_G_MODE_INTERRUPT_SHIFT)) << FT5336_G_MODE_INTERRUPT_SHIFT;
   TS_IO_Write(DeviceAddr, FT5336_GMODE_REG, regValue);
}

void ft5336_TS_DisableIT(uint16_t DeviceAddr)
{
  uint8_t regValue = 0;
  regValue = (FT5336_G_MODE_INTERRUPT_POLLING & (FT5336_G_MODE_INTERRUPT_MASK >> FT5336_G_MODE_INTERRUPT_SHIFT)) << FT5336_G_MODE_INTERRUPT_SHIFT;

  TS_IO_Write(DeviceAddr, FT5336_GMODE_REG, regValue);
}

uint8_t ft5336_TS_ITStatus(uint16_t DeviceAddr)
{
  return 0;
}

void ft5336_TS_ClearIT(uint16_t DeviceAddr)
{

}

#if (TS_MULTI_TOUCH_SUPPORTED == 1)

void ft5336_TS_GetGestureID(uint16_t DeviceAddr, uint32_t * pGestureId)
{
  volatile uint8_t ucReadData = 0;

  ucReadData = TS_IO_Read(DeviceAddr, FT5336_GEST_ID_REG);

  * pGestureId = ucReadData;
}

void ft5336_TS_GetTouchInfo(uint16_t   DeviceAddr,
                            uint32_t   touchIdx,
                            uint32_t * pWeight,
                            uint32_t * pArea,
                            uint32_t * pEvent)
{
  volatile uint8_t ucReadData = 0;
  uint8_t regAddressXHigh = 0;
  uint8_t regAddressPWeight = 0;
  uint8_t regAddressPMisc = 0;

  if(touchIdx < ft5336_handle.currActiveTouchNb)
  {
    switch(touchIdx)
    {
    case 0 :
      regAddressXHigh   = FT5336_P1_XH_REG;
      regAddressPWeight = FT5336_P1_WEIGHT_REG;
      regAddressPMisc   = FT5336_P1_MISC_REG;
      break;

    case 1 :
      regAddressXHigh   = FT5336_P2_XH_REG;
      regAddressPWeight = FT5336_P2_WEIGHT_REG;
      regAddressPMisc   = FT5336_P2_MISC_REG;
      break;

    case 2 :
      regAddressXHigh   = FT5336_P3_XH_REG;
      regAddressPWeight = FT5336_P3_WEIGHT_REG;
      regAddressPMisc   = FT5336_P3_MISC_REG;
      break;

    case 3 :
      regAddressXHigh   = FT5336_P4_XH_REG;
      regAddressPWeight = FT5336_P4_WEIGHT_REG;
      regAddressPMisc   = FT5336_P4_MISC_REG;
      break;

    case 4 :
      regAddressXHigh   = FT5336_P5_XH_REG;
      regAddressPWeight = FT5336_P5_WEIGHT_REG;
      regAddressPMisc   = FT5336_P5_MISC_REG;
      break;

    case 5 :
      regAddressXHigh   = FT5336_P6_XH_REG;
      regAddressPWeight = FT5336_P6_WEIGHT_REG;
      regAddressPMisc   = FT5336_P6_MISC_REG;
      break;

    case 6 :
      regAddressXHigh   = FT5336_P7_XH_REG;
      regAddressPWeight = FT5336_P7_WEIGHT_REG;
      regAddressPMisc   = FT5336_P7_MISC_REG;
      break;

    case 7 :
      regAddressXHigh   = FT5336_P8_XH_REG;
      regAddressPWeight = FT5336_P8_WEIGHT_REG;
      regAddressPMisc   = FT5336_P8_MISC_REG;
      break;

    case 8 :
      regAddressXHigh   = FT5336_P9_XH_REG;
      regAddressPWeight = FT5336_P9_WEIGHT_REG;
      regAddressPMisc   = FT5336_P9_MISC_REG;
      break;

    case 9 :
      regAddressXHigh   = FT5336_P10_XH_REG;
      regAddressPWeight = FT5336_P10_WEIGHT_REG;
      regAddressPMisc   = FT5336_P10_MISC_REG;
      break;

    default :
      break;

    }

    ucReadData = TS_IO_Read(DeviceAddr, regAddressXHigh);
    * pEvent = (ucReadData & FT5336_TOUCH_EVT_FLAG_MASK) >> FT5336_TOUCH_EVT_FLAG_SHIFT;

    ucReadData = TS_IO_Read(DeviceAddr, regAddressPWeight);
    * pWeight = (ucReadData & FT5336_TOUCH_WEIGHT_MASK) >> FT5336_TOUCH_WEIGHT_SHIFT;

    ucReadData = TS_IO_Read(DeviceAddr, regAddressPMisc);
    * pArea = (ucReadData & FT5336_TOUCH_AREA_MASK) >> FT5336_TOUCH_AREA_SHIFT;

  }
}

#endif

static uint8_t ft5336_Get_I2C_InitializedStatus(void)
{
  return(ft5336_handle.i2cInitialized);
}

static void ft5336_I2C_InitializeIfRequired(void)
{
  if(ft5336_Get_I2C_InitializedStatus() == FT5336_I2C_NOT_INITIALIZED)
  {
    TS_IO_Init();
    ft5336_handle.i2cInitialized = FT5336_I2C_INITIALIZED;
  }
}

static uint32_t ft5336_TS_Configure(uint16_t DeviceAddr)
{
  uint32_t status = FT5336_STATUS_OK;
  return(status);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
