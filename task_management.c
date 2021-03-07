#include "task_management.h"
#include "stddef.h"


extern void Default_Handler(void);


struct task_block TASKS[MAX_TASKS];
int n_tasks = 1;
int running_task_id = 0;

struct task_block * tasklist_waiting;
struct task_block * tasklist_active[MAX_PRIO];
struct task_block * t_cur = &TASKS[0];

static int idx = 0;


void task_stack_init(struct task_block *t){
  struct stack_frame * tf;
  struct extra_frame * ex;
  t->sp -= sizeof(struct stack_frame);
  tf = (struct stack_frame *)(t->sp);
  tf->r0 = (uint32_t) t->arg;
  tf->pc = (uint32_t) t->start;
  tf->lr = (uint32_t) Default_Handler;
  tf->xpsr =  0x01000000;
  t->sp -= sizeof(struct extra_frame);
  ex = (struct extra_frame *)(t->sp);
}

struct task_block * task_create(char * name, void (*start)(void *arg),
                                void * arg, uint8_t priority){

  struct task_block *t;
  int i;
  if (n_tasks >= MAX_TASKS) return NULL;
  t = &TASKS[n_tasks];
  t->id = n_tasks++;
  for(i = 0; i < TASK_NAME_MAXLEN; i++){
    t->name[i] = name[i];
    if (name[i] == 0) break;
  }
  t->state = TASK_READY;
  t->start = start;
  t->arg = arg;
  t->priority = priority;
  /* needs to be a uint8_t because in task_stack_init, it can decrement
     the stack pointer correctly
    (n_tasks-1) because only user created task in CCMRAM, kernel is still in
    SRAM.
  */
  t->sp =(uint8_t*) ((&_start_os_stack) + ((n_tasks-1) * STACK_SIZE));
  task_stack_init(t);
  tasklist_add_active(t);
  return t;
}
void __attribute__((naked)) store_kernel_context (void){

  __asm__ volatile ("mrs r0, msp");
  __asm__ volatile ("stmdb r0!, {r4-r11}");
  __asm__ volatile ("msr msp, r0");
  __asm__ volatile ("bx lr");

}

void __attribute__((naked)) restore_kernel_context (void){

  __asm__ volatile ("mrs r0, msp");
  __asm__ volatile ("ldmfd r0!, {r4-r11}");
  __asm__ volatile ("msr msp, r0");
  __asm__ volatile ("bx lr");

}

void __attribute__((naked)) store_user_context (void){

  __asm__ volatile ("mrs r0, psp");
  __asm__ volatile ("stmdb r0!, {r4-r11}");
  __asm__ volatile ("msr psp, r0");
  __asm__ volatile ("bx lr");

}

void __attribute__((naked)) restore_user_context (void){

  __asm__ volatile ("mrs r0, psp");
  __asm__ volatile ("ldmfd r0!, {r4-r11}");
  __asm__ volatile ("msr psp, r0");
  __asm__ volatile ("bx lr");

}


void tasklist_add(struct task_block ** list, struct task_block * el){
  el->next = *list;
  *list = el;
}

void tasklist_add_active(struct task_block * el){
  tasklist_add(&tasklist_active[el->priority], el);
}

int tasklist_del(struct task_block ** list, struct task_block * delme){

  struct task_block * t = *list;
  struct task_block * p = NULL;

  while(t){
    if(delme == t){
      if(p==NULL){
        *list = t->next;
      }
      else{
        p->next=t->next;
      }
      return 0;
    }
    p=t;
    t=t->next;
  }
  return -1;
}

int tasklist_del_active(struct task_block * delme){
  return tasklist_del(&tasklist_active[delme->priority], delme);
}

void task_waiting(struct task_block * t){
  if(tasklist_del_active(t) == 0){
    t->state = TASK_WAITING;
    tasklist_add(&tasklist_waiting, t);
  }
}
void task_ready(struct task_block * t){
  if(tasklist_del(&tasklist_waiting, t) == 0){
    t->state = TASK_READY;
    tasklist_add_active(t);
  }

}

struct task_block * tasklist_next_ready(struct task_block * t){
  for (idx = MAX_PRIO - 1; idx >= 0; idx--) {
    /* This is saying if the next task in the active queue has
     * the same priority as the current running task
     * then make the swtich to guarentee round robin mechanism
     */
    if ((idx == t->priority) && (t->next != NULL) && (t->next->state == TASK_READY))
      return t->next;
    if (tasklist_active[idx])
      return tasklist_active[idx];
    }
    return t;
}

