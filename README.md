I2C init :



RCC Register : 
![clock tree](https://github.com/user-attachments/assets/ba8a6af2-bdee-49ce-8b7b-480832cb73bc)
code : 
uint32_t RCC_GetPCLK1Value(void)
{
    uint32_t pclk1,SystemClk ;
    
    uint8_t clksrc;
    clksrc = ((RCC->CFGR >> 2) & 0x3) ;

    if(clksrc == 0){
        SystemClk = 16000000;
    }else if(clksrc ==1){
        SystemClk = 8000000;
    }else if(clksrc ==2){
        SystemClk = RCC_GetPLLValue(); 
    }
    return pclk1 ;
}
