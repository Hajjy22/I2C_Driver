
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

// I2C Configuration macros

	// I2C_SCLK_SPEED

#define I2C_SCLK_SPEED_SM	100000
#define I2C_SCLK_SPEED_FM4K	400000
#define I2C_SCLK_SPEED_FM2K	200000
#define I2C_SCLK_SPEED_FM3K	300000


	 // I2C_ACK_CONTROL

#define I2C_ACK_ENABLE		1
#define I2C_ACK_DISABLE 	0

	// I2C_DUTY_CYCLE

#define I2C_FM_DUTY_2		0
#define I2C_FM_DUTY_16_9	1

#define  I2C_ENABLE_SR		ENABLE
#define  I2C_DISABLE_SR		DISABLE




/*
    Configuration structure for I2Cx peripheral
*/

typedef struct{

	uint32_t I2C_SCLKSpeed ;	// refer @I2C_SCLK_SPEED
	uint8_t	I2C_DeviceAddress ; // mentioned by the user (no refrence)
	uint8_t	I2C_ACKControl    ;	// refer @I2C_ACK_CONTROL
	uint8_t	I2C_FMDutyCycle   ;	// refer @I2C_DUTY_CYCLE


}I2C_Config_t;

/*
 * Handle structure for I2Cx peripheral
 * */

typedef struct{
	I2C_RegDef_t    *pI2Cx 	 ;		// this holds the base address of i2cx(1 ,2,3,4) peripheral
	I2C_Config_t    I2CConfig ;		// configuration structure reference
	uint8_t			*pTxBuffer ; 	// to store the Tx buffer address
	uint8_t			*pRxBuffer ; 	// to store the Rx buffer address
	uint32_t		 TxLen     ; 	// to store the Tx len
	uint32_t		 RxLen     ;  	// to store the Rx len
	uint8_t			 TxRxState ;	// to store communicatoopn state
	uint8_t			 DevAddr   ; 	// to store s;ave / Device address
	uint32_t		 RxSize    ;    // to store Rx Size
	uint8_t			 Sr ; 			// to store Repeated start value

}I2C_Handle_t;


