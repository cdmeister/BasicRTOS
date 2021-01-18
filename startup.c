#include "linker_defines.h"
#include "startup.h"

#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field.
                                   This value must be a multiple of 0x200. */

uint32_t SystemCoreClock = 168000000;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

extern void main(void);

void _initialize_data(uint32_t * flash_begin, uint32_t * data_begin,
                              uint32_t * data_end){
  uint32_t * p = data_begin;
  while(p<data_end) *p++ = *flash_begin++;

}

void _initialize_bss(uint32_t * bss_begin, uint32_t * bss_end){
  uint32_t * p = bss_begin;
  while(p<bss_end) *p++ = 0;

}

/**
  * General Idea to set the clock 168MHz
  *   1. RCC to Default State
  *   2. HSE Selection On
  *   3. Wait till the HSE is ready
  *   4. PLL Configuration
  *   5. Configure AHB/APB1/APB2
  *   6. Configre Flash Waitstates to 5
  *   7. Configure System Core Clock to use PLL
*/
void SetSysClock(void){

 /**
   * Since this is called from SystemInit(),
   * RCC is in the default state
   */
  /* Wait for the HSE to get started */
  volatile uint32_t HSEStatus=0;
  volatile uint32_t Startup_Counter;

  /* Turn on High Speed External Clock */
  RCC->CR |= RCC_CR_HSEON;

 do{
    /* Read bit 17 via a mask to check the */
    /* HSE is ready*/
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    ++Startup_Counter;
  }while((HSEStatus == 0) && (Startup_Counter != HSE_STARTUP_TIMEOUT));

  HSEStatus = ((RCC->CR & RCC_CR_HSERDY) != 0) ? (uint32_t) 0x1 : (uint32_t) 0x0;

  /* Able to successfully startup the HSE Clock */
  if(HSEStatus == (uint32_t) 0x1){

    /*Set the PWR_CFG VOS*/
    PWR->CR &= ~(PWR_CR_VOS_Msk);
    PWR->CR |= PWR_CR_VOS;

    /*Configre the multiplier and division factors to the RCC_PLLCFGR Register*/
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk);
    RCC->PLLCFGR |= (PLL_M << RCC_PLLCFGR_PLLM_Pos); /*PLL_M*/

    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_Msk);
    RCC->PLLCFGR |= (PLL_N << RCC_PLLCFGR_PLLN_Pos); /*PLL_N*/

    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP_Msk);
    RCC->PLLCFGR |= (((PLL_P>> 1)-1) << RCC_PLLCFGR_PLLP_Pos); /*PLL_P*/

    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ_Msk);
    RCC->PLLCFGR |= (PLL_Q << RCC_PLLCFGR_PLLQ_Pos); /*PLL_Q*/

    /* Main PLL(PLL) and audio PLL (PLLI2S) use HSE as clock source */
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC_Msk);
    RCC->PLLCFGR |=RCC_PLLCFGR_PLLSRC_HSE;

    /* AHB Clock Divider */
    RCC->CFGR &= ~(RCC_CFGR_HPRE_Msk);
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    /* APB1 Clock Divider */
    RCC->CFGR &= ~(RCC_CFGR_PPRE1_Msk);
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

    /* APB2 Clock Divider */
    RCC->CFGR &= ~(RCC_CFGR_PPRE2_Msk);
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;

    /** Configure Flash prefetch, Instruction cache, Data cache and wait state
      * 5 Wait states since clock is gonna be at 168MHz, please refer to
      * reference manual
      */
    FLASH->ACR = FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

    /* Turn the PLL ON after applying all of the settings */
    RCC->CR |= RCC_CR_PLLON;

    /* Wait till the main PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0){}

    /* Select the main PLL as system clock source */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* Wait till the main PLL is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL){}

    /* Turn off HSI clock since PLL is used as system clock*/
    /*RCC->CR &=~(RCC_CR_HSION);*/
    /*Debug only, check if it works */

    /* Enable Clock */
    /*RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;*/

    /* Set mode of all pins as digital output
     00 = digital input       01 = digital output
     10 = alternate function  11 = analog (default)*/
    /*GPIOD->MODER &= ~(0xFF<<24);*/ /* Clear mode bits */
    /*GPIOD->MODER |= 85UL<<24;*//* LED 5-8 are on GPIOD Pins 12-15 */

    /* Set output type of all pins as push-pull
     0 = push-pull (default)
     1 = open-drain*/
    /*GPIOD->OTYPER &= ~(0xF<<3);*/ /*Configure as output open-drain */

    /* Set output speed of all pins as high
     00 = Low speed           01 = Medium speed
     10 = Fast speed          11 = High speed*/
    /*GPIOD->OSPEEDR &=~(0xFF<<3);*/ /* Configure as high speed */
    /*GPIOD->OSPEEDR |= (0xFF<<3);*/

    /* Set all pins as no pull-up, no pull-down
     00 = no pull-up, no pull-down    01 = pull-up
     10 = pull-down,                  11 = reserved*/
    /*GPIOD->PUPDR &= ~(0xFF<<3);*/ /*no pul-up, no pull-down*/
    /*
    uint32_t i =0;
    uint32_t delay =0;
    for(;i<10;i++){
      GPIOD->ODR |=0x0000F000;
      for(delay= 0; delay < 1066667; delay++);
      GPIOD->ODR &=~(0x0000F000);
      for(delay= 0; delay < 1066667; delay++);
    }*/

  }
  else{
      /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
  }




}

void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case 0x00:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;
    case 0x04:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;
    case 0x08:  /* PLL used as system clock source */

      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
         SYSCLK = PLL_VCO / PLL_P
         */
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

      if (pllsource != 0)
      {
        /* HSE used as PLL clock source */
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
      }

      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
}



void SystemInit(void)
{

  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set HSION bit */
  RCC->CR |= (uint32_t)0x00000001;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000;

  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (uint32_t)0xFEF6FFFF;

  /* Reset PLLCFGR register */
  RCC->PLLCFGR = 0x24003010;

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* Disable all interrupts */
  RCC->CIR = 0x00000000;

  /* Configure the System clock source, PLL Multiplier and Divider factors,
     AHB/APBx prescalers and Flash settings ----------------------------------*/
  /* Setting the clock to max becuase I can :) */
  SetSysClock();

  /* Configure the Vector Table location add offset address ------------------*/
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
}


void Reset_Handler(void){
  _initialize_data(&_sidata,&_sdata,&_edata);
  _initialize_bss(&_sbss,&_ebss);
  SystemInit();
  main();
  for(;;);
}



