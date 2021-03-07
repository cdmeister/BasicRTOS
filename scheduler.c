#include "scheduler.h"
#include "task_management.h"
#include "mpu.h"

extern int running_task_id;
extern struct task_block TASKS[MAX_TASKS];
extern int n_tasks;
extern struct task_block * t_cur;

/* need naked to prevent prologue and epiloge code interacting with the
 * stack pointers and such
 */
void __attribute__((naked)) PendSV_Handler(void){
    if (t_cur->id == 0) {
        store_kernel_context();
        __asm__ volatile("mrs %0, msp" : "=r"(t_cur->sp));
    } else {
        store_user_context();
        __asm__ volatile("mrs %0, psp" : "=r"(t_cur->sp));
    }
    if (t_cur->state == TASK_RUNNING) {
        t_cur->state = TASK_READY;
    }
    t_cur = tasklist_next_ready(t_cur);
    t_cur->state = TASK_RUNNING;
    if (t_cur->id == 0) {
        __asm__ volatile("msr msp, %0" ::"r"(t_cur->sp));
        restore_kernel_context();
        __asm__ volatile("mov lr, %0" ::"r"(0xFFFFFFF9));
        __asm__ volatile("msr CONTROL, %0" ::"r"(0x00));
    } else {
        __asm__ volatile("msr psp, %0" ::"r"(t_cur->sp));
        restore_user_context();
        mpu_task_stack_permit(((uint8_t *)((&_start_os_stack)) + ((t_cur->id-1) << 10)));
        __asm__ volatile("mov lr, %0" ::"r"(0xFFFFFFFD));
        __asm__ volatile("msr CONTROL, %0" ::"r"(0x01));
    }
    __asm__ volatile("bx lr");
}

int syscall(int arg0){
  SVC();
  return 0;
}

void UsageFault_Handler(void){
  while(1);
}

void HardFault_Handler(void){
  while(1);
}
