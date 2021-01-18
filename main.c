#include "stdint.h"
#include "stm32f407xx.h"
#include "led.h"

/* Work out end of RAM address as intial stack pointer, Use both
 * (specific of a given STM32 MCU)
*/
#define SRAM_SIZE            128 * 1024 /* STM32F4O7 has 128 KB of RAM */
#define SRAM_END             (SRAM1_BASE + SRAM_SIZE)
#define RCC_AHB1ENR           ((uint32_t*)(RCC_BASE+ 0x30))

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */

#define PORTD_15 0x00008000
#define PORTD_14 0x00004000
#define PORTD_13 0x00002000
#define PORTD_12 0x00001000
#define PORTD_ALL 0x0000F000

int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */
  unsigned int delay =0;
  ledInit();
  /* Infinite loop */
  while (1)
  {
        for(delay= 0; delay < 1066667; delay++);
        red_led_toggle();
        for(delay= 0; delay < 1066667; delay++);
        blue_led_toggle();
        for(delay= 0; delay < 1066667; delay++);
        green_led_toggle();
        for(delay= 0; delay < 1066667; delay++);
        orange_led_toggle();
  }
}

