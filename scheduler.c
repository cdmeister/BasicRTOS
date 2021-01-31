#include "scheduler.h"
#include "task_management.h"

extern int running_task_id;
extern struct task_block TASKS[MAX_TASKS];
extern int n_tasks;
extern struct task_block * t_cur;

/* need naked to prevent prologue and epiloge code interacting with the
 * stack pointers and such
 */
void __attribute__((naked)) PendSV_Handler(void){
  store_context();
  __asm__ volatile("mrs %0, msp" : "=r"(t_cur->sp));
  if (t_cur->state == TASK_RUNNING){
    t_cur->state = TASK_READY;
  }
  t_cur = tasklist_next_ready(t_cur);
  t_cur->state = TASK_RUNNING;
  __asm__ volatile("msr msp, %0" ::"r"(t_cur->sp));
  restore_context();
  __asm__ volatile("mov lr, %0" ::"r"(0xFFFFFFF9));
  __asm__ volatile("bx lr");
}

void UsageFault_Handler(void){
  while(1);
}

void HardFault_Handler(void){
  while(1);
}
