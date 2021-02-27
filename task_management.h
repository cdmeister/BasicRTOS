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
#define MAX_PRIO 4

extern struct task_block * tasklist_waiting;
extern struct task_block * tasklist_active[MAX_PRIO];
extern struct task_block * t_cur;



/* Task block structure */
struct task_block {
  char name[TASK_NAME_MAXLEN];
  int id;
  int state;
  void (*start)(void *arg);
  void *arg;
  uint8_t * sp;
  uint32_t wakeup_time;
  uint8_t priority;
  struct task_block * next;
};


struct stack_frame {
  uint32_t r0, r1, r2, r3, r12, lr , pc, xpsr;
};

struct extra_frame {
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
};


void task_stack_init(struct task_block * t);

struct task_block * task_create(char * name, void (*start)(void *arg),
                                void * arg, uint8_t priority);




void __attribute__((naked)) store_context (void);
void __attribute__((naked)) restore_context (void);

/* Add to front of list */
void tasklist_add(struct task_block ** list, struct task_block * el);

/* Shortcut to add to the active list */
void tasklist_add_active(struct task_block * el);

/* Delete matching from list */
int tasklist_del(struct task_block ** list, struct task_block * delme);

/* Shortcut to delete from the active list */
int tasklist_del_active(struct task_block * delme);

/* Move task from active to the waiting queue */
void task_waiting(struct task_block * t);

/* Move task from waiting to the active queue */
void task_ready(struct task_block * t);

/* Grab the next active task */
struct task_block * tasklist_next_ready(struct task_block * t);


#endif /*TASK_MANAGEMENT_H*/
