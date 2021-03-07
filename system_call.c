#include "system_call.h"


void __attribute__((naked)) SVC_Handler(int arg)
{
    store_user_context();
    __asm__ volatile("mrs %0, psp" : "=r"(t_cur->sp));
    if (t_cur->state == TASK_RUNNING) {
        t_cur->state = TASK_READY;
    }
    switch(arg) {
        case SYS_BUTTON_READ:
            button_start_read();
            /* fall through */
        case SYS_SCHEDULE:
            t_cur = tasklist_next_ready(t_cur);
            t_cur->state = TASK_RUNNING;
            break;
        case SYS_BLUELED_ON:
            blue_led_on();
            break;
        case SYS_BLUELED_OFF:
            blue_led_off();
            break;
        case SYS_BLUELED_TOGGLE:
            blue_led_toggle();
            break;
        case SYS_GREENLED_ON:
            green_led_on();
            break;
        case SYS_GREENLED_OFF:
            green_led_off();
            break;
        case SYS_GREENLED_TOGGLE:
            green_led_toggle();
            break;
        case SYS_REDLED_ON:
            red_led_on();
            break;
        case SYS_REDLED_OFF:
            red_led_off();
            break;
        case SYS_REDLED_TOGGLE:
            red_led_toggle();
            break;
    }
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
    return;

}

