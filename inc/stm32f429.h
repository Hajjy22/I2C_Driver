
/*
 *      file :stm32f429.h
 *      Created on: sep 9, 2024
 *      Author: hajjy ismail
 *      github: hajjy02
 *      linkdin: HAJJY ISMAIL
 */

#ifndef INC_STM32F429_H_
#define INC_STM32F429_H_
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#define __vo volatile

// base address of flash and ram memories
#define FLASH_BASEADDR	0x08000000U
#define SRAM1_BASEADDR	0x20000000U	// 112kb of sram1
#define SRAM2_BASEADDR	0x20001C00U	// 16 kb of sram2
#define ROM_BASEADDR	0x1FFF0000U	// 30kb of  system memory
#define SRAM 			SRAM1_BASEADDR

#define ENABLE  1
#define DISABLE 0
#define SET		ENABLE
#define RESET 	DISABLE
#define FLAG_RESET	RESET
#define FLAG_SET	SET


////////////////////////////////////Processor specific details ///////////////////////////////////
/* Arm cortex Mx NVIC register addresses */
	 // stm32f429 has only 91 interrupts implemented by the vendor itself
#define NVIC_ISER0				(__vo uint32_t*)0xE000E100
#define NVIC_ISER1				(__vo uint32_t*)0xE000E104
#define NVIC_ISER2				(__vo uint32_t*)0xE000E108

#define NVIC_ICER0				(__vo uint32_t*)0xE000E180
#define NVIC_ICER1				(__vo uint32_t*)0xE000E184
#define NVIC_ICER2				(__vo uint32_t*)0xE000E188

#define NVIC_IPR_BASE_ADDR			(__vo uint32_t *)0xE000E400
#define NO_PR_BITS_IMPLEMENTED 		4

////////////////////////////////////////////////////////////////////////////////////////////////

// base address for various bus domains
#define APB1ERIPH_BASE	0x40000000U
#define APB2ERIPH_BASE	0x40010000U



// I2C peripheral base address
#define I2C1_BASEADDR 	(APB1ERIPH_BASE + 0x5400 )
#define I2C2_BASEADDR 	(APB1ERIPH_BASE + 0x5800 )
#define I2C3_BASEADDR 	(APB1ERIPH_BASE + 0x5C00 )


//RCC structure definition

typedef struct {
	__vo  uint32_t	CR 			;
	__vo  uint32_t	PLLCFGR 	;
	__vo  uint32_t	CFGR		;
	__vo  uint32_t	CIR			;
	__vo  uint32_t	AHB1RSTR	;
	__vo  uint32_t	AHB2RSTR	;
	__vo  uint32_t	AHB3RSTR	;
	__vo  uint32_t	RESERVED1	;
	__vo  uint32_t	APB1RSTR	;
	__vo  uint32_t	APB2RSTR	;
	__vo  uint32_t	RESERVED2[2];
	__vo  uint32_t	AHB1ENR 	;
	__vo  uint32_t	AHB2ENR 	;
	__vo  uint32_t	AHB3ENR 	;
	__vo  uint32_t	RESERVED3 	;
	__vo  uint32_t	APB1ENR 	;
	__vo  uint32_t	APB2ENR 	;
	__vo  uint32_t	RESERVED4[2];
	__vo  uint32_t	AHB1LPENR 	;
	__vo  uint32_t	AHB2LPENR 	;
	__vo  uint32_t	AHB3LPENR 	;
	__vo  uint32_t	RESERVED5 	;
	__vo  uint32_t	APB1LPENR 	;
	__vo  uint32_t	APB2LPENR 	;
	__vo  uint32_t	RESERVED6[2];
	__vo  uint32_t	BDCR 		;
	__vo  uint32_t	CSR 		;
	__vo  uint32_t	RESERVED7[2];
	__vo  uint32_t	SSCGR 		;
	__vo  uint32_t	PLLI2SCFGR 	;

}RCC_RegDef_t;


//EXTI structure definition
typedef struct {
	__vo uint32_t IMR  ;
	__vo uint32_t EMR  ;
	__vo uint32_t RTSR ;
	__vo uint32_t FTSR ;
	__vo uint32_t SWIER;
	__vo uint32_t PR   ;

}EXTI_RegDef_t;

//SYSCFG structure definition
typedef struct {
__vo uint32_t MEMRMP ;
__vo uint32_t PMC    ;
__vo uint32_t EXTICR[4] ;
__vo uint32_t RESERVED[2] ;
__vo uint32_t CMPCR	  ;

}SYSCFG_RegDef_t;

// I2C structure definition

