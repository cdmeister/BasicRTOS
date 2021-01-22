#ifndef TASK_MANAGEMENT_H
#define TASK_MANAGEMENT_H

#include "linker_defines.h"

/* Amount of space reserved for the execution stack of each task
 * expressed in four-byte words
 */
#define STACK_SIZE (256)

/* Task States */
#define TASK_WAITING   0
#define TASK_READY      1
#define TASK_RUNNING    2


#define TASK_NAME_MAXLEN    16
#define MAX_TASKS           8



/* Task block structure */
struct task_block {
  char name[TASK_NAME_MAXLEN];
  int id;
  int state;
  void (*start)(void *arg);
  void *arg;
  uint8_t * sp;
};


struct stack_frame {
  uint32_t r0, r1, r2, r3, r12, lr , pc, xpsr;
};

struct extra_frame {
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
};


void task_stack_init(struct task_block * t);

struct task_block * task_create(char * name, void (*start)(void *arg),
                                void * arg);




void __attribute__((naked)) store_context (void);
void __attribute__((naked)) restore_context (void);

#endif /*TASK_MANAGEMENT_H*/
