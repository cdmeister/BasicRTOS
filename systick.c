#include "systick.h"
#include "scheduler.h"
#include "task_management.h"

volatile uint32_t TimeDelay;
volatile uint32_t milliseconds;


/* SysTick System Handler */
void SysTick_Handler(void){
  /* TimeDelay is a global variable delcared as volatile */
  milliseconds++;
  if(milliseconds % TIMESLICE == 0){
    schedule();
  }
  if (TimeDelay >0)         /* Prevent it from being negative*/
    TimeDelay--;            /* TimeDelay is global volatile variable */
}

/* not very reliable now to use Delay with Systick due to context switch every
* TIMESLICE
*/
void Delay(uint32_t nTime){
  /* nTime: specifies the delay time Length */
  TimeDelay = nTime;        /* Time Delay must be declared as volatile */
  while(TimeDelay != 0);    /* Busy wait */
}

uint32_t millis() {
  return milliseconds;
}

/* Input: ticks = muber of ticks between two interrupts */
void SysTick_Init (uint32_t ticks){

  /*Disable SysTick IRQ and SysTick counter*/
  SysTick->CTRL = 0;
  TimeDelay = 0;
  milliseconds = 0;
  /* Set reload register */
  SysTick->LOAD = ticks - 1;

  /* Set interrupt priority of SysTick*/
  /* Make SysTick Least urgent(i.ie., highest priority number) */
  /* __NVIC_PRIO_BITS: number of bits for priority levels, defined in CMSIS */
  NVIC_SetPriority(SysTick_IRQn, 0);
  /* Set the lowest Priority for PendSV interrupt */
  NVIC_SetPriority(PendSV_IRQn, (1<<__NVIC_PRIO_BITS) -1);

  /* Reset the SysTick counter value*/
  SysTick->VAL = 0;

  /* Select Processor Cycle */
  /* 1 = processor clock; 0 = external clock */
  SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

  /*  Enables SysTick exception request */
  /*  1 = counting down to zero asserts the SysTick exception request */
  /*  0 = counting down to zero does not assert the SysTick exception request*/
  SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

  /* Enable SysTick Timer */
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;


}

void sleep_ms(uint32_t ms){
  if(ms < TIMESLICE) return;
  t_cur->wakeup_time = ms + millis();
  task_waiting(t_cur);
  schedule();
}
