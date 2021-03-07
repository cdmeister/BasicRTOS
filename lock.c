#include "lock.h"

extern struct task_block TASKS[MAX_TASKS];
mutex m;

int sem_init(semaphore *s, int val)
{
    int i;
    s->value = val;
    for (i = 0; i < MAX_LISTENERS; i++)
        s->listeners[i] = 0;
    return 0;
}

int sem_wait(semaphore *s)
{
    int i;
    if (s == NULL)
        return -1;
    // sem_trywait return 0 on success of decrementing semaphore.
    if (sem_trywait(s) == 0)
        return 0;
    // if you failed, add yourself to the list of task listing to this semaphore.
    for (i = 0; i < MAX_LISTENERS; i++) {
        if (!s->listeners[i])
            s->listeners[i] = t_cur->id;
        if (s->listeners[i] == t_cur->id)
            break;
    }
    /* if you failed, then get added to waiting queue */
    task_waiting(t_cur);
    syscall(SYS_SCHEDULE);
    return sem_wait(s);
}

int sem_post(semaphore *s)
{
    int i;
    if (s == NULL)
        return -1;
    /* if task was able to increment the semaphore, then add all listeners to
     * active queue to 'wake them up'
     */
    if (sem_dopost(s) > 0) {
        for (i = 0; i < MAX_LISTENERS; i++) {
            if (s->listeners[i]) {
                task_ready(&TASKS[s->listeners[i]]);
                s->listeners[i] = 0;
            }
        }
        syscall(SYS_SCHEDULE);
    }
    return 0;
}
