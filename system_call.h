#ifndef _SYSCALL_H
#define _SYSCALL_H

#include "stm32f407xx.h"
#include "scheduler.h"
#include "task_management.h"
#include "led.h"
#include "button.h"
#include "mpu.h"

/* System calls */
#define SYS_SCHEDULE 0
#define SYS_BUTTON_READ 1
#define SYS_BLUELED_ON 2
#define SYS_BLUELED_OFF 3
#define SYS_BLUELED_TOGGLE 4
#define SYS_REDLED_ON 5
#define SYS_REDLED_OFF 6
#define SYS_REDLED_TOGGLE 7
#define SYS_GREENLED_ON 8
#define SYS_GREENLED_OFF 9
#define SYS_GREENLED_TOGGLE 10

#define SVC() __asm__ volatile("svc 0")

int syscall(int arg0);

#endif /*_SYSCALL_H*/
