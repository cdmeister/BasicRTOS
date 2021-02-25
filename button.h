#ifndef BUTTON_H
#define BUTTON_H

void button_start_read(void);
int button_read(void);
void button_setup(void (*callback)(void));
int button_is_pressed(void);
void button_wakeup(void);

#endif /*BUTTON_H*/
