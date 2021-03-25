#include "stm32f4xx_hal.h"
   
#define TS_INT_PIN                           		GPIO_PIN_4
#define TS_INT_GPIO_PORT                     		GPIOB
#define TS_INT_GPIO_CLK_ENABLE()             		__HAL_RCC_GPIOI_CLK_ENABLE()
#define TS_INT_GPIO_CLK_DISABLE()            		__HAL_RCC_GPIOI_CLK_DISABLE()
#define TS_INT_EXTI_IRQn                     		EXTI4_IRQn
#define TS_I2C_ADDRESS                   			((uint16_t)0x70)

#define MASTERS_TFT_I2Cx                            I2C3
#define MASTERS_TFT_I2Cx_CLK_ENABLE()               __HAL_RCC_I2C3_CLK_ENABLE()
#define MASTERS_TFT_I2Cx_SCL_GPIO_CLK_ENABLE()   	__HAL_RCC_GPIOA_CLK_ENABLE()
#define MASTERS_TFT_I2Cx_SDA_GPIO_CLK_ENABLE()   	__HAL_RCC_GPIOC_CLK_ENABLE()
#define MASTERS_TFT_I2Cx_FORCE_RESET()              __HAL_RCC_I2C3_FORCE_RESET()
#define MASTERS_TFT_I2Cx_RELEASE_RESET()            __HAL_RCC_I2C3_RELEASE_RESET()
#define MASTERS_TFT_I2Cx_SCL_PIN                    GPIO_PIN_8
#define MASTERS_TFT_I2Cx_SCL_GPIO_PORT           	GPIOA
#define MASTERS_TFT_I2Cx_SCL_SDA_AF                 GPIO_AF4_I2C3
#define MASTERS_TFT_I2Cx_SDA_PIN                    GPIO_PIN_9
#define MASTERS_TFT_I2Cx_SDA_GPIO_PORT           	GPIOC

#define MASTERS_TFT_I2Cx_EV_IRQn                    I2C3_EV_IRQn
#define MASTERS_TFT_I2Cx_ER_IRQn                    I2C3_ER_IRQn

#define MASTERS_TFT_I2Cx_TIMING                     100000
