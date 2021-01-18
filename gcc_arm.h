#ifndef __GCC_ARM
#define __GCC_ARM
/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
static __inline __attribute__((always_inline)) void __NOP(void)
{
  __asm__ volatile ("nop");
}

/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
static __inline __attribute__((always_inline)) void __DSB(void)
{
  __asm__ volatile ("dsb 0xF":::"memory");
}


/**
  \brief   Data Memory Barrier
  \details Ensures the apparent order of the explicit memory operations before
           and after the instruction, without ensuring their completion.
 */
static __inline __attribute__((always_inline)) void __DMB(void)
{
  __asm__ volatile ("dmb 0xF":::"memory");
}


#endif

