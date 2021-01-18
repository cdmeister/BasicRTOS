#include "dynamic_memory.h"

void * _sbrk(uint32_t incr){
  static uint32_t * heap = NULL;
  void * old_heap = heap;
  if((incr & 0x03) != incr) {
    incr = ((incr >> 2) + 1) << 2;
  }
  if(old_heap == NULL){
    old_heap = heap = (uint32_t *) &_start_heap;
  }
  if((heap +incr) >= &_end_heap){
    return (void *)(-1);
  }
  else{
    heap += incr;
  }
  return old_heap;
}
