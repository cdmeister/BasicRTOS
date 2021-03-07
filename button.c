#include "button.h"
/*
 *
 * Embedded System Architecture
 * Copyright (c) 2018 Packt
 *
 * Author: Daniele Lacamera <root@danielinux.net>
 *
 * MIT License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdint.h>
#include <stddef.h>
#include "scheduler.h"
#include "task_management.h"
#include "button.h"
#include "stm32f407xx.h"

static void (*button_callback)(void) = NULL;
struct task_block *button_task = NULL;
extern struct task_block * t_cur;

void button_setup(void (*callback)(void))
{
    /* Enable Clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;


    // Set mode of all pins as digital output
    // 00 = digital input       01 = digital output
    // 10 = alternate function  11 = analog (default)
    GPIOD->MODER &= ~(GPIO_MODER_MODE0); /* Clear mode bits, set to input */

    /* Configuring external interrupt */
    // Enable SYSCFG clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    // Select PA0 as the trigger source of EXTI_0

    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0; //clear EXTI 0
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA; // set EXTI0 to map ext interrupt
                                               //  to PA0
    // Enable rising edge trigger for EXTI_0
    // Rising edge trigger selection register (RSTR)
    // 0 = disable  1 = enable
    EXTI->RTSR &= ~EXTI_RTSR_TR0;
    EXTI->RTSR |= EXTI_RTSR_TR0;

    // Disable Falling edge trigger EXTI 0
    // Falling trigger selection
    // 0 = disable  1 = enable
    EXTI->FTSR &= ~EXTI_FTSR_TR0;

    // Enable EXTI 0 Interrupt
    // Interrupt mask register: 0 = masked, 1 = unmasked
    // "Masked" means that processor ignores corresponding interupt
    EXTI->IMR &= ~EXTI_IMR_MR0;
    EXTI->IMR |= EXTI_IMR_MR0;

    // Enable EXTI 0 Events
    EXTI->EMR &= ~EXTI_EMR_MR0;
    EXTI->EMR |= EXTI_EMR_MR0;


    button_callback = callback;
}

void button_start_read(void){
  NVIC_EnableIRQ(EXTI0_IRQn);
}


int button_read(void)
{
    if (button_task)
        return 0;
    button_task = t_cur;
    task_waiting(t_cur);
    syscall(SYS_BUTTON_READ);
    return 1;
}

void EXTI0_IRQHandler(void){

    NVIC_DisableIRQ(EXTI0_IRQn);
    // Clear interupt pending request
    EXTI->PR |= EXTI_PR_PR0;
    if (button_callback)
      button_callback();

}

void button_wakeup(void)
{
    if (button_task) {
        task_ready(button_task);
        button_task = NULL;
        schedule();
    }
}
