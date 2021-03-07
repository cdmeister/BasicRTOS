#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include "stm32f407xx.h"
#include "system_call.h"
/* Calls the PENDSV ISR */
#define schedule() SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;

#endif /*_SCHEDULER_H*/
