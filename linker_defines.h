#ifndef LINKER_DEFINES
#define LINKER_DEFINES

#include "stdint.h"

/* Begin address for the initialization values of the .data section
 * defined in the linker script
 * https://stackoverflow.com/questions/8398755/access-symbols-defined-in-the-linker-script-by-application
*/


extern uint32_t _estack;


extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t _start_heap;
extern uint32_t _end_heap;

extern uint32_t _os_stack_start;
extern uint32_t _os_stack_stop;


#define FLASH_BASE            0x08000000U /*!< FLASH(up to 1 MB) base address in the alias region                         */
#define CCMDATARAM_BASE       0x10000000U /*!< CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE            0x20000000U /*!< SRAM1(112 KB) base address in the alias region                              */
#define SRAM2_BASE            0x2001C000U /*!< SRAM2(16 KB) base address in the alias region                              */
#define PERIPH_BASE           0x40000000U /*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE          0x40024000U /*!< Backup SRAM(4 KB) base address in the alias region                         */
#define FSMC_R_BASE           0xA0000000U /*!< FSMC registers base address                                                */
#define SRAM1_BB_BASE         0x22000000U /*!< SRAM1(112 KB) base address in the bit-band region                          */
#define SRAM2_BB_BASE         0x22380000U /*!< SRAM2(16 KB) base address in the bit-band region                           */
#define PERIPH_BB_BASE        0x42000000U /*!< Peripheral base address in the bit-band region                             */
#define BKPSRAM_BB_BASE       0x42480000U /*!< Backup SRAM(4 KB) base address in the bit-band region                      */
#define FLASH_END             0x080FFFFFU /*!< FLASH end address                                                          */
#define FLASH_OTP_BASE        0x1FFF7800U /*!< Base address of : (up to 528 Bytes) embedded FLASH OTP Area                */
#define FLASH_OTP_END         0x1FFF7A0FU /*!< End address of : (up to 528 Bytes) embedded FLASH OTP Area                 */
#define CCMDATARAM_END        0x1000FFFFU /*!< CCM data RAM end address                                                   */



  /* Work out end of RAM address as intial stack pointer, Use both
  * (specific of a given STM32 MCU)
  */
  #define SRAM_SIZE            128 * 1024 /* STM32F4O7 has 128 KB of RAM */
  #define SRAM_END             (SRAM1_BASE + SRAM_SIZE)

#endif
