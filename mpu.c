#include "mpu.h"

int mpu_enable(void){

  if((MPU->TYPE & MPU_TYPE_DREGION) == 0){
    /* MPU is not present */
    return -1;
  }

  /* Make sure outstanding transfers are done */
  __DMB();

  /* Make sure MPU is disable while we change the base address */
  MPU->CTRL &= ~(MPU_CTRL_ENABLE);

  /* Setup Flash region, Flash base address start is at address 0x0 */
  MPU->RNR = MPU_RNR_REGION_0;
  MPU->RBAR =  (0x08000000);
  MPU->RASR = (MPU_RASR_AP_RO_RO|MPU_RASR_NORMAL_SHARED_MEM_WB|MPU_RASR_SIZE_512K|MPU_RASR_ENABLE);

  /* Setup SRAM region, SRAM base address start is at address 0x20000000 */
  MPU->RNR = MPU_RNR_REGION_1;
  MPU->RBAR =  (0x20000000);
  MPU->RASR = (MPU_RASR_XN|MPU_RASR_AP_RW_RW|MPU_RASR_NORMAL_SHARED_MEM_WB|MPU_RASR_SIZE_128K|MPU_RASR_ENABLE);

  /* Setup CCMRAM region, CCMRAM base address start is at address 0x10000000 */
  MPU->RNR = MPU_RNR_REGION_2;
  MPU->RBAR =  (0x10000000);
  MPU->RASR = (MPU_RASR_XN|MPU_RASR_AP_RW_NA|MPU_RASR_NORMAL_SHARED_MEM_WB|MPU_RASR_SIZE_64K|MPU_RASR_ENABLE);

  /* Setup Peripheral region, Peripheral base address start is at address 0x40000000 */
  MPU->RNR = MPU_RNR_REGION_4;
  MPU->RBAR =  (0x40000000);
  MPU->RASR = (MPU_RASR_XN|MPU_RASR_AP_RW_NA|MPU_RASR_NORMAL_SHARED_DEVICE|MPU_RASR_SIZE_1G|MPU_RASR_ENABLE);

  /* Setup System Register region, base address start is at address 0xE0000000 */
  MPU->RNR = MPU_RNR_REGION_5;
  MPU->RBAR =  (0xE0000000);
  MPU->RASR = (MPU_RASR_XN|MPU_RASR_AP_RW_NA|MPU_RASR_NORMAL_SHARED_DEVICE|MPU_RASR_SIZE_256M|MPU_RASR_ENABLE);

  /* Disable Unused regions */
  MPU->RNR = MPU_RNR_REGION_3; /* Select which MPU region to configure */
  MPU->RBAR = 0;         /* Configure region base address register */
  MPU->RASR = 0;         /* Configure region attribute and size register */

  MPU->RNR = MPU_RNR_REGION_6;
  MPU->RBAR = 0;
  MPU->RASR = 0;

  MPU->RNR = MPU_RNR_REGION_7;
  MPU->RBAR = 0;
  MPU->RASR = 0;

  /* Enable Mem fault ISR */
  SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;


  /* Enable MPU */
  MPU->CTRL |= MPU_CTRL_ENABLE;

  /*/Memory barrier to ensure subsiquence data & instruction */
  __DSB();

  /* Transers using updated MPU settings */
  __ISB();

  return 0;
}

void mpu_task_stack_permit(void *start)
{
    /* Make sure MPU is disable while we change the base address */
    MPU->CTRL &= ~(MPU_CTRL_ENABLE);
    __DMB();

    /* Setup CCMRAM region, CCMRAM base address start is at address 0x10000000 */
    MPU->RNR = MPU_RNR_REGION_3;
    MPU->RBAR =  ((uint32_t)start);
    MPU->RASR = (MPU_RASR_AP_RW_RW|MPU_RASR_NORMAL_SHARED_MEM_WB|MPU_RASR_SIZE_1K|MPU_RASR_ENABLE);
    MPU->CTRL |= MPU_CTRL_ENABLE;
}

