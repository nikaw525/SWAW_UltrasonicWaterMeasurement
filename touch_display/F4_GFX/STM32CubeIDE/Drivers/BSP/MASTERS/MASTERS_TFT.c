#include "MASTERS_TFT.h"

static I2C_HandleTypeDef hI2cAudioHandler = {0};

static void     I2Cx_MspInit(I2C_HandleTypeDef *i2c_handler);
static void     I2Cx_Init(I2C_HandleTypeDef *i2c_handler);

static HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef *i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddSize, uint8_t *Buffer, uint16_t Length);
static HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef *i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddSize, uint8_t *Buffer, uint16_t Length);

static void              I2Cx_Error(I2C_HandleTypeDef *i2c_handler, uint8_t Addr);


static void I2Cx_MspInit(I2C_HandleTypeDef *i2c_handler)
{
  GPIO_InitTypeDef  gpio_init_structure;

    //MASTERS_TFT_I2Cx_SCL_SDA_GPIO_CLK_ENABLE();
  MASTERS_TFT_I2Cx_SCL_GPIO_CLK_ENABLE();
  MASTERS_TFT_I2Cx_SDA_GPIO_CLK_ENABLE();

    gpio_init_structure.Pin = MASTERS_TFT_I2Cx_SCL_PIN;
    gpio_init_structure.Mode = GPIO_MODE_AF_OD;
    gpio_init_structure.Pull = GPIO_NOPULL;
    gpio_init_structure.Speed = GPIO_SPEED_FAST;
    gpio_init_structure.Alternate = MASTERS_TFT_I2Cx_SCL_SDA_AF;
    HAL_GPIO_Init(MASTERS_TFT_I2Cx_SCL_GPIO_PORT, &gpio_init_structure);

    gpio_init_structure.Pin = MASTERS_TFT_I2Cx_SDA_PIN;
    HAL_GPIO_Init(MASTERS_TFT_I2Cx_SDA_GPIO_PORT, &gpio_init_structure);

    MASTERS_TFT_I2Cx_CLK_ENABLE();
    MASTERS_TFT_I2Cx_FORCE_RESET();
    MASTERS_TFT_I2Cx_RELEASE_RESET();

    HAL_NVIC_SetPriority(MASTERS_TFT_I2Cx_EV_IRQn, 0x0F, 0);
    HAL_NVIC_EnableIRQ(MASTERS_TFT_I2Cx_EV_IRQn);

    HAL_NVIC_SetPriority(MASTERS_TFT_I2Cx_ER_IRQn, 0x0F, 0);
    HAL_NVIC_EnableIRQ(MASTERS_TFT_I2Cx_ER_IRQn);

}


static void I2Cx_Init(I2C_HandleTypeDef *i2c_handler)
{
  if(HAL_I2C_GetState(i2c_handler) == HAL_I2C_STATE_RESET)
  {
    i2c_handler->Instance = MASTERS_TFT_I2Cx;
    i2c_handler->Init.ClockSpeed           = MASTERS_TFT_I2Cx_TIMING;
    i2c_handler->Init.OwnAddress1      = 0;
    i2c_handler->Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    i2c_handler->Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    i2c_handler->Init.OwnAddress2      = 0;
    i2c_handler->Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    i2c_handler->Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

    I2Cx_MspInit(i2c_handler);
    HAL_I2C_Init(i2c_handler);
  }
}


static HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef *i2c_handler,
                                           uint8_t Addr,
                                           uint16_t Reg,
                                           uint16_t MemAddress,
                                           uint8_t *Buffer,
                                           uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_I2C_Mem_Read(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);
  if(status != HAL_OK)
  {
    I2Cx_Error(i2c_handler, Addr);
  }
  return status;
}


static HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef *i2c_handler,
                                            uint8_t Addr,
                                            uint16_t Reg,
                                            uint16_t MemAddress,
                                            uint8_t *Buffer,
                                            uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_I2C_Mem_Write(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);
  if(status != HAL_OK)
  {
    I2Cx_Error(i2c_handler, Addr);
  }
  return status;
}


static void I2Cx_Error(I2C_HandleTypeDef *i2c_handler, uint8_t Addr)
{
  HAL_I2C_DeInit(i2c_handler);
  I2Cx_Init(i2c_handler);
}


/********************************* TOUCHSCREEN *********************************/

void TS_IO_Init(void)
{
  I2Cx_Init(&hI2cAudioHandler);
}


void TS_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
  I2Cx_WriteMultiple(&hI2cAudioHandler, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT,(uint8_t*)&Value, 1);
}


uint8_t TS_IO_Read(uint8_t Addr, uint8_t Reg)
{
  uint8_t read_value = 0;

  I2Cx_ReadMultiple(&hI2cAudioHandler, Addr, Reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&read_value, 1);

  return read_value;
}


void TS_IO_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}


