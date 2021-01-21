#include "scheduler.h"
#include "task_management.h"

extern int running_task_id;
extern struct task_block TASKS[MAX_TASKS];
extern int n_tasks;

/* need naked to prevent prologue and epiloge code interacting with the
 * stack pointers and such
 */
void __attribute__((naked)) PendSV_Handler(void){
    store_context();
    __asm__ volatile("mrs %0, msp" : "=r"(TASKS[running_task_id].sp));
    TASKS[running_task_id].state = TASK_WAITING;
    running_task_id++;
    if (running_task_id >= n_tasks)
        running_task_id = 0;
    TASKS[running_task_id].state = TASK_RUNNING;
    __asm__ volatile("msr msp, %0" ::"r"(TASKS[running_task_id].sp));
    restore_context();
    __asm__ volatile("mov lr, %0" ::"r"(0xFFFFFFF9));
    __asm__ volatile("bx lr");
}
void UsageFault_Handler(void){
  while(1);
}
