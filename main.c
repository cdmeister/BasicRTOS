#include <stddef.h>

#include "stm32f407xx.h"
#include "led.h"
#include "task_management.h"
#include "systick.h"
#include "scheduler.h"
#include "button.h"
#include "lock.h"
#include "mpu.h"

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
extern mutex m;
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
    while(1) {
      syscall(SYS_BLUELED_ON);
      mutex_lock(&m);
      sleep_ms(500);
      syscall(SYS_BLUELED_OFF);
      mutex_unlock(&m);
      sleep_ms(1000);
    }
}

void task_test1(void *arg)
{
    syscall(SYS_REDLED_ON);
    while(1) {
      sleep_ms(50);
      mutex_lock(&m);
      syscall(SYS_REDLED_TOGGLE);
      mutex_unlock(&m);
    }
}


void task_test2(void *arg)
{
    uint32_t toggle_time = 0;
    syscall(SYS_GREENLED_OFF);
    while(1) {
        if (button_read()) {
            if ((millis() - toggle_time) > 120) {
                syscall(SYS_GREENLED_TOGGLE);
                toggle_time = millis();
            }
        }
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
  mpu_enable();
  button_setup(button_wakeup);
  kernel.name[0] = 0;
  kernel.id = 0;
  kernel.state = TASK_RUNNING;
  kernel.wakeup_time = 0;
  kernel.priority = 0;
  tasklist_add_active( &kernel);
  task_create("test0", task_test0, NULL, 1);
  task_create("test1", task_test1, NULL, 1);
  task_create("test2", task_test2, NULL, 3);
  /* Infinite loop */
  SysTick_Init(SystemCoreClock/1000);
  mutex_init(&m);
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

