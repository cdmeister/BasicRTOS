#ifndef LOCKS_H_INCLUDED
#define LOCKS_H_INCLUDED

#include "stm32f407xx.h"
#include "task_management.h"
#include "scheduler.h"
#include <stddef.h>



#define MAX_LISTENERS 4

struct semaphore {
    uint32_t value;
    uint8_t listeners[MAX_LISTENERS];
};

typedef struct semaphore semaphore;

int sem_trywait(semaphore *s);
int sem_dopost(semaphore *s);
int sem_init(semaphore *s, int val);
int sem_wait(semaphore *s);
int sem_post(semaphore *s);


typedef semaphore mutex;
#define mutex_init(m) sem_init(m, 1)
#define mutex_trylock(m) sem_trywait(m)
#define mutex_lock(x) sem_wait(x)
#define mutex_unlock(x) sem_post(x)

#endif
