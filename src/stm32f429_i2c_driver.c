#include "stm32f429_i2c_driver.h"

uint32_t RCC_GetPLLValue()
{
     return 0;
}

//To get PCLK1 APB frequency Value in CCR register :
uint32_t RCC_GetPCLK1Value(void)
{
    uint32_t pclk1,SystemClk ;
    
    uint8_t clksrc;
    clksrc = ((RCC->CFGR >> 2) & 0x3) ;

    if(clksrc == 0){
        SystemClk = 16000000; //HSE
    }else if(clksrc ==1){
        SystemClk = 8000000; //HSI
    }else if(clksrc ==2){
        SystemClk = RCC_GetPLLValue(); //PLL
    }
    return pclk1 ;
}





void i2c_init(I2C_Handle_t *pI2CHandle)
{
      uint32_t tempreg = 0;
      tempreg |= pI2CHandle->I2CConfig.I2C_ACKControl << 10 ;
      
}