typedef struct {
	__vo uint32_t CR1 	;
	__vo uint32_t CR2 	;
	__vo uint32_t OAR1 	;
	__vo uint32_t OAR2 	;
	__vo uint32_t DR	;
	__vo uint32_t SR1	;
	__vo uint32_t SR2   ;
	__vo uint32_t CCR	;
	__vo uint32_t TRISE	;
	__vo uint32_t FLTR	;

}I2C_RegDef_t ;


// RCC struct macro
#define RCC 	((RCC_RegDef_t *)RCC_BASEADDR)

// EXTI struct macro
#define EXTI	((EXTI_RegDef_t *)EXTI_BASEADDR)

//SYSCFG struct macro

#define SYSCFG	((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


// I2Cx struct macro

#define I2C1	((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2	((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3	((I2C_RegDef_t*)I2C3_BASEADDR)


// Peripheral clock enable macros

	// clock enable macros for I2Cx
	#define I2C1_CLOCK_ENABLE()			(RCC->APB1ENR |= (1 << 21) )
	#define I2C2_CLOCK_ENABLE()			(RCC->APB1ENR |= (1 << 22) )
	#define I2C3_CLOCK_ENABLE()			(RCC->APB1ENR |= (1 << 23) )

	// clock enable macro for syscfg
	#define SYSCFG_CLOCK_ENABLE()			(RCC->APB2ENR |= (1 << 14) )

// Peripheral clock disable macros

	// clock disable macros for I2Cx
	#define I2C1_CLOCK_DISABLE()			(RCC->APB1ENR &= ~(1 << 21) )
	#define I2C2_CLOCK_DISABLE()			(RCC->APB1ENR &= ~(1 << 22) )
	#define I2C3_CLOCK_DISABLE()			(RCC->APB1ENR &= ~(1 << 23) )

	// clock disable macro for syscfg
	#define SYSCFG_CLOCK_DISABLE()			(RCC->APB2ENR &= ~(1 << 14) )

/*
 * bit definition macros of i2c peripheral
 * */

		// CR1 bit position definition

#define I2C_CR1_PE			    0
#define I2C_CR1_SMBUS		    1
#define I2C_CR1_SMBTYPE		    3
#define I2C_CR1_ENARP		    4
#define I2C_CR1_ENPEC		    5
#define I2C_CR1_ENGC		    6
#define I2C_CR1_NOSTRETCH	    7
#define I2C_CR1_START		    8
#define I2C_CR1_STOP		    9
#define I2C_CR1_ACK		    	10
#define I2C_CR1_POS		    	11
#define I2C_CR1_PEC		    	12
#define I2C_CR1_ALERT		    13
#define I2C_CR1_SWRST		    15


		// CR2 bit position definition

#define I2C_CR2_FREQ			0
#define I2C_CR2_ITERREN		    8
#define I2C_CR2_ITEVTEN		    9
#define I2C_CR2_ITBUFEN		    10
#define I2C_CR2_DMAEN		    11
#define I2C_CR2_LAST		    12

		// OAR1 bit position definition

#define I2C_OAR1_ADD0			0
#define I2C_OAR1_ADD			1
#define I2C_OAR1_AD1			8
#define I2C_OAR1_ADDMODE		15

		// OAR2 bit position definition

#define I2C_OAR2_ENDUAL			0
#define I2C_OAR2_ADD2			1

		// DR bit position definition

#define I2C_DR_DR			0

		// SR1 bit position definition

#define I2C_SR1_SB			    0
#define I2C_SR1_ADDR		    1
#define I2C_SR1_BTF		    	2
#define I2C_SR1_ADD10		    3
#define I2C_SR1_STOPF		    4
#define I2C_SR1_RxNE		    6
#define I2C_SR1_TxE				7
#define I2C_SR1_BERR		    8
#define I2C_SR1_ARLO		    9
#define I2C_SR1_AF		    	10
#define I2C_SR1_OVR		    	11
#define I2C_SR1_PECERR		    12
#define I2C_SR1_TIMEOUT		    14
#define I2C_SR1_SMBALERT		15

		// SR2 bit position definition

#define I2C_SR2_MSL			    0
#define I2C_SR2_BUSY		    1
#define I2C_SR2_TRA				2
#define I2C_SR2_GENCALL			4
#define I2C_SR2_SMBDEFAULT		5
#define I2C_SR2_SMBHOST			6
#define I2C_SR2_DUALF			7
#define I2C_SR2_PEC				8

		// CCR bit position definition

#define I2C_CCR_CCR				0
#define I2C_CCR_DUTY			14
#define I2C_CCR_FS				15

		// TRISE bit position definition

#define I2C_TRISE_TRISE			0

		// FLTR bit position definition

#define I2C_FLTR_DNF			0
#define I2C_FLTR_ANOFF			4




#endif /* INC_STM32F429_H_ */