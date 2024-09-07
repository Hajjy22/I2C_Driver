
/*
 *      file : stm32f407xx_i2c_driver.h
 *      Created on: sep 9, 2024
 *      Author: hajjy ismail
 *      github: hajjy02
 *      linkdin: HAJJY ISMAIL
 */



#ifndef INC_STM32F407XX_I2C_DRIVER_H_
#define INC_STM32F407XX_I2C_DRIVER_H_

#include "stm32f407xx.h"

/*
    Configuration structure for I2Cx peripheral
*/

typedef struct{

	uint32_t I2C_SCLKSpeed ;	// refer @I2C_SCLK_SPEED
	uint8_t	I2C_DeviceAddress ; // mentioned by the user (no refrence)
	uint8_t	I2C_ACKControl    ;	// refer @I2C_ACK_CONTROL
	uint8_t	I2C_FMDutyCycle   ;	// refer @I2C_DUTY_CYCLE


}I2C_Config_t ;