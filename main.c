#include <stddef.h>

#include "stm32f407xx.h"
#include "led.h"
#include "task_management.h"
#include "systick.h"
#include "scheduler.h"

/* Work out end of RAM address as intial stack pointer, Use both
 * (specific of a given STM32 MCU)
*/
#define SRAM_SIZE            128 * 1024 /* STM32F4O7 has 128 KB of RAM */
#define SRAM_END             (SRAM1_BASE + SRAM_SIZE)
#define RCC_AHB1ENR           ((uint32_t*)(RCC_BASE+ 0x30))

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
extern uint32_t SystemCoreClock;
extern struct task_block TASKS[MAX_TASKS];
#define kernel TASKS[0]
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#define PORTD_15 0x00008000
#define PORTD_14 0x00004000
#define PORTD_13 0x00002000
#define PORTD_12 0x00001000
#define PORTD_ALL 0x0000F000



void task_test0(void *arg)
{
    blue_led_on();
    while(1) {
      sleep_ms(500);
      blue_led_toggle();
    }
}

void task_test1(void *arg)
{
    red_led_on();
    while(1) {
      sleep_ms(125);
      red_led_toggle();
    }
}

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */


int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */
  unsigned int delay =0;
  SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;
  ledInit();
  kernel.name[0] = 0;
  kernel.id = 0;
  kernel.state = TASK_RUNNING;
  kernel.wakeup_time = 0;
  tasklist_add(&tasklist_active, &kernel);
  task_create("test0", task_test0, NULL);
  task_create("test1", task_test1, NULL);
  /* Infinite loop */
  SysTick_Init(SystemCoreClock/1000);
  while (1)
  {
    struct task_block *t = tasklist_waiting;
    while(t){
      if (t->wakeup_time && (t->wakeup_time < millis())){
        t->wakeup_time = 0;
        task_ready(t);
        break;
      }
      t=t->next;
    }
    __WFI();
  }

}

