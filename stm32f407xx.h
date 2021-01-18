#ifndef __STM32F407_H
#define __STM32F407_H
#include "stdint.h"
#include "gcc_arm.h"

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

/*@} end of group Cortex_M4 */


/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
  */
#define __CM4_REV                 0x0001U  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1U       /*!< STM32F4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4U       /*!< STM32F4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1U       /*!< FPU present                                   */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32F4XX Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare global interrupt                             */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
  FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                             */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
  ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
  OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
  OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
  DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
  HASH_RNG_IRQn               = 80,     /*!< Hash and Rng global interrupt                                     */
  FPU_IRQn                    = 81      /*!< FPU global interrupt                                               */
} IRQn_Type;




/**
  * @brief Power Control
  */

typedef struct
{
  volatile uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  volatile uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;


/**
  * @brief Reset and Clock Control
  */
typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} RCC_TypeDef;

/**
  * @brief FLASH Registers
  */

typedef struct
{
  volatile uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  volatile uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  volatile uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  volatile uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  volatile uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  volatile uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  volatile uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SysTick     System Tick Timer (SysTick)
  \brief    Type definitions for the System Timer Registers.
  @{
 */


/**
  \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;


/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_NVIC  Nested Vectored Interrupt Controller (NVIC)
  \brief      Type definitions for the NVIC Registers
  @{
 */

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  volatile uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;

/* Software Triggered Interrupt Register Definitions */
#define NVIC_STIR_INTID_Pos                 0U                                         /*!< STIR: INTLINESNUM Position */
#define NVIC_STIR_INTID_Msk                (0x1FFUL /*<< NVIC_STIR_INTID_Pos*/)        /*!< STIR: INTLINESNUM Mask */

/*@} end of group CMSIS_NVIC */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SCB     System Control Block (SCB)
  \brief    Type definitions for the System Control Block Registers
  @{
 */

/**
  \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  volatile const  uint32_t CPUID;        /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  volatile const  uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  volatile const  uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  volatile const  uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  volatile const  uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  volatile const  uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_Type;

/* Memory mapping of Cortex-M4 Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */

#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */

/* Peripheral_memory_map */
#define PERIPH_BASE           0x40000000U /*Peripheral base address in the alias region */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000U)

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00U)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000U)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000U)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800U)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00U)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000U)

/*!< APB1 peripherals */
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000U)

/* Peripheral_declaration */
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODE0_Pos             (0U)
#define GPIO_MODER_MODE0_Msk             (0x3U << GPIO_MODER_MODE0_Pos)        /*!< 0x00000003 */
#define GPIO_MODER_MODE0                 GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE0_0               (0x1U << GPIO_MODER_MODE0_Pos)        /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1               (0x2U << GPIO_MODER_MODE0_Pos)        /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos             (2U)
#define GPIO_MODER_MODE1_Msk             (0x3U << GPIO_MODER_MODE1_Pos)        /*!< 0x0000000C */
#define GPIO_MODER_MODE1                 GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE1_0               (0x1U << GPIO_MODER_MODE1_Pos)        /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1               (0x2U << GPIO_MODER_MODE1_Pos)        /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos             (4U)
#define GPIO_MODER_MODE2_Msk             (0x3U << GPIO_MODER_MODE2_Pos)        /*!< 0x00000030 */
#define GPIO_MODER_MODE2                 GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE2_0               (0x1U << GPIO_MODER_MODE2_Pos)        /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1               (0x2U << GPIO_MODER_MODE2_Pos)        /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos             (6U)
#define GPIO_MODER_MODE3_Msk             (0x3U << GPIO_MODER_MODE3_Pos)        /*!< 0x000000C0 */
#define GPIO_MODER_MODE3                 GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE3_0               (0x1U << GPIO_MODER_MODE3_Pos)        /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1               (0x2U << GPIO_MODER_MODE3_Pos)        /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos             (8U)
#define GPIO_MODER_MODE4_Msk             (0x3U << GPIO_MODER_MODE4_Pos)        /*!< 0x00000300 */
#define GPIO_MODER_MODE4                 GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE4_0               (0x1U << GPIO_MODER_MODE4_Pos)        /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1               (0x2U << GPIO_MODER_MODE4_Pos)        /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos             (10U)
#define GPIO_MODER_MODE5_Msk             (0x3U << GPIO_MODER_MODE5_Pos)        /*!< 0x00000C00 */
#define GPIO_MODER_MODE5                 GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE5_0               (0x1U << GPIO_MODER_MODE5_Pos)        /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1               (0x2U << GPIO_MODER_MODE5_Pos)        /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos             (12U)
#define GPIO_MODER_MODE6_Msk             (0x3U << GPIO_MODER_MODE6_Pos)        /*!< 0x00003000 */
#define GPIO_MODER_MODE6                 GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE6_0               (0x1U << GPIO_MODER_MODE6_Pos)        /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1               (0x2U << GPIO_MODER_MODE6_Pos)        /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos             (14U)
#define GPIO_MODER_MODE7_Msk             (0x3U << GPIO_MODER_MODE7_Pos)        /*!< 0x0000C000 */
#define GPIO_MODER_MODE7                 GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE7_0               (0x1U << GPIO_MODER_MODE7_Pos)        /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1               (0x2U << GPIO_MODER_MODE7_Pos)        /*!< 0x00008000 */
#define GPIO_MODER_MODE8_Pos             (16U)
#define GPIO_MODER_MODE8_Msk             (0x3U << GPIO_MODER_MODE8_Pos)        /*!< 0x00030000 */
#define GPIO_MODER_MODE8                 GPIO_MODER_MODE8_Msk
#define GPIO_MODER_MODE8_0               (0x1U << GPIO_MODER_MODE8_Pos)        /*!< 0x00010000 */
#define GPIO_MODER_MODE8_1               (0x2U << GPIO_MODER_MODE8_Pos)        /*!< 0x00020000 */
#define GPIO_MODER_MODE9_Pos             (18U)
#define GPIO_MODER_MODE9_Msk             (0x3U << GPIO_MODER_MODE9_Pos)        /*!< 0x000C0000 */
#define GPIO_MODER_MODE9                 GPIO_MODER_MODE9_Msk
#define GPIO_MODER_MODE9_0               (0x1U << GPIO_MODER_MODE9_Pos)        /*!< 0x00040000 */
#define GPIO_MODER_MODE9_1               (0x2U << GPIO_MODER_MODE9_Pos)        /*!< 0x00080000 */
#define GPIO_MODER_MODE10_Pos            (20U)
#define GPIO_MODER_MODE10_Msk            (0x3U << GPIO_MODER_MODE10_Pos)       /*!< 0x00300000 */
#define GPIO_MODER_MODE10                GPIO_MODER_MODE10_Msk
#define GPIO_MODER_MODE10_0              (0x1U << GPIO_MODER_MODE10_Pos)       /*!< 0x00100000 */
#define GPIO_MODER_MODE10_1              (0x2U << GPIO_MODER_MODE10_Pos)       /*!< 0x00200000 */
#define GPIO_MODER_MODE11_Pos            (22U)
#define GPIO_MODER_MODE11_Msk            (0x3U << GPIO_MODER_MODE11_Pos)       /*!< 0x00C00000 */
#define GPIO_MODER_MODE11                GPIO_MODER_MODE11_Msk
#define GPIO_MODER_MODE11_0              (0x1U << GPIO_MODER_MODE11_Pos)       /*!< 0x00400000 */
#define GPIO_MODER_MODE11_1              (0x2U << GPIO_MODER_MODE11_Pos)       /*!< 0x00800000 */
#define GPIO_MODER_MODE12_Pos            (24U)
#define GPIO_MODER_MODE12_Msk            (0x3U << GPIO_MODER_MODE12_Pos)       /*!< 0x03000000 */
#define GPIO_MODER_MODE12                GPIO_MODER_MODE12_Msk
#define GPIO_MODER_MODE12_0              (0x1U << GPIO_MODER_MODE12_Pos)       /*!< 0x01000000 */
#define GPIO_MODER_MODE12_1              (0x2U << GPIO_MODER_MODE12_Pos)       /*!< 0x02000000 */
#define GPIO_MODER_MODE13_Pos            (26U)
#define GPIO_MODER_MODE13_Msk            (0x3U << GPIO_MODER_MODE13_Pos)       /*!< 0x0C000000 */
#define GPIO_MODER_MODE13                GPIO_MODER_MODE13_Msk
#define GPIO_MODER_MODE13_0              (0x1U << GPIO_MODER_MODE13_Pos)       /*!< 0x04000000 */
#define GPIO_MODER_MODE13_1              (0x2U << GPIO_MODER_MODE13_Pos)       /*!< 0x08000000 */
#define GPIO_MODER_MODE14_Pos            (28U)
#define GPIO_MODER_MODE14_Msk            (0x3U << GPIO_MODER_MODE14_Pos)       /*!< 0x30000000 */
#define GPIO_MODER_MODE14                GPIO_MODER_MODE14_Msk
#define GPIO_MODER_MODE14_0              (0x1U << GPIO_MODER_MODE14_Pos)       /*!< 0x10000000 */
#define GPIO_MODER_MODE14_1              (0x2U << GPIO_MODER_MODE14_Pos)       /*!< 0x20000000 */
#define GPIO_MODER_MODE15_Pos            (30U)
#define GPIO_MODER_MODE15_Msk            (0x3U << GPIO_MODER_MODE15_Pos)       /*!< 0xC0000000 */
#define GPIO_MODER_MODE15                GPIO_MODER_MODE15_Msk
#define GPIO_MODER_MODE15_0              (0x1U << GPIO_MODER_MODE15_Pos)       /*!< 0x40000000 */
#define GPIO_MODER_MODE15_1              (0x2U << GPIO_MODER_MODE15_Pos)       /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_MODER_MODER0_Pos            (0U)
#define GPIO_MODER_MODER0_Msk            (0x3U << GPIO_MODER_MODER0_Pos)       /*!< 0x00000003 */
#define GPIO_MODER_MODER0                GPIO_MODER_MODER0_Msk
#define GPIO_MODER_MODER0_0              (0x1U << GPIO_MODER_MODER0_Pos)       /*!< 0x00000001 */
#define GPIO_MODER_MODER0_1              (0x2U << GPIO_MODER_MODER0_Pos)       /*!< 0x00000002 */
#define GPIO_MODER_MODER1_Pos            (2U)
#define GPIO_MODER_MODER1_Msk            (0x3U << GPIO_MODER_MODER1_Pos)       /*!< 0x0000000C */
#define GPIO_MODER_MODER1                GPIO_MODER_MODER1_Msk
#define GPIO_MODER_MODER1_0              (0x1U << GPIO_MODER_MODER1_Pos)       /*!< 0x00000004 */
#define GPIO_MODER_MODER1_1              (0x2U << GPIO_MODER_MODER1_Pos)       /*!< 0x00000008 */
#define GPIO_MODER_MODER2_Pos            (4U)
#define GPIO_MODER_MODER2_Msk            (0x3U << GPIO_MODER_MODER2_Pos)       /*!< 0x00000030 */
#define GPIO_MODER_MODER2                GPIO_MODER_MODER2_Msk
#define GPIO_MODER_MODER2_0              (0x1U << GPIO_MODER_MODER2_Pos)       /*!< 0x00000010 */
#define GPIO_MODER_MODER2_1              (0x2U << GPIO_MODER_MODER2_Pos)       /*!< 0x00000020 */
#define GPIO_MODER_MODER3_Pos            (6U)
#define GPIO_MODER_MODER3_Msk            (0x3U << GPIO_MODER_MODER3_Pos)       /*!< 0x000000C0 */
#define GPIO_MODER_MODER3                GPIO_MODER_MODER3_Msk
#define GPIO_MODER_MODER3_0              (0x1U << GPIO_MODER_MODER3_Pos)       /*!< 0x00000040 */
#define GPIO_MODER_MODER3_1              (0x2U << GPIO_MODER_MODER3_Pos)       /*!< 0x00000080 */
#define GPIO_MODER_MODER4_Pos            (8U)
#define GPIO_MODER_MODER4_Msk            (0x3U << GPIO_MODER_MODER4_Pos)       /*!< 0x00000300 */
#define GPIO_MODER_MODER4                GPIO_MODER_MODER4_Msk
#define GPIO_MODER_MODER4_0              (0x1U << GPIO_MODER_MODER4_Pos)       /*!< 0x00000100 */
#define GPIO_MODER_MODER4_1              (0x2U << GPIO_MODER_MODER4_Pos)       /*!< 0x00000200 */
#define GPIO_MODER_MODER5_Pos            (10U)
#define GPIO_MODER_MODER5_Msk            (0x3U << GPIO_MODER_MODER5_Pos)       /*!< 0x00000C00 */
#define GPIO_MODER_MODER5                GPIO_MODER_MODER5_Msk
#define GPIO_MODER_MODER5_0              (0x1U << GPIO_MODER_MODER5_Pos)       /*!< 0x00000400 */
#define GPIO_MODER_MODER5_1              (0x2U << GPIO_MODER_MODER5_Pos)       /*!< 0x00000800 */
#define GPIO_MODER_MODER6_Pos            (12U)
#define GPIO_MODER_MODER6_Msk            (0x3U << GPIO_MODER_MODER6_Pos)       /*!< 0x00003000 */
#define GPIO_MODER_MODER6                GPIO_MODER_MODER6_Msk
#define GPIO_MODER_MODER6_0              (0x1U << GPIO_MODER_MODER6_Pos)       /*!< 0x00001000 */
#define GPIO_MODER_MODER6_1              (0x2U << GPIO_MODER_MODER6_Pos)       /*!< 0x00002000 */
#define GPIO_MODER_MODER7_Pos            (14U)
#define GPIO_MODER_MODER7_Msk            (0x3U << GPIO_MODER_MODER7_Pos)       /*!< 0x0000C000 */
#define GPIO_MODER_MODER7                GPIO_MODER_MODER7_Msk
#define GPIO_MODER_MODER7_0              (0x1U << GPIO_MODER_MODER7_Pos)       /*!< 0x00004000 */
#define GPIO_MODER_MODER7_1              (0x2U << GPIO_MODER_MODER7_Pos)       /*!< 0x00008000 */
#define GPIO_MODER_MODER8_Pos            (16U)
#define GPIO_MODER_MODER8_Msk            (0x3U << GPIO_MODER_MODER8_Pos)       /*!< 0x00030000 */
#define GPIO_MODER_MODER8                GPIO_MODER_MODER8_Msk
#define GPIO_MODER_MODER8_0              (0x1U << GPIO_MODER_MODER8_Pos)       /*!< 0x00010000 */
#define GPIO_MODER_MODER8_1              (0x2U << GPIO_MODER_MODER8_Pos)       /*!< 0x00020000 */
#define GPIO_MODER_MODER9_Pos            (18U)
#define GPIO_MODER_MODER9_Msk            (0x3U << GPIO_MODER_MODER9_Pos)       /*!< 0x000C0000 */
#define GPIO_MODER_MODER9                GPIO_MODER_MODER9_Msk
#define GPIO_MODER_MODER9_0              (0x1U << GPIO_MODER_MODER9_Pos)       /*!< 0x00040000 */
#define GPIO_MODER_MODER9_1              (0x2U << GPIO_MODER_MODER9_Pos)       /*!< 0x00080000 */
#define GPIO_MODER_MODER10_Pos           (20U)
#define GPIO_MODER_MODER10_Msk           (0x3U << GPIO_MODER_MODER10_Pos)      /*!< 0x00300000 */
#define GPIO_MODER_MODER10               GPIO_MODER_MODER10_Msk
#define GPIO_MODER_MODER10_0             (0x1U << GPIO_MODER_MODER10_Pos)      /*!< 0x00100000 */
#define GPIO_MODER_MODER10_1             (0x2U << GPIO_MODER_MODER10_Pos)      /*!< 0x00200000 */
#define GPIO_MODER_MODER11_Pos           (22U)
#define GPIO_MODER_MODER11_Msk           (0x3U << GPIO_MODER_MODER11_Pos)      /*!< 0x00C00000 */
#define GPIO_MODER_MODER11               GPIO_MODER_MODER11_Msk
#define GPIO_MODER_MODER11_0             (0x1U << GPIO_MODER_MODER11_Pos)      /*!< 0x00400000 */
#define GPIO_MODER_MODER11_1             (0x2U << GPIO_MODER_MODER11_Pos)      /*!< 0x00800000 */
#define GPIO_MODER_MODER12_Pos           (24U)
#define GPIO_MODER_MODER12_Msk           (0x3U << GPIO_MODER_MODER12_Pos)      /*!< 0x03000000 */
#define GPIO_MODER_MODER12               GPIO_MODER_MODER12_Msk
#define GPIO_MODER_MODER12_0             (0x1U << GPIO_MODER_MODER12_Pos)      /*!< 0x01000000 */
#define GPIO_MODER_MODER12_1             (0x2U << GPIO_MODER_MODER12_Pos)      /*!< 0x02000000 */
#define GPIO_MODER_MODER13_Pos           (26U)
#define GPIO_MODER_MODER13_Msk           (0x3U << GPIO_MODER_MODER13_Pos)      /*!< 0x0C000000 */
#define GPIO_MODER_MODER13               GPIO_MODER_MODER13_Msk
#define GPIO_MODER_MODER13_0             (0x1U << GPIO_MODER_MODER13_Pos)      /*!< 0x04000000 */
#define GPIO_MODER_MODER13_1             (0x2U << GPIO_MODER_MODER13_Pos)      /*!< 0x08000000 */
#define GPIO_MODER_MODER14_Pos           (28U)
#define GPIO_MODER_MODER14_Msk           (0x3U << GPIO_MODER_MODER14_Pos)      /*!< 0x30000000 */
#define GPIO_MODER_MODER14               GPIO_MODER_MODER14_Msk
#define GPIO_MODER_MODER14_0             (0x1U << GPIO_MODER_MODER14_Pos)      /*!< 0x10000000 */
#define GPIO_MODER_MODER14_1             (0x2U << GPIO_MODER_MODER14_Pos)      /*!< 0x20000000 */
#define GPIO_MODER_MODER15_Pos           (30U)
#define GPIO_MODER_MODER15_Msk           (0x3U << GPIO_MODER_MODER15_Pos)      /*!< 0xC0000000 */
#define GPIO_MODER_MODER15               GPIO_MODER_MODER15_Msk
#define GPIO_MODER_MODER15_0             (0x1U << GPIO_MODER_MODER15_Pos)      /*!< 0x40000000 */
#define GPIO_MODER_MODER15_1             (0x2U << GPIO_MODER_MODER15_Pos)      /*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT0_Pos              (0U)
#define GPIO_OTYPER_OT0_Msk              (0x1U << GPIO_OTYPER_OT0_Pos)         /*!< 0x00000001 */
#define GPIO_OTYPER_OT0                  GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos              (1U)
#define GPIO_OTYPER_OT1_Msk              (0x1U << GPIO_OTYPER_OT1_Pos)         /*!< 0x00000002 */
#define GPIO_OTYPER_OT1                  GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos              (2U)
#define GPIO_OTYPER_OT2_Msk              (0x1U << GPIO_OTYPER_OT2_Pos)         /*!< 0x00000004 */
#define GPIO_OTYPER_OT2                  GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos              (3U)
#define GPIO_OTYPER_OT3_Msk              (0x1U << GPIO_OTYPER_OT3_Pos)         /*!< 0x00000008 */
#define GPIO_OTYPER_OT3                  GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos              (4U)
#define GPIO_OTYPER_OT4_Msk              (0x1U << GPIO_OTYPER_OT4_Pos)         /*!< 0x00000010 */
#define GPIO_OTYPER_OT4                  GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos              (5U)
#define GPIO_OTYPER_OT5_Msk              (0x1U << GPIO_OTYPER_OT5_Pos)         /*!< 0x00000020 */
#define GPIO_OTYPER_OT5                  GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos              (6U)
#define GPIO_OTYPER_OT6_Msk              (0x1U << GPIO_OTYPER_OT6_Pos)         /*!< 0x00000040 */
#define GPIO_OTYPER_OT6                  GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos              (7U)
#define GPIO_OTYPER_OT7_Msk              (0x1U << GPIO_OTYPER_OT7_Pos)         /*!< 0x00000080 */
#define GPIO_OTYPER_OT7                  GPIO_OTYPER_OT7_Msk
#define GPIO_OTYPER_OT8_Pos              (8U)
#define GPIO_OTYPER_OT8_Msk              (0x1U << GPIO_OTYPER_OT8_Pos)         /*!< 0x00000100 */
#define GPIO_OTYPER_OT8                  GPIO_OTYPER_OT8_Msk
#define GPIO_OTYPER_OT9_Pos              (9U)
#define GPIO_OTYPER_OT9_Msk              (0x1U << GPIO_OTYPER_OT9_Pos)         /*!< 0x00000200 */
#define GPIO_OTYPER_OT9                  GPIO_OTYPER_OT9_Msk
#define GPIO_OTYPER_OT10_Pos             (10U)
#define GPIO_OTYPER_OT10_Msk             (0x1U << GPIO_OTYPER_OT10_Pos)        /*!< 0x00000400 */
#define GPIO_OTYPER_OT10                 GPIO_OTYPER_OT10_Msk
#define GPIO_OTYPER_OT11_Pos             (11U)
#define GPIO_OTYPER_OT11_Msk             (0x1U << GPIO_OTYPER_OT11_Pos)        /*!< 0x00000800 */
#define GPIO_OTYPER_OT11                 GPIO_OTYPER_OT11_Msk
#define GPIO_OTYPER_OT12_Pos             (12U)
#define GPIO_OTYPER_OT12_Msk             (0x1U << GPIO_OTYPER_OT12_Pos)        /*!< 0x00001000 */
#define GPIO_OTYPER_OT12                 GPIO_OTYPER_OT12_Msk
#define GPIO_OTYPER_OT13_Pos             (13U)
#define GPIO_OTYPER_OT13_Msk             (0x1U << GPIO_OTYPER_OT13_Pos)        /*!< 0x00002000 */
#define GPIO_OTYPER_OT13                 GPIO_OTYPER_OT13_Msk
#define GPIO_OTYPER_OT14_Pos             (14U)
#define GPIO_OTYPER_OT14_Msk             (0x1U << GPIO_OTYPER_OT14_Pos)        /*!< 0x00004000 */
#define GPIO_OTYPER_OT14                 GPIO_OTYPER_OT14_Msk
#define GPIO_OTYPER_OT15_Pos             (15U)
#define GPIO_OTYPER_OT15_Msk             (0x1U << GPIO_OTYPER_OT15_Pos)        /*!< 0x00008000 */
#define GPIO_OTYPER_OT15                 GPIO_OTYPER_OT15_Msk

/* Legacy defines */
#define GPIO_OTYPER_OT_0                    GPIO_OTYPER_OT0
#define GPIO_OTYPER_OT_1                    GPIO_OTYPER_OT1
#define GPIO_OTYPER_OT_2                    GPIO_OTYPER_OT2
#define GPIO_OTYPER_OT_3                    GPIO_OTYPER_OT3
#define GPIO_OTYPER_OT_4                    GPIO_OTYPER_OT4
#define GPIO_OTYPER_OT_5                    GPIO_OTYPER_OT5
#define GPIO_OTYPER_OT_6                    GPIO_OTYPER_OT6
#define GPIO_OTYPER_OT_7                    GPIO_OTYPER_OT7
#define GPIO_OTYPER_OT_8                    GPIO_OTYPER_OT8
#define GPIO_OTYPER_OT_9                    GPIO_OTYPER_OT9
#define GPIO_OTYPER_OT_10                   GPIO_OTYPER_OT10
#define GPIO_OTYPER_OT_11                   GPIO_OTYPER_OT11
#define GPIO_OTYPER_OT_12                   GPIO_OTYPER_OT12
#define GPIO_OTYPER_OT_13                   GPIO_OTYPER_OT13
#define GPIO_OTYPER_OT_14                   GPIO_OTYPER_OT14
#define GPIO_OTYPER_OT_15                   GPIO_OTYPER_OT15

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDR_OSPEED0_Pos         (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk         (0x3U << GPIO_OSPEEDR_OSPEED0_Pos)    /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0             GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_0           (0x1U << GPIO_OSPEEDR_OSPEED0_Pos)    /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1           (0x2U << GPIO_OSPEEDR_OSPEED0_Pos)    /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos         (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk         (0x3U << GPIO_OSPEEDR_OSPEED1_Pos)    /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1             GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_0           (0x1U << GPIO_OSPEEDR_OSPEED1_Pos)    /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1           (0x2U << GPIO_OSPEEDR_OSPEED1_Pos)    /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos         (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk         (0x3U << GPIO_OSPEEDR_OSPEED2_Pos)    /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2             GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_0           (0x1U << GPIO_OSPEEDR_OSPEED2_Pos)    /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1           (0x2U << GPIO_OSPEEDR_OSPEED2_Pos)    /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos         (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk         (0x3U << GPIO_OSPEEDR_OSPEED3_Pos)    /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3             GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_0           (0x1U << GPIO_OSPEEDR_OSPEED3_Pos)    /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1           (0x2U << GPIO_OSPEEDR_OSPEED3_Pos)    /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos         (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk         (0x3U << GPIO_OSPEEDR_OSPEED4_Pos)    /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4             GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_0           (0x1U << GPIO_OSPEEDR_OSPEED4_Pos)    /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1           (0x2U << GPIO_OSPEEDR_OSPEED4_Pos)    /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos         (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk         (0x3U << GPIO_OSPEEDR_OSPEED5_Pos)    /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5             GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_0           (0x1U << GPIO_OSPEEDR_OSPEED5_Pos)    /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1           (0x2U << GPIO_OSPEEDR_OSPEED5_Pos)    /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos         (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk         (0x3U << GPIO_OSPEEDR_OSPEED6_Pos)    /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6             GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_0           (0x1U << GPIO_OSPEEDR_OSPEED6_Pos)    /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1           (0x2U << GPIO_OSPEEDR_OSPEED6_Pos)    /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos         (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk         (0x3U << GPIO_OSPEEDR_OSPEED7_Pos)    /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7             GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_0           (0x1U << GPIO_OSPEEDR_OSPEED7_Pos)    /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1           (0x2U << GPIO_OSPEEDR_OSPEED7_Pos)    /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEED8_Pos         (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk         (0x3U << GPIO_OSPEEDR_OSPEED8_Pos)    /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEED8             GPIO_OSPEEDR_OSPEED8_Msk
#define GPIO_OSPEEDR_OSPEED8_0           (0x1U << GPIO_OSPEEDR_OSPEED8_Pos)    /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEED8_1           (0x2U << GPIO_OSPEEDR_OSPEED8_Pos)    /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEED9_Pos         (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk         (0x3U << GPIO_OSPEEDR_OSPEED9_Pos)    /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEED9             GPIO_OSPEEDR_OSPEED9_Msk
#define GPIO_OSPEEDR_OSPEED9_0           (0x1U << GPIO_OSPEEDR_OSPEED9_Pos)    /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEED9_1           (0x2U << GPIO_OSPEEDR_OSPEED9_Pos)    /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEED10_Pos        (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk        (0x3U << GPIO_OSPEEDR_OSPEED10_Pos)   /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEED10            GPIO_OSPEEDR_OSPEED10_Msk
#define GPIO_OSPEEDR_OSPEED10_0          (0x1U << GPIO_OSPEEDR_OSPEED10_Pos)   /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEED10_1          (0x2U << GPIO_OSPEEDR_OSPEED10_Pos)   /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEED11_Pos        (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk        (0x3U << GPIO_OSPEEDR_OSPEED11_Pos)   /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEED11            GPIO_OSPEEDR_OSPEED11_Msk
#define GPIO_OSPEEDR_OSPEED11_0          (0x1U << GPIO_OSPEEDR_OSPEED11_Pos)   /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEED11_1          (0x2U << GPIO_OSPEEDR_OSPEED11_Pos)   /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEED12_Pos        (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk        (0x3U << GPIO_OSPEEDR_OSPEED12_Pos)   /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEED12            GPIO_OSPEEDR_OSPEED12_Msk
#define GPIO_OSPEEDR_OSPEED12_0          (0x1U << GPIO_OSPEEDR_OSPEED12_Pos)   /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEED12_1          (0x2U << GPIO_OSPEEDR_OSPEED12_Pos)   /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEED13_Pos        (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk        (0x3U << GPIO_OSPEEDR_OSPEED13_Pos)   /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEED13            GPIO_OSPEEDR_OSPEED13_Msk
#define GPIO_OSPEEDR_OSPEED13_0          (0x1U << GPIO_OSPEEDR_OSPEED13_Pos)   /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEED13_1          (0x2U << GPIO_OSPEEDR_OSPEED13_Pos)   /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEED14_Pos        (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk        (0x3U << GPIO_OSPEEDR_OSPEED14_Pos)   /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEED14            GPIO_OSPEEDR_OSPEED14_Msk
#define GPIO_OSPEEDR_OSPEED14_0          (0x1U << GPIO_OSPEEDR_OSPEED14_Pos)   /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEED14_1          (0x2U << GPIO_OSPEEDR_OSPEED14_Pos)   /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEED15_Pos        (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk        (0x3U << GPIO_OSPEEDR_OSPEED15_Pos)   /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEED15            GPIO_OSPEEDR_OSPEED15_Msk
#define GPIO_OSPEEDR_OSPEED15_0          (0x1U << GPIO_OSPEEDR_OSPEED15_Pos)   /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEED15_1          (0x2U << GPIO_OSPEEDR_OSPEED15_Pos)   /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_OSPEEDER_OSPEEDR0              GPIO_OSPEEDR_OSPEED0
#define GPIO_OSPEEDER_OSPEEDR0_0            GPIO_OSPEEDR_OSPEED0_0
#define GPIO_OSPEEDER_OSPEEDR0_1            GPIO_OSPEEDR_OSPEED0_1
#define GPIO_OSPEEDER_OSPEEDR1              GPIO_OSPEEDR_OSPEED1
#define GPIO_OSPEEDER_OSPEEDR1_0            GPIO_OSPEEDR_OSPEED1_0
#define GPIO_OSPEEDER_OSPEEDR1_1            GPIO_OSPEEDR_OSPEED1_1
#define GPIO_OSPEEDER_OSPEEDR2              GPIO_OSPEEDR_OSPEED2
#define GPIO_OSPEEDER_OSPEEDR2_0            GPIO_OSPEEDR_OSPEED2_0
#define GPIO_OSPEEDER_OSPEEDR2_1            GPIO_OSPEEDR_OSPEED2_1
#define GPIO_OSPEEDER_OSPEEDR3              GPIO_OSPEEDR_OSPEED3
#define GPIO_OSPEEDER_OSPEEDR3_0            GPIO_OSPEEDR_OSPEED3_0
#define GPIO_OSPEEDER_OSPEEDR3_1            GPIO_OSPEEDR_OSPEED3_1
#define GPIO_OSPEEDER_OSPEEDR4              GPIO_OSPEEDR_OSPEED4
#define GPIO_OSPEEDER_OSPEEDR4_0            GPIO_OSPEEDR_OSPEED4_0
#define GPIO_OSPEEDER_OSPEEDR4_1            GPIO_OSPEEDR_OSPEED4_1
#define GPIO_OSPEEDER_OSPEEDR5              GPIO_OSPEEDR_OSPEED5
#define GPIO_OSPEEDER_OSPEEDR5_0            GPIO_OSPEEDR_OSPEED5_0
#define GPIO_OSPEEDER_OSPEEDR5_1            GPIO_OSPEEDR_OSPEED5_1
#define GPIO_OSPEEDER_OSPEEDR6              GPIO_OSPEEDR_OSPEED6
#define GPIO_OSPEEDER_OSPEEDR6_0            GPIO_OSPEEDR_OSPEED6_0
#define GPIO_OSPEEDER_OSPEEDR6_1            GPIO_OSPEEDR_OSPEED6_1
#define GPIO_OSPEEDER_OSPEEDR7              GPIO_OSPEEDR_OSPEED7
#define GPIO_OSPEEDER_OSPEEDR7_0            GPIO_OSPEEDR_OSPEED7_0
#define GPIO_OSPEEDER_OSPEEDR7_1            GPIO_OSPEEDR_OSPEED7_1
#define GPIO_OSPEEDER_OSPEEDR8              GPIO_OSPEEDR_OSPEED8
#define GPIO_OSPEEDER_OSPEEDR8_0            GPIO_OSPEEDR_OSPEED8_0
#define GPIO_OSPEEDER_OSPEEDR8_1            GPIO_OSPEEDR_OSPEED8_1
#define GPIO_OSPEEDER_OSPEEDR9              GPIO_OSPEEDR_OSPEED9
#define GPIO_OSPEEDER_OSPEEDR9_0            GPIO_OSPEEDR_OSPEED9_0
#define GPIO_OSPEEDER_OSPEEDR9_1            GPIO_OSPEEDR_OSPEED9_1
#define GPIO_OSPEEDER_OSPEEDR10             GPIO_OSPEEDR_OSPEED10
#define GPIO_OSPEEDER_OSPEEDR10_0           GPIO_OSPEEDR_OSPEED10_0
#define GPIO_OSPEEDER_OSPEEDR10_1           GPIO_OSPEEDR_OSPEED10_1
#define GPIO_OSPEEDER_OSPEEDR11             GPIO_OSPEEDR_OSPEED11
#define GPIO_OSPEEDER_OSPEEDR11_0           GPIO_OSPEEDR_OSPEED11_0
#define GPIO_OSPEEDER_OSPEEDR11_1           GPIO_OSPEEDR_OSPEED11_1
#define GPIO_OSPEEDER_OSPEEDR12             GPIO_OSPEEDR_OSPEED12
#define GPIO_OSPEEDER_OSPEEDR12_0           GPIO_OSPEEDR_OSPEED12_0
#define GPIO_OSPEEDER_OSPEEDR12_1           GPIO_OSPEEDR_OSPEED12_1
#define GPIO_OSPEEDER_OSPEEDR13             GPIO_OSPEEDR_OSPEED13
#define GPIO_OSPEEDER_OSPEEDR13_0           GPIO_OSPEEDR_OSPEED13_0
#define GPIO_OSPEEDER_OSPEEDR13_1           GPIO_OSPEEDR_OSPEED13_1
#define GPIO_OSPEEDER_OSPEEDR14             GPIO_OSPEEDR_OSPEED14
#define GPIO_OSPEEDER_OSPEEDR14_0           GPIO_OSPEEDR_OSPEED14_0
#define GPIO_OSPEEDER_OSPEEDR14_1           GPIO_OSPEEDR_OSPEED14_1
#define GPIO_OSPEEDER_OSPEEDR15             GPIO_OSPEEDR_OSPEED15
#define GPIO_OSPEEDER_OSPEEDR15_0           GPIO_OSPEEDR_OSPEED15_0
#define GPIO_OSPEEDER_OSPEEDR15_1           GPIO_OSPEEDR_OSPEED15_1

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPD0_Pos             (0U)
#define GPIO_PUPDR_PUPD0_Msk             (0x3U << GPIO_PUPDR_PUPD0_Pos)        /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0                 GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_0               (0x1U << GPIO_PUPDR_PUPD0_Pos)        /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1               (0x2U << GPIO_PUPDR_PUPD0_Pos)        /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos             (2U)
#define GPIO_PUPDR_PUPD1_Msk             (0x3U << GPIO_PUPDR_PUPD1_Pos)        /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1                 GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_0               (0x1U << GPIO_PUPDR_PUPD1_Pos)        /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1               (0x2U << GPIO_PUPDR_PUPD1_Pos)        /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos             (4U)
#define GPIO_PUPDR_PUPD2_Msk             (0x3U << GPIO_PUPDR_PUPD2_Pos)        /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2                 GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_0               (0x1U << GPIO_PUPDR_PUPD2_Pos)        /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1               (0x2U << GPIO_PUPDR_PUPD2_Pos)        /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos             (6U)
#define GPIO_PUPDR_PUPD3_Msk             (0x3U << GPIO_PUPDR_PUPD3_Pos)        /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3                 GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_0               (0x1U << GPIO_PUPDR_PUPD3_Pos)        /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1               (0x2U << GPIO_PUPDR_PUPD3_Pos)        /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos             (8U)
#define GPIO_PUPDR_PUPD4_Msk             (0x3U << GPIO_PUPDR_PUPD4_Pos)        /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4                 GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_0               (0x1U << GPIO_PUPDR_PUPD4_Pos)        /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1               (0x2U << GPIO_PUPDR_PUPD4_Pos)        /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos             (10U)
#define GPIO_PUPDR_PUPD5_Msk             (0x3U << GPIO_PUPDR_PUPD5_Pos)        /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5                 GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_0               (0x1U << GPIO_PUPDR_PUPD5_Pos)        /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1               (0x2U << GPIO_PUPDR_PUPD5_Pos)        /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos             (12U)
#define GPIO_PUPDR_PUPD6_Msk             (0x3U << GPIO_PUPDR_PUPD6_Pos)        /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6                 GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_0               (0x1U << GPIO_PUPDR_PUPD6_Pos)        /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1               (0x2U << GPIO_PUPDR_PUPD6_Pos)        /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos             (14U)
#define GPIO_PUPDR_PUPD7_Msk             (0x3U << GPIO_PUPDR_PUPD7_Pos)        /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7                 GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_0               (0x1U << GPIO_PUPDR_PUPD7_Pos)        /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1               (0x2U << GPIO_PUPDR_PUPD7_Pos)        /*!< 0x00008000 */
#define GPIO_PUPDR_PUPD8_Pos             (16U)
#define GPIO_PUPDR_PUPD8_Msk             (0x3U << GPIO_PUPDR_PUPD8_Pos)        /*!< 0x00030000 */
#define GPIO_PUPDR_PUPD8                 GPIO_PUPDR_PUPD8_Msk
#define GPIO_PUPDR_PUPD8_0               (0x1U << GPIO_PUPDR_PUPD8_Pos)        /*!< 0x00010000 */
#define GPIO_PUPDR_PUPD8_1               (0x2U << GPIO_PUPDR_PUPD8_Pos)        /*!< 0x00020000 */
#define GPIO_PUPDR_PUPD9_Pos             (18U)
#define GPIO_PUPDR_PUPD9_Msk             (0x3U << GPIO_PUPDR_PUPD9_Pos)        /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPD9                 GPIO_PUPDR_PUPD9_Msk
#define GPIO_PUPDR_PUPD9_0               (0x1U << GPIO_PUPDR_PUPD9_Pos)        /*!< 0x00040000 */
#define GPIO_PUPDR_PUPD9_1               (0x2U << GPIO_PUPDR_PUPD9_Pos)        /*!< 0x00080000 */
#define GPIO_PUPDR_PUPD10_Pos            (20U)
#define GPIO_PUPDR_PUPD10_Msk            (0x3U << GPIO_PUPDR_PUPD10_Pos)       /*!< 0x00300000 */
#define GPIO_PUPDR_PUPD10                GPIO_PUPDR_PUPD10_Msk
#define GPIO_PUPDR_PUPD10_0              (0x1U << GPIO_PUPDR_PUPD10_Pos)       /*!< 0x00100000 */
#define GPIO_PUPDR_PUPD10_1              (0x2U << GPIO_PUPDR_PUPD10_Pos)       /*!< 0x00200000 */
#define GPIO_PUPDR_PUPD11_Pos            (22U)
#define GPIO_PUPDR_PUPD11_Msk            (0x3U << GPIO_PUPDR_PUPD11_Pos)       /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPD11                GPIO_PUPDR_PUPD11_Msk
#define GPIO_PUPDR_PUPD11_0              (0x1U << GPIO_PUPDR_PUPD11_Pos)       /*!< 0x00400000 */
#define GPIO_PUPDR_PUPD11_1              (0x2U << GPIO_PUPDR_PUPD11_Pos)       /*!< 0x00800000 */
#define GPIO_PUPDR_PUPD12_Pos            (24U)
#define GPIO_PUPDR_PUPD12_Msk            (0x3U << GPIO_PUPDR_PUPD12_Pos)       /*!< 0x03000000 */
#define GPIO_PUPDR_PUPD12                GPIO_PUPDR_PUPD12_Msk
#define GPIO_PUPDR_PUPD12_0              (0x1U << GPIO_PUPDR_PUPD12_Pos)       /*!< 0x01000000 */
#define GPIO_PUPDR_PUPD12_1              (0x2U << GPIO_PUPDR_PUPD12_Pos)       /*!< 0x02000000 */
#define GPIO_PUPDR_PUPD13_Pos            (26U)
#define GPIO_PUPDR_PUPD13_Msk            (0x3U << GPIO_PUPDR_PUPD13_Pos)       /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPD13                GPIO_PUPDR_PUPD13_Msk
#define GPIO_PUPDR_PUPD13_0              (0x1U << GPIO_PUPDR_PUPD13_Pos)       /*!< 0x04000000 */
#define GPIO_PUPDR_PUPD13_1              (0x2U << GPIO_PUPDR_PUPD13_Pos)       /*!< 0x08000000 */
#define GPIO_PUPDR_PUPD14_Pos            (28U)
#define GPIO_PUPDR_PUPD14_Msk            (0x3U << GPIO_PUPDR_PUPD14_Pos)       /*!< 0x30000000 */
#define GPIO_PUPDR_PUPD14                GPIO_PUPDR_PUPD14_Msk
#define GPIO_PUPDR_PUPD14_0              (0x1U << GPIO_PUPDR_PUPD14_Pos)       /*!< 0x10000000 */
#define GPIO_PUPDR_PUPD14_1              (0x2U << GPIO_PUPDR_PUPD14_Pos)       /*!< 0x20000000 */
#define GPIO_PUPDR_PUPD15_Pos            (30U)
#define GPIO_PUPDR_PUPD15_Msk            (0x3U << GPIO_PUPDR_PUPD15_Pos)       /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPD15                GPIO_PUPDR_PUPD15_Msk
#define GPIO_PUPDR_PUPD15_0              (0x1U << GPIO_PUPDR_PUPD15_Pos)       /*!< 0x40000000 */
#define GPIO_PUPDR_PUPD15_1              (0x2U << GPIO_PUPDR_PUPD15_Pos)       /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_PUPDR_PUPDR0                   GPIO_PUPDR_PUPD0
#define GPIO_PUPDR_PUPDR0_0                 GPIO_PUPDR_PUPD0_0
#define GPIO_PUPDR_PUPDR0_1                 GPIO_PUPDR_PUPD0_1
#define GPIO_PUPDR_PUPDR1                   GPIO_PUPDR_PUPD1
#define GPIO_PUPDR_PUPDR1_0                 GPIO_PUPDR_PUPD1_0
#define GPIO_PUPDR_PUPDR1_1                 GPIO_PUPDR_PUPD1_1
#define GPIO_PUPDR_PUPDR2                   GPIO_PUPDR_PUPD2
#define GPIO_PUPDR_PUPDR2_0                 GPIO_PUPDR_PUPD2_0
#define GPIO_PUPDR_PUPDR2_1                 GPIO_PUPDR_PUPD2_1
#define GPIO_PUPDR_PUPDR3                   GPIO_PUPDR_PUPD3
#define GPIO_PUPDR_PUPDR3_0                 GPIO_PUPDR_PUPD3_0
#define GPIO_PUPDR_PUPDR3_1                 GPIO_PUPDR_PUPD3_1
#define GPIO_PUPDR_PUPDR4                   GPIO_PUPDR_PUPD4
#define GPIO_PUPDR_PUPDR4_0                 GPIO_PUPDR_PUPD4_0
#define GPIO_PUPDR_PUPDR4_1                 GPIO_PUPDR_PUPD4_1
#define GPIO_PUPDR_PUPDR5                   GPIO_PUPDR_PUPD5
#define GPIO_PUPDR_PUPDR5_0                 GPIO_PUPDR_PUPD5_0
#define GPIO_PUPDR_PUPDR5_1                 GPIO_PUPDR_PUPD5_1
#define GPIO_PUPDR_PUPDR6                   GPIO_PUPDR_PUPD6
#define GPIO_PUPDR_PUPDR6_0                 GPIO_PUPDR_PUPD6_0
#define GPIO_PUPDR_PUPDR6_1                 GPIO_PUPDR_PUPD6_1
#define GPIO_PUPDR_PUPDR7                   GPIO_PUPDR_PUPD7
#define GPIO_PUPDR_PUPDR7_0                 GPIO_PUPDR_PUPD7_0
#define GPIO_PUPDR_PUPDR7_1                 GPIO_PUPDR_PUPD7_1
#define GPIO_PUPDR_PUPDR8                   GPIO_PUPDR_PUPD8
#define GPIO_PUPDR_PUPDR8_0                 GPIO_PUPDR_PUPD8_0
#define GPIO_PUPDR_PUPDR8_1                 GPIO_PUPDR_PUPD8_1
#define GPIO_PUPDR_PUPDR9                   GPIO_PUPDR_PUPD9
#define GPIO_PUPDR_PUPDR9_0                 GPIO_PUPDR_PUPD9_0
#define GPIO_PUPDR_PUPDR9_1                 GPIO_PUPDR_PUPD9_1
#define GPIO_PUPDR_PUPDR10                  GPIO_PUPDR_PUPD10
#define GPIO_PUPDR_PUPDR10_0                GPIO_PUPDR_PUPD10_0
#define GPIO_PUPDR_PUPDR10_1                GPIO_PUPDR_PUPD10_1
#define GPIO_PUPDR_PUPDR11                  GPIO_PUPDR_PUPD11
#define GPIO_PUPDR_PUPDR11_0                GPIO_PUPDR_PUPD11_0
#define GPIO_PUPDR_PUPDR11_1                GPIO_PUPDR_PUPD11_1
#define GPIO_PUPDR_PUPDR12                  GPIO_PUPDR_PUPD12
#define GPIO_PUPDR_PUPDR12_0                GPIO_PUPDR_PUPD12_0
#define GPIO_PUPDR_PUPDR12_1                GPIO_PUPDR_PUPD12_1
#define GPIO_PUPDR_PUPDR13                  GPIO_PUPDR_PUPD13
#define GPIO_PUPDR_PUPDR13_0                GPIO_PUPDR_PUPD13_0
#define GPIO_PUPDR_PUPDR13_1                GPIO_PUPDR_PUPD13_1
#define GPIO_PUPDR_PUPDR14                  GPIO_PUPDR_PUPD14
#define GPIO_PUPDR_PUPDR14_0                GPIO_PUPDR_PUPD14_0
#define GPIO_PUPDR_PUPDR14_1                GPIO_PUPDR_PUPD14_1
#define GPIO_PUPDR_PUPDR15                  GPIO_PUPDR_PUPD15
#define GPIO_PUPDR_PUPDR15_0                GPIO_PUPDR_PUPD15_0
#define GPIO_PUPDR_PUPDR15_1                GPIO_PUPDR_PUPD15_1

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos                 (0U)
#define GPIO_IDR_ID0_Msk                 (0x1U << GPIO_IDR_ID0_Pos)            /*!< 0x00000001 */
#define GPIO_IDR_ID0                     GPIO_IDR_ID0_Msk
#define GPIO_IDR_ID1_Pos                 (1U)
#define GPIO_IDR_ID1_Msk                 (0x1U << GPIO_IDR_ID1_Pos)            /*!< 0x00000002 */
#define GPIO_IDR_ID1                     GPIO_IDR_ID1_Msk
#define GPIO_IDR_ID2_Pos                 (2U)
#define GPIO_IDR_ID2_Msk                 (0x1U << GPIO_IDR_ID2_Pos)            /*!< 0x00000004 */
#define GPIO_IDR_ID2                     GPIO_IDR_ID2_Msk
#define GPIO_IDR_ID3_Pos                 (3U)
#define GPIO_IDR_ID3_Msk                 (0x1U << GPIO_IDR_ID3_Pos)            /*!< 0x00000008 */
#define GPIO_IDR_ID3                     GPIO_IDR_ID3_Msk
#define GPIO_IDR_ID4_Pos                 (4U)
#define GPIO_IDR_ID4_Msk                 (0x1U << GPIO_IDR_ID4_Pos)            /*!< 0x00000010 */
#define GPIO_IDR_ID4                     GPIO_IDR_ID4_Msk
#define GPIO_IDR_ID5_Pos                 (5U)
#define GPIO_IDR_ID5_Msk                 (0x1U << GPIO_IDR_ID5_Pos)            /*!< 0x00000020 */
#define GPIO_IDR_ID5                     GPIO_IDR_ID5_Msk
#define GPIO_IDR_ID6_Pos                 (6U)
#define GPIO_IDR_ID6_Msk                 (0x1U << GPIO_IDR_ID6_Pos)            /*!< 0x00000040 */
#define GPIO_IDR_ID6                     GPIO_IDR_ID6_Msk
#define GPIO_IDR_ID7_Pos                 (7U)
#define GPIO_IDR_ID7_Msk                 (0x1U << GPIO_IDR_ID7_Pos)            /*!< 0x00000080 */
#define GPIO_IDR_ID7                     GPIO_IDR_ID7_Msk
#define GPIO_IDR_ID8_Pos                 (8U)
#define GPIO_IDR_ID8_Msk                 (0x1U << GPIO_IDR_ID8_Pos)            /*!< 0x00000100 */
#define GPIO_IDR_ID8                     GPIO_IDR_ID8_Msk
#define GPIO_IDR_ID9_Pos                 (9U)
#define GPIO_IDR_ID9_Msk                 (0x1U << GPIO_IDR_ID9_Pos)            /*!< 0x00000200 */
#define GPIO_IDR_ID9                     GPIO_IDR_ID9_Msk
#define GPIO_IDR_ID10_Pos                (10U)
#define GPIO_IDR_ID10_Msk                (0x1U << GPIO_IDR_ID10_Pos)           /*!< 0x00000400 */
#define GPIO_IDR_ID10                    GPIO_IDR_ID10_Msk
#define GPIO_IDR_ID11_Pos                (11U)
#define GPIO_IDR_ID11_Msk                (0x1U << GPIO_IDR_ID11_Pos)           /*!< 0x00000800 */
#define GPIO_IDR_ID11                    GPIO_IDR_ID11_Msk
#define GPIO_IDR_ID12_Pos                (12U)
#define GPIO_IDR_ID12_Msk                (0x1U << GPIO_IDR_ID12_Pos)           /*!< 0x00001000 */
#define GPIO_IDR_ID12                    GPIO_IDR_ID12_Msk
#define GPIO_IDR_ID13_Pos                (13U)
#define GPIO_IDR_ID13_Msk                (0x1U << GPIO_IDR_ID13_Pos)           /*!< 0x00002000 */
#define GPIO_IDR_ID13                    GPIO_IDR_ID13_Msk
#define GPIO_IDR_ID14_Pos                (14U)
#define GPIO_IDR_ID14_Msk                (0x1U << GPIO_IDR_ID14_Pos)           /*!< 0x00004000 */
#define GPIO_IDR_ID14                    GPIO_IDR_ID14_Msk
#define GPIO_IDR_ID15_Pos                (15U)
#define GPIO_IDR_ID15_Msk                (0x1U << GPIO_IDR_ID15_Pos)           /*!< 0x00008000 */
#define GPIO_IDR_ID15                    GPIO_IDR_ID15_Msk

/* Legacy defines */
#define GPIO_IDR_IDR_0                      GPIO_IDR_ID0
#define GPIO_IDR_IDR_1                      GPIO_IDR_ID1
#define GPIO_IDR_IDR_2                      GPIO_IDR_ID2
#define GPIO_IDR_IDR_3                      GPIO_IDR_ID3
#define GPIO_IDR_IDR_4                      GPIO_IDR_ID4
#define GPIO_IDR_IDR_5                      GPIO_IDR_ID5
#define GPIO_IDR_IDR_6                      GPIO_IDR_ID6
#define GPIO_IDR_IDR_7                      GPIO_IDR_ID7
#define GPIO_IDR_IDR_8                      GPIO_IDR_ID8
#define GPIO_IDR_IDR_9                      GPIO_IDR_ID9
#define GPIO_IDR_IDR_10                     GPIO_IDR_ID10
#define GPIO_IDR_IDR_11                     GPIO_IDR_ID11
#define GPIO_IDR_IDR_12                     GPIO_IDR_ID12
#define GPIO_IDR_IDR_13                     GPIO_IDR_ID13
#define GPIO_IDR_IDR_14                     GPIO_IDR_ID14
#define GPIO_IDR_IDR_15                     GPIO_IDR_ID15

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos                 (0U)
#define GPIO_ODR_OD0_Msk                 (0x1U << GPIO_ODR_OD0_Pos)            /*!< 0x00000001 */
#define GPIO_ODR_OD0                     GPIO_ODR_OD0_Msk
#define GPIO_ODR_OD1_Pos                 (1U)
#define GPIO_ODR_OD1_Msk                 (0x1U << GPIO_ODR_OD1_Pos)            /*!< 0x00000002 */
#define GPIO_ODR_OD1                     GPIO_ODR_OD1_Msk
#define GPIO_ODR_OD2_Pos                 (2U)
#define GPIO_ODR_OD2_Msk                 (0x1U << GPIO_ODR_OD2_Pos)            /*!< 0x00000004 */
#define GPIO_ODR_OD2                     GPIO_ODR_OD2_Msk
#define GPIO_ODR_OD3_Pos                 (3U)
#define GPIO_ODR_OD3_Msk                 (0x1U << GPIO_ODR_OD3_Pos)            /*!< 0x00000008 */
#define GPIO_ODR_OD3                     GPIO_ODR_OD3_Msk
#define GPIO_ODR_OD4_Pos                 (4U)
#define GPIO_ODR_OD4_Msk                 (0x1U << GPIO_ODR_OD4_Pos)            /*!< 0x00000010 */
#define GPIO_ODR_OD4                     GPIO_ODR_OD4_Msk
#define GPIO_ODR_OD5_Pos                 (5U)
#define GPIO_ODR_OD5_Msk                 (0x1U << GPIO_ODR_OD5_Pos)            /*!< 0x00000020 */
#define GPIO_ODR_OD5                     GPIO_ODR_OD5_Msk
#define GPIO_ODR_OD6_Pos                 (6U)
#define GPIO_ODR_OD6_Msk                 (0x1U << GPIO_ODR_OD6_Pos)            /*!< 0x00000040 */
#define GPIO_ODR_OD6                     GPIO_ODR_OD6_Msk
#define GPIO_ODR_OD7_Pos                 (7U)
#define GPIO_ODR_OD7_Msk                 (0x1U << GPIO_ODR_OD7_Pos)            /*!< 0x00000080 */
#define GPIO_ODR_OD7                     GPIO_ODR_OD7_Msk
#define GPIO_ODR_OD8_Pos                 (8U)
#define GPIO_ODR_OD8_Msk                 (0x1U << GPIO_ODR_OD8_Pos)            /*!< 0x00000100 */
#define GPIO_ODR_OD8                     GPIO_ODR_OD8_Msk
#define GPIO_ODR_OD9_Pos                 (9U)
#define GPIO_ODR_OD9_Msk                 (0x1U << GPIO_ODR_OD9_Pos)            /*!< 0x00000200 */
#define GPIO_ODR_OD9                     GPIO_ODR_OD9_Msk
#define GPIO_ODR_OD10_Pos                (10U)
#define GPIO_ODR_OD10_Msk                (0x1U << GPIO_ODR_OD10_Pos)           /*!< 0x00000400 */
#define GPIO_ODR_OD10                    GPIO_ODR_OD10_Msk
#define GPIO_ODR_OD11_Pos                (11U)
#define GPIO_ODR_OD11_Msk                (0x1U << GPIO_ODR_OD11_Pos)           /*!< 0x00000800 */
#define GPIO_ODR_OD11                    GPIO_ODR_OD11_Msk
#define GPIO_ODR_OD12_Pos                (12U)
#define GPIO_ODR_OD12_Msk                (0x1U << GPIO_ODR_OD12_Pos)           /*!< 0x00001000 */
#define GPIO_ODR_OD12                    GPIO_ODR_OD12_Msk
#define GPIO_ODR_OD13_Pos                (13U)
#define GPIO_ODR_OD13_Msk                (0x1U << GPIO_ODR_OD13_Pos)           /*!< 0x00002000 */
#define GPIO_ODR_OD13                    GPIO_ODR_OD13_Msk
#define GPIO_ODR_OD14_Pos                (14U)
#define GPIO_ODR_OD14_Msk                (0x1U << GPIO_ODR_OD14_Pos)           /*!< 0x00004000 */
#define GPIO_ODR_OD14                    GPIO_ODR_OD14_Msk
#define GPIO_ODR_OD15_Pos                (15U)
#define GPIO_ODR_OD15_Msk                (0x1U << GPIO_ODR_OD15_Pos)           /*!< 0x00008000 */
#define GPIO_ODR_OD15                    GPIO_ODR_OD15_Msk
/* Legacy defines */
#define GPIO_ODR_ODR_0                       GPIO_ODR_OD0
#define GPIO_ODR_ODR_1                       GPIO_ODR_OD1
#define GPIO_ODR_ODR_2                       GPIO_ODR_OD2
#define GPIO_ODR_ODR_3                       GPIO_ODR_OD3
#define GPIO_ODR_ODR_4                       GPIO_ODR_OD4
#define GPIO_ODR_ODR_5                       GPIO_ODR_OD5
#define GPIO_ODR_ODR_6                       GPIO_ODR_OD6
#define GPIO_ODR_ODR_7                       GPIO_ODR_OD7
#define GPIO_ODR_ODR_8                       GPIO_ODR_OD8
#define GPIO_ODR_ODR_9                       GPIO_ODR_OD9
#define GPIO_ODR_ODR_10                      GPIO_ODR_OD10
#define GPIO_ODR_ODR_11                      GPIO_ODR_OD11
#define GPIO_ODR_ODR_12                      GPIO_ODR_OD12
#define GPIO_ODR_ODR_13                      GPIO_ODR_OD13
#define GPIO_ODR_ODR_14                      GPIO_ODR_OD14
#define GPIO_ODR_ODR_15                      GPIO_ODR_OD15

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS0_Pos                (0U)
#define GPIO_BSRR_BS0_Msk                (0x1U << GPIO_BSRR_BS0_Pos)           /*!< 0x00000001 */
#define GPIO_BSRR_BS0                    GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos                (1U)
#define GPIO_BSRR_BS1_Msk                (0x1U << GPIO_BSRR_BS1_Pos)           /*!< 0x00000002 */
#define GPIO_BSRR_BS1                    GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos                (2U)
#define GPIO_BSRR_BS2_Msk                (0x1U << GPIO_BSRR_BS2_Pos)           /*!< 0x00000004 */
#define GPIO_BSRR_BS2                    GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos                (3U)
#define GPIO_BSRR_BS3_Msk                (0x1U << GPIO_BSRR_BS3_Pos)           /*!< 0x00000008 */
#define GPIO_BSRR_BS3                    GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos                (4U)
#define GPIO_BSRR_BS4_Msk                (0x1U << GPIO_BSRR_BS4_Pos)           /*!< 0x00000010 */
#define GPIO_BSRR_BS4                    GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos                (5U)
#define GPIO_BSRR_BS5_Msk                (0x1U << GPIO_BSRR_BS5_Pos)           /*!< 0x00000020 */
#define GPIO_BSRR_BS5                    GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos                (6U)
#define GPIO_BSRR_BS6_Msk                (0x1U << GPIO_BSRR_BS6_Pos)           /*!< 0x00000040 */
#define GPIO_BSRR_BS6                    GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos                (7U)
#define GPIO_BSRR_BS7_Msk                (0x1U << GPIO_BSRR_BS7_Pos)           /*!< 0x00000080 */
#define GPIO_BSRR_BS7                    GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BS8_Pos                (8U)
#define GPIO_BSRR_BS8_Msk                (0x1U << GPIO_BSRR_BS8_Pos)           /*!< 0x00000100 */
#define GPIO_BSRR_BS8                    GPIO_BSRR_BS8_Msk
#define GPIO_BSRR_BS9_Pos                (9U)
#define GPIO_BSRR_BS9_Msk                (0x1U << GPIO_BSRR_BS9_Pos)           /*!< 0x00000200 */
#define GPIO_BSRR_BS9                    GPIO_BSRR_BS9_Msk
#define GPIO_BSRR_BS10_Pos               (10U)
#define GPIO_BSRR_BS10_Msk               (0x1U << GPIO_BSRR_BS10_Pos)          /*!< 0x00000400 */
#define GPIO_BSRR_BS10                   GPIO_BSRR_BS10_Msk
#define GPIO_BSRR_BS11_Pos               (11U)
#define GPIO_BSRR_BS11_Msk               (0x1U << GPIO_BSRR_BS11_Pos)          /*!< 0x00000800 */
#define GPIO_BSRR_BS11                   GPIO_BSRR_BS11_Msk
#define GPIO_BSRR_BS12_Pos               (12U)
#define GPIO_BSRR_BS12_Msk               (0x1U << GPIO_BSRR_BS12_Pos)          /*!< 0x00001000 */
#define GPIO_BSRR_BS12                   GPIO_BSRR_BS12_Msk
#define GPIO_BSRR_BS13_Pos               (13U)
#define GPIO_BSRR_BS13_Msk               (0x1U << GPIO_BSRR_BS13_Pos)          /*!< 0x00002000 */
#define GPIO_BSRR_BS13                   GPIO_BSRR_BS13_Msk
#define GPIO_BSRR_BS14_Pos               (14U)
#define GPIO_BSRR_BS14_Msk               (0x1U << GPIO_BSRR_BS14_Pos)          /*!< 0x00004000 */
#define GPIO_BSRR_BS14                   GPIO_BSRR_BS14_Msk
#define GPIO_BSRR_BS15_Pos               (15U)
#define GPIO_BSRR_BS15_Msk               (0x1U << GPIO_BSRR_BS15_Pos)          /*!< 0x00008000 */
#define GPIO_BSRR_BS15                   GPIO_BSRR_BS15_Msk
#define GPIO_BSRR_BR0_Pos                (16U)
#define GPIO_BSRR_BR0_Msk                (0x1U << GPIO_BSRR_BR0_Pos)           /*!< 0x00010000 */
#define GPIO_BSRR_BR0                    GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos                (17U)
#define GPIO_BSRR_BR1_Msk                (0x1U << GPIO_BSRR_BR1_Pos)           /*!< 0x00020000 */
#define GPIO_BSRR_BR1                    GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos                (18U)
#define GPIO_BSRR_BR2_Msk                (0x1U << GPIO_BSRR_BR2_Pos)           /*!< 0x00040000 */
#define GPIO_BSRR_BR2                    GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos                (19U)
#define GPIO_BSRR_BR3_Msk                (0x1U << GPIO_BSRR_BR3_Pos)           /*!< 0x00080000 */
#define GPIO_BSRR_BR3                    GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos                (20U)
#define GPIO_BSRR_BR4_Msk                (0x1U << GPIO_BSRR_BR4_Pos)           /*!< 0x00100000 */
#define GPIO_BSRR_BR4                    GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos                (21U)
#define GPIO_BSRR_BR5_Msk                (0x1U << GPIO_BSRR_BR5_Pos)           /*!< 0x00200000 */
#define GPIO_BSRR_BR5                    GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos                (22U)
#define GPIO_BSRR_BR6_Msk                (0x1U << GPIO_BSRR_BR6_Pos)           /*!< 0x00400000 */
#define GPIO_BSRR_BR6                    GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos                (23U)
#define GPIO_BSRR_BR7_Msk                (0x1U << GPIO_BSRR_BR7_Pos)           /*!< 0x00800000 */
#define GPIO_BSRR_BR7                    GPIO_BSRR_BR7_Msk
#define GPIO_BSRR_BR8_Pos                (24U)
#define GPIO_BSRR_BR8_Msk                (0x1U << GPIO_BSRR_BR8_Pos)           /*!< 0x01000000 */
#define GPIO_BSRR_BR8                    GPIO_BSRR_BR8_Msk
#define GPIO_BSRR_BR9_Pos                (25U)
#define GPIO_BSRR_BR9_Msk                (0x1U << GPIO_BSRR_BR9_Pos)           /*!< 0x02000000 */
#define GPIO_BSRR_BR9                    GPIO_BSRR_BR9_Msk
#define GPIO_BSRR_BR10_Pos               (26U)
#define GPIO_BSRR_BR10_Msk               (0x1U << GPIO_BSRR_BR10_Pos)          /*!< 0x04000000 */
#define GPIO_BSRR_BR10                   GPIO_BSRR_BR10_Msk
#define GPIO_BSRR_BR11_Pos               (27U)
#define GPIO_BSRR_BR11_Msk               (0x1U << GPIO_BSRR_BR11_Pos)          /*!< 0x08000000 */
#define GPIO_BSRR_BR11                   GPIO_BSRR_BR11_Msk
#define GPIO_BSRR_BR12_Pos               (28U)
#define GPIO_BSRR_BR12_Msk               (0x1U << GPIO_BSRR_BR12_Pos)          /*!< 0x10000000 */
#define GPIO_BSRR_BR12                   GPIO_BSRR_BR12_Msk
#define GPIO_BSRR_BR13_Pos               (29U)
#define GPIO_BSRR_BR13_Msk               (0x1U << GPIO_BSRR_BR13_Pos)          /*!< 0x20000000 */
#define GPIO_BSRR_BR13                   GPIO_BSRR_BR13_Msk
#define GPIO_BSRR_BR14_Pos               (30U)
#define GPIO_BSRR_BR14_Msk               (0x1U << GPIO_BSRR_BR14_Pos)          /*!< 0x40000000 */
#define GPIO_BSRR_BR14                   GPIO_BSRR_BR14_Msk
#define GPIO_BSRR_BR15_Pos               (31U)
#define GPIO_BSRR_BR15_Msk               (0x1U << GPIO_BSRR_BR15_Pos)          /*!< 0x80000000 */
#define GPIO_BSRR_BR15                   GPIO_BSRR_BR15_Msk

/* Legacy defines */
#define GPIO_BSRR_BS_0                      GPIO_BSRR_BS0
#define GPIO_BSRR_BS_1                      GPIO_BSRR_BS1
#define GPIO_BSRR_BS_2                      GPIO_BSRR_BS2
#define GPIO_BSRR_BS_3                      GPIO_BSRR_BS3
#define GPIO_BSRR_BS_4                      GPIO_BSRR_BS4
#define GPIO_BSRR_BS_5                      GPIO_BSRR_BS5
#define GPIO_BSRR_BS_6                      GPIO_BSRR_BS6
#define GPIO_BSRR_BS_7                      GPIO_BSRR_BS7
#define GPIO_BSRR_BS_8                      GPIO_BSRR_BS8
#define GPIO_BSRR_BS_9                      GPIO_BSRR_BS9
#define GPIO_BSRR_BS_10                     GPIO_BSRR_BS10
#define GPIO_BSRR_BS_11                     GPIO_BSRR_BS11
#define GPIO_BSRR_BS_12                     GPIO_BSRR_BS12
#define GPIO_BSRR_BS_13                     GPIO_BSRR_BS13
#define GPIO_BSRR_BS_14                     GPIO_BSRR_BS14
#define GPIO_BSRR_BS_15                     GPIO_BSRR_BS15
#define GPIO_BSRR_BR_0                      GPIO_BSRR_BR0
#define GPIO_BSRR_BR_1                      GPIO_BSRR_BR1
#define GPIO_BSRR_BR_2                      GPIO_BSRR_BR2
#define GPIO_BSRR_BR_3                      GPIO_BSRR_BR3
#define GPIO_BSRR_BR_4                      GPIO_BSRR_BR4
#define GPIO_BSRR_BR_5                      GPIO_BSRR_BR5
#define GPIO_BSRR_BR_6                      GPIO_BSRR_BR6
#define GPIO_BSRR_BR_7                      GPIO_BSRR_BR7
#define GPIO_BSRR_BR_8                      GPIO_BSRR_BR8
#define GPIO_BSRR_BR_9                      GPIO_BSRR_BR9
#define GPIO_BSRR_BR_10                     GPIO_BSRR_BR10
#define GPIO_BSRR_BR_11                     GPIO_BSRR_BR11
#define GPIO_BSRR_BR_12                     GPIO_BSRR_BR12
#define GPIO_BSRR_BR_13                     GPIO_BSRR_BR13
#define GPIO_BSRR_BR_14                     GPIO_BSRR_BR14
#define GPIO_BSRR_BR_15                     GPIO_BSRR_BR15
/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos               (0U)
#define GPIO_LCKR_LCK0_Msk               (0x1U << GPIO_LCKR_LCK0_Pos)          /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                   GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos               (1U)
#define GPIO_LCKR_LCK1_Msk               (0x1U << GPIO_LCKR_LCK1_Pos)          /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                   GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos               (2U)
#define GPIO_LCKR_LCK2_Msk               (0x1U << GPIO_LCKR_LCK2_Pos)          /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                   GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos               (3U)
#define GPIO_LCKR_LCK3_Msk               (0x1U << GPIO_LCKR_LCK3_Pos)          /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                   GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos               (4U)
#define GPIO_LCKR_LCK4_Msk               (0x1U << GPIO_LCKR_LCK4_Pos)          /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                   GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos               (5U)
#define GPIO_LCKR_LCK5_Msk               (0x1U << GPIO_LCKR_LCK5_Pos)          /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                   GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos               (6U)
#define GPIO_LCKR_LCK6_Msk               (0x1U << GPIO_LCKR_LCK6_Pos)          /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                   GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos               (7U)
#define GPIO_LCKR_LCK7_Msk               (0x1U << GPIO_LCKR_LCK7_Pos)          /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                   GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos               (8U)
#define GPIO_LCKR_LCK8_Msk               (0x1U << GPIO_LCKR_LCK8_Pos)          /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                   GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos               (9U)
#define GPIO_LCKR_LCK9_Msk               (0x1U << GPIO_LCKR_LCK9_Pos)          /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                   GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos              (10U)
#define GPIO_LCKR_LCK10_Msk              (0x1U << GPIO_LCKR_LCK10_Pos)         /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                  GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos              (11U)
#define GPIO_LCKR_LCK11_Msk              (0x1U << GPIO_LCKR_LCK11_Pos)         /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                  GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos              (12U)
#define GPIO_LCKR_LCK12_Msk              (0x1U << GPIO_LCKR_LCK12_Pos)         /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                  GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos              (13U)
#define GPIO_LCKR_LCK13_Msk              (0x1U << GPIO_LCKR_LCK13_Pos)         /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                  GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos              (14U)
#define GPIO_LCKR_LCK14_Msk              (0x1U << GPIO_LCKR_LCK14_Pos)         /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                  GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos              (15U)
#define GPIO_LCKR_LCK15_Msk              (0x1U << GPIO_LCKR_LCK15_Pos)         /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                  GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos               (16U)
#define GPIO_LCKR_LCKK_Msk               (0x1U << GPIO_LCKR_LCKK_Pos)          /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                   GPIO_LCKR_LCKK_Msk
/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFSEL0_Pos             (0U)
#define GPIO_AFRL_AFSEL0_Msk             (0xFU << GPIO_AFRL_AFSEL0_Pos)        /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0                 GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL0_0               (0x1U << GPIO_AFRL_AFSEL0_Pos)        /*!< 0x00000001 */
#define GPIO_AFRL_AFSEL0_1               (0x2U << GPIO_AFRL_AFSEL0_Pos)        /*!< 0x00000002 */
#define GPIO_AFRL_AFSEL0_2               (0x4U << GPIO_AFRL_AFSEL0_Pos)        /*!< 0x00000004 */
#define GPIO_AFRL_AFSEL0_3               (0x8U << GPIO_AFRL_AFSEL0_Pos)        /*!< 0x00000008 */
#define GPIO_AFRL_AFSEL1_Pos             (4U)
#define GPIO_AFRL_AFSEL1_Msk             (0xFU << GPIO_AFRL_AFSEL1_Pos)        /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1                 GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL1_0               (0x1U << GPIO_AFRL_AFSEL1_Pos)        /*!< 0x00000010 */
#define GPIO_AFRL_AFSEL1_1               (0x2U << GPIO_AFRL_AFSEL1_Pos)        /*!< 0x00000020 */
#define GPIO_AFRL_AFSEL1_2               (0x4U << GPIO_AFRL_AFSEL1_Pos)        /*!< 0x00000040 */
#define GPIO_AFRL_AFSEL1_3               (0x8U << GPIO_AFRL_AFSEL1_Pos)        /*!< 0x00000080 */
#define GPIO_AFRL_AFSEL2_Pos             (8U)
#define GPIO_AFRL_AFSEL2_Msk             (0xFU << GPIO_AFRL_AFSEL2_Pos)        /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2                 GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL2_0               (0x1U << GPIO_AFRL_AFSEL2_Pos)        /*!< 0x00000100 */
#define GPIO_AFRL_AFSEL2_1               (0x2U << GPIO_AFRL_AFSEL2_Pos)        /*!< 0x00000200 */
#define GPIO_AFRL_AFSEL2_2               (0x4U << GPIO_AFRL_AFSEL2_Pos)        /*!< 0x00000400 */
#define GPIO_AFRL_AFSEL2_3               (0x8U << GPIO_AFRL_AFSEL2_Pos)        /*!< 0x00000800 */
#define GPIO_AFRL_AFSEL3_Pos             (12U)
#define GPIO_AFRL_AFSEL3_Msk             (0xFU << GPIO_AFRL_AFSEL3_Pos)        /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3                 GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL3_0               (0x1U << GPIO_AFRL_AFSEL3_Pos)        /*!< 0x00001000 */
#define GPIO_AFRL_AFSEL3_1               (0x2U << GPIO_AFRL_AFSEL3_Pos)        /*!< 0x00002000 */
#define GPIO_AFRL_AFSEL3_2               (0x4U << GPIO_AFRL_AFSEL3_Pos)        /*!< 0x00004000 */
#define GPIO_AFRL_AFSEL3_3               (0x8U << GPIO_AFRL_AFSEL3_Pos)        /*!< 0x00008000 */
#define GPIO_AFRL_AFSEL4_Pos             (16U)
#define GPIO_AFRL_AFSEL4_Msk             (0xFU << GPIO_AFRL_AFSEL4_Pos)        /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4                 GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL4_0               (0x1U << GPIO_AFRL_AFSEL4_Pos)        /*!< 0x00010000 */
#define GPIO_AFRL_AFSEL4_1               (0x2U << GPIO_AFRL_AFSEL4_Pos)        /*!< 0x00020000 */
#define GPIO_AFRL_AFSEL4_2               (0x4U << GPIO_AFRL_AFSEL4_Pos)        /*!< 0x00040000 */
#define GPIO_AFRL_AFSEL4_3               (0x8U << GPIO_AFRL_AFSEL4_Pos)        /*!< 0x00080000 */
#define GPIO_AFRL_AFSEL5_Pos             (20U)
#define GPIO_AFRL_AFSEL5_Msk             (0xFU << GPIO_AFRL_AFSEL5_Pos)        /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5                 GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL5_0               (0x1U << GPIO_AFRL_AFSEL5_Pos)        /*!< 0x00100000 */
#define GPIO_AFRL_AFSEL5_1               (0x2U << GPIO_AFRL_AFSEL5_Pos)        /*!< 0x00200000 */
#define GPIO_AFRL_AFSEL5_2               (0x4U << GPIO_AFRL_AFSEL5_Pos)        /*!< 0x00400000 */
#define GPIO_AFRL_AFSEL5_3               (0x8U << GPIO_AFRL_AFSEL5_Pos)        /*!< 0x00800000 */
#define GPIO_AFRL_AFSEL6_Pos             (24U)
#define GPIO_AFRL_AFSEL6_Msk             (0xFU << GPIO_AFRL_AFSEL6_Pos)        /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6                 GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL6_0               (0x1U << GPIO_AFRL_AFSEL6_Pos)        /*!< 0x01000000 */
#define GPIO_AFRL_AFSEL6_1               (0x2U << GPIO_AFRL_AFSEL6_Pos)        /*!< 0x02000000 */
#define GPIO_AFRL_AFSEL6_2               (0x4U << GPIO_AFRL_AFSEL6_Pos)        /*!< 0x04000000 */
#define GPIO_AFRL_AFSEL6_3               (0x8U << GPIO_AFRL_AFSEL6_Pos)        /*!< 0x08000000 */
#define GPIO_AFRL_AFSEL7_Pos             (28U)
#define GPIO_AFRL_AFSEL7_Msk             (0xFU << GPIO_AFRL_AFSEL7_Pos)        /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7                 GPIO_AFRL_AFSEL7_Msk
#define GPIO_AFRL_AFSEL7_0               (0x1U << GPIO_AFRL_AFSEL7_Pos)        /*!< 0x10000000 */
#define GPIO_AFRL_AFSEL7_1               (0x2U << GPIO_AFRL_AFSEL7_Pos)        /*!< 0x20000000 */
#define GPIO_AFRL_AFSEL7_2               (0x4U << GPIO_AFRL_AFSEL7_Pos)        /*!< 0x40000000 */
#define GPIO_AFRL_AFSEL7_3               (0x8U << GPIO_AFRL_AFSEL7_Pos)        /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_AFRL_AFRL0                      GPIO_AFRL_AFSEL0
#define GPIO_AFRL_AFRL0_0                    GPIO_AFRL_AFSEL0_0
#define GPIO_AFRL_AFRL0_1                    GPIO_AFRL_AFSEL0_1
#define GPIO_AFRL_AFRL0_2                    GPIO_AFRL_AFSEL0_2
#define GPIO_AFRL_AFRL0_3                    GPIO_AFRL_AFSEL0_3
#define GPIO_AFRL_AFRL1                      GPIO_AFRL_AFSEL1
#define GPIO_AFRL_AFRL1_0                    GPIO_AFRL_AFSEL1_0
#define GPIO_AFRL_AFRL1_1                    GPIO_AFRL_AFSEL1_1
#define GPIO_AFRL_AFRL1_2                    GPIO_AFRL_AFSEL1_2
#define GPIO_AFRL_AFRL1_3                    GPIO_AFRL_AFSEL1_3
#define GPIO_AFRL_AFRL2                      GPIO_AFRL_AFSEL2
#define GPIO_AFRL_AFRL2_0                    GPIO_AFRL_AFSEL2_0
#define GPIO_AFRL_AFRL2_1                    GPIO_AFRL_AFSEL2_1
#define GPIO_AFRL_AFRL2_2                    GPIO_AFRL_AFSEL2_2
#define GPIO_AFRL_AFRL2_3                    GPIO_AFRL_AFSEL2_3
#define GPIO_AFRL_AFRL3                      GPIO_AFRL_AFSEL3
#define GPIO_AFRL_AFRL3_0                    GPIO_AFRL_AFSEL3_0
#define GPIO_AFRL_AFRL3_1                    GPIO_AFRL_AFSEL3_1
#define GPIO_AFRL_AFRL3_2                    GPIO_AFRL_AFSEL3_2
#define GPIO_AFRL_AFRL3_3                    GPIO_AFRL_AFSEL3_3
#define GPIO_AFRL_AFRL4                      GPIO_AFRL_AFSEL4
#define GPIO_AFRL_AFRL4_0                    GPIO_AFRL_AFSEL4_0
#define GPIO_AFRL_AFRL4_1                    GPIO_AFRL_AFSEL4_1
#define GPIO_AFRL_AFRL4_2                    GPIO_AFRL_AFSEL4_2
#define GPIO_AFRL_AFRL4_3                    GPIO_AFRL_AFSEL4_3
#define GPIO_AFRL_AFRL5                      GPIO_AFRL_AFSEL5
#define GPIO_AFRL_AFRL5_0                    GPIO_AFRL_AFSEL5_0
#define GPIO_AFRL_AFRL5_1                    GPIO_AFRL_AFSEL5_1
#define GPIO_AFRL_AFRL5_2                    GPIO_AFRL_AFSEL5_2
#define GPIO_AFRL_AFRL5_3                    GPIO_AFRL_AFSEL5_3
#define GPIO_AFRL_AFRL6                      GPIO_AFRL_AFSEL6
#define GPIO_AFRL_AFRL6_0                    GPIO_AFRL_AFSEL6_0
#define GPIO_AFRL_AFRL6_1                    GPIO_AFRL_AFSEL6_1
#define GPIO_AFRL_AFRL6_2                    GPIO_AFRL_AFSEL6_2
#define GPIO_AFRL_AFRL6_3                    GPIO_AFRL_AFSEL6_3
#define GPIO_AFRL_AFRL7                      GPIO_AFRL_AFSEL7
#define GPIO_AFRL_AFRL7_0                    GPIO_AFRL_AFSEL7_0
#define GPIO_AFRL_AFRL7_1                    GPIO_AFRL_AFSEL7_1
#define GPIO_AFRL_AFRL7_2                    GPIO_AFRL_AFSEL7_2
#define GPIO_AFRL_AFRL7_3                    GPIO_AFRL_AFSEL7_3

/****************** Bit definition for GPIO_AFRH register *********************/
#define GPIO_AFRH_AFSEL8_Pos             (0U)
#define GPIO_AFRH_AFSEL8_Msk             (0xFU << GPIO_AFRH_AFSEL8_Pos)        /*!< 0x0000000F */
#define GPIO_AFRH_AFSEL8                 GPIO_AFRH_AFSEL8_Msk
#define GPIO_AFRH_AFSEL8_0               (0x1U << GPIO_AFRH_AFSEL8_Pos)        /*!< 0x00000001 */
#define GPIO_AFRH_AFSEL8_1               (0x2U << GPIO_AFRH_AFSEL8_Pos)        /*!< 0x00000002 */
#define GPIO_AFRH_AFSEL8_2               (0x4U << GPIO_AFRH_AFSEL8_Pos)        /*!< 0x00000004 */
#define GPIO_AFRH_AFSEL8_3               (0x8U << GPIO_AFRH_AFSEL8_Pos)        /*!< 0x00000008 */
#define GPIO_AFRH_AFSEL9_Pos             (4U)
#define GPIO_AFRH_AFSEL9_Msk             (0xFU << GPIO_AFRH_AFSEL9_Pos)        /*!< 0x000000F0 */
#define GPIO_AFRH_AFSEL9                 GPIO_AFRH_AFSEL9_Msk
#define GPIO_AFRH_AFSEL9_0               (0x1U << GPIO_AFRH_AFSEL9_Pos)        /*!< 0x00000010 */
#define GPIO_AFRH_AFSEL9_1               (0x2U << GPIO_AFRH_AFSEL9_Pos)        /*!< 0x00000020 */
#define GPIO_AFRH_AFSEL9_2               (0x4U << GPIO_AFRH_AFSEL9_Pos)        /*!< 0x00000040 */
#define GPIO_AFRH_AFSEL9_3               (0x8U << GPIO_AFRH_AFSEL9_Pos)        /*!< 0x00000080 */
#define GPIO_AFRH_AFSEL10_Pos            (8U)
#define GPIO_AFRH_AFSEL10_Msk            (0xFU << GPIO_AFRH_AFSEL10_Pos)       /*!< 0x00000F00 */
#define GPIO_AFRH_AFSEL10                GPIO_AFRH_AFSEL10_Msk
#define GPIO_AFRH_AFSEL10_0              (0x1U << GPIO_AFRH_AFSEL10_Pos)       /*!< 0x00000100 */
#define GPIO_AFRH_AFSEL10_1              (0x2U << GPIO_AFRH_AFSEL10_Pos)       /*!< 0x00000200 */
#define GPIO_AFRH_AFSEL10_2              (0x4U << GPIO_AFRH_AFSEL10_Pos)       /*!< 0x00000400 */
#define GPIO_AFRH_AFSEL10_3              (0x8U << GPIO_AFRH_AFSEL10_Pos)       /*!< 0x00000800 */
#define GPIO_AFRH_AFSEL11_Pos            (12U)
#define GPIO_AFRH_AFSEL11_Msk            (0xFU << GPIO_AFRH_AFSEL11_Pos)       /*!< 0x0000F000 */
#define GPIO_AFRH_AFSEL11                GPIO_AFRH_AFSEL11_Msk
#define GPIO_AFRH_AFSEL11_0              (0x1U << GPIO_AFRH_AFSEL11_Pos)       /*!< 0x00001000 */
#define GPIO_AFRH_AFSEL11_1              (0x2U << GPIO_AFRH_AFSEL11_Pos)       /*!< 0x00002000 */
#define GPIO_AFRH_AFSEL11_2              (0x4U << GPIO_AFRH_AFSEL11_Pos)       /*!< 0x00004000 */
#define GPIO_AFRH_AFSEL11_3              (0x8U << GPIO_AFRH_AFSEL11_Pos)       /*!< 0x00008000 */
#define GPIO_AFRH_AFSEL12_Pos            (16U)
#define GPIO_AFRH_AFSEL12_Msk            (0xFU << GPIO_AFRH_AFSEL12_Pos)       /*!< 0x000F0000 */
#define GPIO_AFRH_AFSEL12                GPIO_AFRH_AFSEL12_Msk
#define GPIO_AFRH_AFSEL12_0              (0x1U << GPIO_AFRH_AFSEL12_Pos)       /*!< 0x00010000 */
#define GPIO_AFRH_AFSEL12_1              (0x2U << GPIO_AFRH_AFSEL12_Pos)       /*!< 0x00020000 */
#define GPIO_AFRH_AFSEL12_2              (0x4U << GPIO_AFRH_AFSEL12_Pos)       /*!< 0x00040000 */
#define GPIO_AFRH_AFSEL12_3              (0x8U << GPIO_AFRH_AFSEL12_Pos)       /*!< 0x00080000 */
#define GPIO_AFRH_AFSEL13_Pos            (20U)
#define GPIO_AFRH_AFSEL13_Msk            (0xFU << GPIO_AFRH_AFSEL13_Pos)       /*!< 0x00F00000 */
#define GPIO_AFRH_AFSEL13                GPIO_AFRH_AFSEL13_Msk
#define GPIO_AFRH_AFSEL13_0              (0x1U << GPIO_AFRH_AFSEL13_Pos)       /*!< 0x00100000 */
#define GPIO_AFRH_AFSEL13_1              (0x2U << GPIO_AFRH_AFSEL13_Pos)       /*!< 0x00200000 */
#define GPIO_AFRH_AFSEL13_2              (0x4U << GPIO_AFRH_AFSEL13_Pos)       /*!< 0x00400000 */
#define GPIO_AFRH_AFSEL13_3              (0x8U << GPIO_AFRH_AFSEL13_Pos)       /*!< 0x00800000 */
#define GPIO_AFRH_AFSEL14_Pos            (24U)
#define GPIO_AFRH_AFSEL14_Msk            (0xFU << GPIO_AFRH_AFSEL14_Pos)       /*!< 0x0F000000 */
#define GPIO_AFRH_AFSEL14                GPIO_AFRH_AFSEL14_Msk
#define GPIO_AFRH_AFSEL14_0              (0x1U << GPIO_AFRH_AFSEL14_Pos)       /*!< 0x01000000 */
#define GPIO_AFRH_AFSEL14_1              (0x2U << GPIO_AFRH_AFSEL14_Pos)       /*!< 0x02000000 */
#define GPIO_AFRH_AFSEL14_2              (0x4U << GPIO_AFRH_AFSEL14_Pos)       /*!< 0x04000000 */
#define GPIO_AFRH_AFSEL14_3              (0x8U << GPIO_AFRH_AFSEL14_Pos)       /*!< 0x08000000 */
#define GPIO_AFRH_AFSEL15_Pos            (28U)
#define GPIO_AFRH_AFSEL15_Msk            (0xFU << GPIO_AFRH_AFSEL15_Pos)       /*!< 0xF0000000 */
#define GPIO_AFRH_AFSEL15                GPIO_AFRH_AFSEL15_Msk
#define GPIO_AFRH_AFSEL15_0              (0x1U << GPIO_AFRH_AFSEL15_Pos)       /*!< 0x10000000 */
#define GPIO_AFRH_AFSEL15_1              (0x2U << GPIO_AFRH_AFSEL15_Pos)       /*!< 0x20000000 */
#define GPIO_AFRH_AFSEL15_2              (0x4U << GPIO_AFRH_AFSEL15_Pos)       /*!< 0x40000000 */
#define GPIO_AFRH_AFSEL15_3              (0x8U << GPIO_AFRH_AFSEL15_Pos)       /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_AFRH_AFRH0                      GPIO_AFRH_AFSEL8
#define GPIO_AFRH_AFRH0_0                    GPIO_AFRH_AFSEL8_0
#define GPIO_AFRH_AFRH0_1                    GPIO_AFRH_AFSEL8_1
#define GPIO_AFRH_AFRH0_2                    GPIO_AFRH_AFSEL8_2
#define GPIO_AFRH_AFRH0_3                    GPIO_AFRH_AFSEL8_3
#define GPIO_AFRH_AFRH1                      GPIO_AFRH_AFSEL9
#define GPIO_AFRH_AFRH1_0                    GPIO_AFRH_AFSEL9_0
#define GPIO_AFRH_AFRH1_1                    GPIO_AFRH_AFSEL9_1
#define GPIO_AFRH_AFRH1_2                    GPIO_AFRH_AFSEL9_2
#define GPIO_AFRH_AFRH1_3                    GPIO_AFRH_AFSEL9_3
#define GPIO_AFRH_AFRH2                      GPIO_AFRH_AFSEL10
#define GPIO_AFRH_AFRH2_0                    GPIO_AFRH_AFSEL10_0
#define GPIO_AFRH_AFRH2_1                    GPIO_AFRH_AFSEL10_1
#define GPIO_AFRH_AFRH2_2                    GPIO_AFRH_AFSEL10_2
#define GPIO_AFRH_AFRH2_3                    GPIO_AFRH_AFSEL10_3
#define GPIO_AFRH_AFRH3                      GPIO_AFRH_AFSEL11
#define GPIO_AFRH_AFRH3_0                    GPIO_AFRH_AFSEL11_0
#define GPIO_AFRH_AFRH3_1                    GPIO_AFRH_AFSEL11_1
#define GPIO_AFRH_AFRH3_2                    GPIO_AFRH_AFSEL11_2
#define GPIO_AFRH_AFRH3_3                    GPIO_AFRH_AFSEL11_3
#define GPIO_AFRH_AFRH4                      GPIO_AFRH_AFSEL12
#define GPIO_AFRH_AFRH4_0                    GPIO_AFRH_AFSEL12_0
#define GPIO_AFRH_AFRH4_1                    GPIO_AFRH_AFSEL12_1
#define GPIO_AFRH_AFRH4_2                    GPIO_AFRH_AFSEL12_2
#define GPIO_AFRH_AFRH4_3                    GPIO_AFRH_AFSEL12_3
#define GPIO_AFRH_AFRH5                      GPIO_AFRH_AFSEL13
#define GPIO_AFRH_AFRH5_0                    GPIO_AFRH_AFSEL13_0
#define GPIO_AFRH_AFRH5_1                    GPIO_AFRH_AFSEL13_1
#define GPIO_AFRH_AFRH5_2                    GPIO_AFRH_AFSEL13_2
#define GPIO_AFRH_AFRH5_3                    GPIO_AFRH_AFSEL13_3
#define GPIO_AFRH_AFRH6                      GPIO_AFRH_AFSEL14
#define GPIO_AFRH_AFRH6_0                    GPIO_AFRH_AFSEL14_0
#define GPIO_AFRH_AFRH6_1                    GPIO_AFRH_AFSEL14_1
#define GPIO_AFRH_AFRH6_2                    GPIO_AFRH_AFSEL14_2
#define GPIO_AFRH_AFRH6_3                    GPIO_AFRH_AFSEL14_3
#define GPIO_AFRH_AFRH7                      GPIO_AFRH_AFSEL15
#define GPIO_AFRH_AFRH7_0                    GPIO_AFRH_AFSEL15_0
#define GPIO_AFRH_AFRH7_1                    GPIO_AFRH_AFSEL15_1
#define GPIO_AFRH_AFRH7_2                    GPIO_AFRH_AFSEL15_2
#define GPIO_AFRH_AFRH7_3                    GPIO_AFRH_AFSEL15_3

/******************  Bits definition for GPIO_BRR register  ******************/
#define GPIO_BRR_BR0_Pos                 (0U)
#define GPIO_BRR_BR0_Msk                 (0x1U << GPIO_BRR_BR0_Pos)            /*!< 0x00000001 */
#define GPIO_BRR_BR0                     GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos                 (1U)
#define GPIO_BRR_BR1_Msk                 (0x1U << GPIO_BRR_BR1_Pos)            /*!< 0x00000002 */
#define GPIO_BRR_BR1                     GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos                 (2U)
#define GPIO_BRR_BR2_Msk                 (0x1U << GPIO_BRR_BR2_Pos)            /*!< 0x00000004 */
#define GPIO_BRR_BR2                     GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos                 (3U)
#define GPIO_BRR_BR3_Msk                 (0x1U << GPIO_BRR_BR3_Pos)            /*!< 0x00000008 */
#define GPIO_BRR_BR3                     GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos                 (4U)
#define GPIO_BRR_BR4_Msk                 (0x1U << GPIO_BRR_BR4_Pos)            /*!< 0x00000010 */
#define GPIO_BRR_BR4                     GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos                 (5U)
#define GPIO_BRR_BR5_Msk                 (0x1U << GPIO_BRR_BR5_Pos)            /*!< 0x00000020 */
#define GPIO_BRR_BR5                     GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos                 (6U)
#define GPIO_BRR_BR6_Msk                 (0x1U << GPIO_BRR_BR6_Pos)            /*!< 0x00000040 */
#define GPIO_BRR_BR6                     GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos                 (7U)
#define GPIO_BRR_BR7_Msk                 (0x1U << GPIO_BRR_BR7_Pos)            /*!< 0x00000080 */
#define GPIO_BRR_BR7                     GPIO_BRR_BR7_Msk
#define GPIO_BRR_BR8_Pos                 (8U)
#define GPIO_BRR_BR8_Msk                 (0x1U << GPIO_BRR_BR8_Pos)            /*!< 0x00000100 */
#define GPIO_BRR_BR8                     GPIO_BRR_BR8_Msk
#define GPIO_BRR_BR9_Pos                 (9U)
#define GPIO_BRR_BR9_Msk                 (0x1U << GPIO_BRR_BR9_Pos)            /*!< 0x00000200 */
#define GPIO_BRR_BR9                     GPIO_BRR_BR9_Msk
#define GPIO_BRR_BR10_Pos                (10U)
#define GPIO_BRR_BR10_Msk                (0x1U << GPIO_BRR_BR10_Pos)           /*!< 0x00000400 */
#define GPIO_BRR_BR10                    GPIO_BRR_BR10_Msk
#define GPIO_BRR_BR11_Pos                (11U)
#define GPIO_BRR_BR11_Msk                (0x1U << GPIO_BRR_BR11_Pos)           /*!< 0x00000800 */
#define GPIO_BRR_BR11                    GPIO_BRR_BR11_Msk
#define GPIO_BRR_BR12_Pos                (12U)
#define GPIO_BRR_BR12_Msk                (0x1U << GPIO_BRR_BR12_Pos)           /*!< 0x00001000 */
#define GPIO_BRR_BR12                    GPIO_BRR_BR12_Msk
#define GPIO_BRR_BR13_Pos                (13U)
#define GPIO_BRR_BR13_Msk                (0x1U << GPIO_BRR_BR13_Pos)           /*!< 0x00002000 */
#define GPIO_BRR_BR13                    GPIO_BRR_BR13_Msk
#define GPIO_BRR_BR14_Pos                (14U)
#define GPIO_BRR_BR14_Msk                (0x1U << GPIO_BRR_BR14_Pos)           /*!< 0x00004000 */
#define GPIO_BRR_BR14                    GPIO_BRR_BR14_Msk
#define GPIO_BRR_BR15_Pos                (15U)
#define GPIO_BRR_BR15_Msk                (0x1U << GPIO_BRR_BR15_Pos)           /*!< 0x00008000 */
#define GPIO_BRR_BR15                    GPIO_BRR_BR15_Msk



/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPDS_Pos        (0U)
#define PWR_CR_LPDS_Msk        (0x1U << PWR_CR_LPDS_Pos)                       /*!< 0x00000001 */
#define PWR_CR_LPDS            PWR_CR_LPDS_Msk                                 /*!< Low-Power Deepsleep                 */
#define PWR_CR_PDDS_Pos        (1U)
#define PWR_CR_PDDS_Msk        (0x1U << PWR_CR_PDDS_Pos)                       /*!< 0x00000002 */
#define PWR_CR_PDDS            PWR_CR_PDDS_Msk                                 /*!< Power Down Deepsleep                */
#define PWR_CR_CWUF_Pos        (2U)
#define PWR_CR_CWUF_Msk        (0x1U << PWR_CR_CWUF_Pos)                       /*!< 0x00000004 */
#define PWR_CR_CWUF            PWR_CR_CWUF_Msk                                 /*!< Clear Wakeup Flag                   */
#define PWR_CR_CSBF_Pos        (3U)
#define PWR_CR_CSBF_Msk        (0x1U << PWR_CR_CSBF_Pos)                       /*!< 0x00000008 */
#define PWR_CR_CSBF            PWR_CR_CSBF_Msk                                 /*!< Clear Standby Flag                  */
#define PWR_CR_PVDE_Pos        (4U)
#define PWR_CR_PVDE_Msk        (0x1U << PWR_CR_PVDE_Pos)                       /*!< 0x00000010 */
#define PWR_CR_PVDE            PWR_CR_PVDE_Msk                                 /*!< Power Voltage Detector Enable       */

#define PWR_CR_PLS_Pos         (5U)
#define PWR_CR_PLS_Msk         (0x7U << PWR_CR_PLS_Pos)                        /*!< 0x000000E0 */
#define PWR_CR_PLS             PWR_CR_PLS_Msk                                  /*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR_PLS_0           (0x1U << PWR_CR_PLS_Pos)                        /*!< 0x00000020 */
#define PWR_CR_PLS_1           (0x2U << PWR_CR_PLS_Pos)                        /*!< 0x00000040 */
#define PWR_CR_PLS_2           (0x4U << PWR_CR_PLS_Pos)                        /*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR_PLS_LEV0        0x00000000U                                     /*!< PVD level 0 */
#define PWR_CR_PLS_LEV1        0x00000020U                                     /*!< PVD level 1 */
#define PWR_CR_PLS_LEV2        0x00000040U                                     /*!< PVD level 2 */
#define PWR_CR_PLS_LEV3        0x00000060U                                     /*!< PVD level 3 */
#define PWR_CR_PLS_LEV4        0x00000080U                                     /*!< PVD level 4 */
#define PWR_CR_PLS_LEV5        0x000000A0U                                     /*!< PVD level 5 */
#define PWR_CR_PLS_LEV6        0x000000C0U                                     /*!< PVD level 6 */
#define PWR_CR_PLS_LEV7        0x000000E0U                                     /*!< PVD level 7 */
#define PWR_CR_DBP_Pos         (8U)
#define PWR_CR_DBP_Msk         (0x1U << PWR_CR_DBP_Pos)                        /*!< 0x00000100 */
#define PWR_CR_DBP             PWR_CR_DBP_Msk                                  /*!< Disable Backup Domain write protection                     */
#define PWR_CR_FPDS_Pos        (9U)
#define PWR_CR_FPDS_Msk        (0x1U << PWR_CR_FPDS_Pos)                       /*!< 0x00000200 */
#define PWR_CR_FPDS            PWR_CR_FPDS_Msk                                 /*!< Flash power down in Stop mode                              */
#define PWR_CR_VOS_Pos         (14U)
#define PWR_CR_VOS_Msk         (0x1U << PWR_CR_VOS_Pos)                        /*!< 0x00004000 */
#define PWR_CR_VOS             PWR_CR_VOS_Msk                                  /*!< VOS bit (Regulator voltage scaling output selection) */

/* Legacy define */
#define  PWR_CR_PMODE                        PWR_CR_VOS

/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF_Pos        (0U)
#define PWR_CSR_WUF_Msk        (0x1U << PWR_CSR_WUF_Pos)                       /*!< 0x00000001 */
#define PWR_CSR_WUF            PWR_CSR_WUF_Msk                                 /*!< Wakeup Flag                                      */
#define PWR_CSR_SBF_Pos        (1U)
#define PWR_CSR_SBF_Msk        (0x1U << PWR_CSR_SBF_Pos)                       /*!< 0x00000002 */
#define PWR_CSR_SBF            PWR_CSR_SBF_Msk                                 /*!< Standby Flag                                     */
#define PWR_CSR_PVDO_Pos       (2U)
#define PWR_CSR_PVDO_Msk       (0x1U << PWR_CSR_PVDO_Pos)                      /*!< 0x00000004 */
#define PWR_CSR_PVDO           PWR_CSR_PVDO_Msk                                /*!< PVD Output                                       */
#define PWR_CSR_BRR_Pos        (3U)
#define PWR_CSR_BRR_Msk        (0x1U << PWR_CSR_BRR_Pos)                       /*!< 0x00000008 */
#define PWR_CSR_BRR            PWR_CSR_BRR_Msk                                 /*!< Backup regulator ready                           */
#define PWR_CSR_EWUP_Pos       (8U)
#define PWR_CSR_EWUP_Msk       (0x1U << PWR_CSR_EWUP_Pos)                      /*!< 0x00000100 */
#define PWR_CSR_EWUP           PWR_CSR_EWUP_Msk                                /*!< Enable WKUP pin                                  */
#define PWR_CSR_BRE_Pos        (9U)
#define PWR_CSR_BRE_Msk        (0x1U << PWR_CSR_BRE_Pos)                       /*!< 0x00000200 */
#define PWR_CSR_BRE            PWR_CSR_BRE_Msk                                 /*!< Backup regulator enable                          */
#define PWR_CSR_VOSRDY_Pos     (14U)
#define PWR_CSR_VOSRDY_Msk     (0x1U << PWR_CSR_VOSRDY_Pos)                    /*!< 0x00004000 */
#define PWR_CSR_VOSRDY         PWR_CSR_VOSRDY_Msk                              /*!< Regulator voltage scaling output selection ready */

/* Legacy define */
#define  PWR_CSR_REGRDY                      PWR_CSR_VOSRDY

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos          (0U)
#define FLASH_ACR_LATENCY_Msk          (0xFU << FLASH_ACR_LATENCY_Pos)         /*!< 0x0000000F */
#define FLASH_ACR_LATENCY              FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS          0x00000000U
#define FLASH_ACR_LATENCY_1WS          0x00000001U
#define FLASH_ACR_LATENCY_2WS          0x00000002U
#define FLASH_ACR_LATENCY_3WS          0x00000003U
#define FLASH_ACR_LATENCY_4WS          0x00000004U
#define FLASH_ACR_LATENCY_5WS          0x00000005U
#define FLASH_ACR_LATENCY_6WS          0x00000006U
#define FLASH_ACR_LATENCY_7WS          0x00000007U

#define FLASH_ACR_PRFTEN_Pos           (8U)
#define FLASH_ACR_PRFTEN_Msk           (0x1U << FLASH_ACR_PRFTEN_Pos)          /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN               FLASH_ACR_PRFTEN_Msk
#define FLASH_ACR_ICEN_Pos             (9U)
#define FLASH_ACR_ICEN_Msk             (0x1U << FLASH_ACR_ICEN_Pos)            /*!< 0x00000200 */
#define FLASH_ACR_ICEN                 FLASH_ACR_ICEN_Msk
#define FLASH_ACR_DCEN_Pos             (10U)
#define FLASH_ACR_DCEN_Msk             (0x1U << FLASH_ACR_DCEN_Pos)            /*!< 0x00000400 */
#define FLASH_ACR_DCEN                 FLASH_ACR_DCEN_Msk
#define FLASH_ACR_ICRST_Pos            (11U)
#define FLASH_ACR_ICRST_Msk            (0x1U << FLASH_ACR_ICRST_Pos)           /*!< 0x00000800 */
#define FLASH_ACR_ICRST                FLASH_ACR_ICRST_Msk
#define FLASH_ACR_DCRST_Pos            (12U)
#define FLASH_ACR_DCRST_Msk            (0x1U << FLASH_ACR_DCRST_Pos)           /*!< 0x00001000 */
#define FLASH_ACR_DCRST                FLASH_ACR_DCRST_Msk
#define FLASH_ACR_BYTE0_ADDRESS_Pos    (10U)
#define FLASH_ACR_BYTE0_ADDRESS_Msk    (0x10008FU << FLASH_ACR_BYTE0_ADDRESS_Pos) /*!< 0x40023C00 */
#define FLASH_ACR_BYTE0_ADDRESS        FLASH_ACR_BYTE0_ADDRESS_Msk
#define FLASH_ACR_BYTE2_ADDRESS_Pos    (0U)
#define FLASH_ACR_BYTE2_ADDRESS_Msk    (0x40023C03U << FLASH_ACR_BYTE2_ADDRESS_Pos) /*!< 0x40023C03 */
#define FLASH_ACR_BYTE2_ADDRESS        FLASH_ACR_BYTE2_ADDRESS_Msk

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos               (0U)
#define FLASH_SR_EOP_Msk               (0x1U << FLASH_SR_EOP_Pos)              /*!< 0x00000001 */
#define FLASH_SR_EOP                   FLASH_SR_EOP_Msk
#define FLASH_SR_SOP_Pos               (1U)
#define FLASH_SR_SOP_Msk               (0x1U << FLASH_SR_SOP_Pos)              /*!< 0x00000002 */
#define FLASH_SR_SOP                   FLASH_SR_SOP_Msk
#define FLASH_SR_WRPERR_Pos            (4U)
#define FLASH_SR_WRPERR_Msk            (0x1U << FLASH_SR_WRPERR_Pos)           /*!< 0x00000010 */
#define FLASH_SR_WRPERR                FLASH_SR_WRPERR_Msk
#define FLASH_SR_PGAERR_Pos            (5U)
#define FLASH_SR_PGAERR_Msk            (0x1U << FLASH_SR_PGAERR_Pos)           /*!< 0x00000020 */
#define FLASH_SR_PGAERR                FLASH_SR_PGAERR_Msk
#define FLASH_SR_PGPERR_Pos            (6U)
#define FLASH_SR_PGPERR_Msk            (0x1U << FLASH_SR_PGPERR_Pos)           /*!< 0x00000040 */
#define FLASH_SR_PGPERR                FLASH_SR_PGPERR_Msk
#define FLASH_SR_PGSERR_Pos            (7U)
#define FLASH_SR_PGSERR_Msk            (0x1U << FLASH_SR_PGSERR_Pos)           /*!< 0x00000080 */
#define FLASH_SR_PGSERR                FLASH_SR_PGSERR_Msk
#define FLASH_SR_BSY_Pos               (16U)
#define FLASH_SR_BSY_Msk               (0x1U << FLASH_SR_BSY_Pos)              /*!< 0x00010000 */
#define FLASH_SR_BSY                   FLASH_SR_BSY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                (0U)
#define FLASH_CR_PG_Msk                (0x1U << FLASH_CR_PG_Pos)               /*!< 0x00000001 */
#define FLASH_CR_PG                    FLASH_CR_PG_Msk
#define FLASH_CR_SER_Pos               (1U)
#define FLASH_CR_SER_Msk               (0x1U << FLASH_CR_SER_Pos)              /*!< 0x00000002 */
#define FLASH_CR_SER                   FLASH_CR_SER_Msk
#define FLASH_CR_MER_Pos               (2U)
#define FLASH_CR_MER_Msk               (0x1U << FLASH_CR_MER_Pos)              /*!< 0x00000004 */
#define FLASH_CR_MER                   FLASH_CR_MER_Msk
#define FLASH_CR_SNB_Pos               (3U)
#define FLASH_CR_SNB_Msk               (0x1FU << FLASH_CR_SNB_Pos)             /*!< 0x000000F8 */
#define FLASH_CR_SNB                   FLASH_CR_SNB_Msk
#define FLASH_CR_SNB_0                 (0x01U << FLASH_CR_SNB_Pos)             /*!< 0x00000008 */
#define FLASH_CR_SNB_1                 (0x02U << FLASH_CR_SNB_Pos)             /*!< 0x00000010 */
#define FLASH_CR_SNB_2                 (0x04U << FLASH_CR_SNB_Pos)             /*!< 0x00000020 */
#define FLASH_CR_SNB_3                 (0x08U << FLASH_CR_SNB_Pos)             /*!< 0x00000040 */
#define FLASH_CR_SNB_4                 (0x10U << FLASH_CR_SNB_Pos)             /*!< 0x00000080 */
#define FLASH_CR_PSIZE_Pos             (8U)
#define FLASH_CR_PSIZE_Msk             (0x3U << FLASH_CR_PSIZE_Pos)            /*!< 0x00000300 */
#define FLASH_CR_PSIZE                 FLASH_CR_PSIZE_Msk
#define FLASH_CR_PSIZE_0               (0x1U << FLASH_CR_PSIZE_Pos)            /*!< 0x00000100 */
#define FLASH_CR_PSIZE_1               (0x2U << FLASH_CR_PSIZE_Pos)            /*!< 0x00000200 */
#define FLASH_CR_STRT_Pos              (16U)
#define FLASH_CR_STRT_Msk              (0x1U << FLASH_CR_STRT_Pos)             /*!< 0x00010000 */
#define FLASH_CR_STRT                  FLASH_CR_STRT_Msk
#define FLASH_CR_EOPIE_Pos             (24U)
#define FLASH_CR_EOPIE_Msk             (0x1U << FLASH_CR_EOPIE_Pos)            /*!< 0x01000000 */
#define FLASH_CR_EOPIE                 FLASH_CR_EOPIE_Msk
#define FLASH_CR_LOCK_Pos              (31U)
#define FLASH_CR_LOCK_Msk              (0x1U << FLASH_CR_LOCK_Pos)             /*!< 0x80000000 */
#define FLASH_CR_LOCK                  FLASH_CR_LOCK_Msk

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK_Pos        (0U)
#define FLASH_OPTCR_OPTLOCK_Msk        (0x1U << FLASH_OPTCR_OPTLOCK_Pos)       /*!< 0x00000001 */
#define FLASH_OPTCR_OPTLOCK            FLASH_OPTCR_OPTLOCK_Msk
#define FLASH_OPTCR_OPTSTRT_Pos        (1U)
#define FLASH_OPTCR_OPTSTRT_Msk        (0x1U << FLASH_OPTCR_OPTSTRT_Pos)       /*!< 0x00000002 */
#define FLASH_OPTCR_OPTSTRT            FLASH_OPTCR_OPTSTRT_Msk

#define FLASH_OPTCR_BOR_LEV_0          0x00000004U
#define FLASH_OPTCR_BOR_LEV_1          0x00000008U
#define FLASH_OPTCR_BOR_LEV_Pos        (2U)
#define FLASH_OPTCR_BOR_LEV_Msk        (0x3U << FLASH_OPTCR_BOR_LEV_Pos)       /*!< 0x0000000C */
#define FLASH_OPTCR_BOR_LEV            FLASH_OPTCR_BOR_LEV_Msk
#define FLASH_OPTCR_WDG_SW_Pos         (5U)
#define FLASH_OPTCR_WDG_SW_Msk         (0x1U << FLASH_OPTCR_WDG_SW_Pos)        /*!< 0x00000020 */
#define FLASH_OPTCR_WDG_SW             FLASH_OPTCR_WDG_SW_Msk
#define FLASH_OPTCR_nRST_STOP_Pos      (6U)
#define FLASH_OPTCR_nRST_STOP_Msk      (0x1U << FLASH_OPTCR_nRST_STOP_Pos)     /*!< 0x00000040 */
#define FLASH_OPTCR_nRST_STOP          FLASH_OPTCR_nRST_STOP_Msk
#define FLASH_OPTCR_nRST_STDBY_Pos     (7U)
#define FLASH_OPTCR_nRST_STDBY_Msk     (0x1U << FLASH_OPTCR_nRST_STDBY_Pos)    /*!< 0x00000080 */
#define FLASH_OPTCR_nRST_STDBY         FLASH_OPTCR_nRST_STDBY_Msk
#define FLASH_OPTCR_RDP_Pos            (8U)
#define FLASH_OPTCR_RDP_Msk            (0xFFU << FLASH_OPTCR_RDP_Pos)          /*!< 0x0000FF00 */
#define FLASH_OPTCR_RDP                FLASH_OPTCR_RDP_Msk
#define FLASH_OPTCR_RDP_0              (0x01U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00000100 */
#define FLASH_OPTCR_RDP_1              (0x02U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00000200 */
#define FLASH_OPTCR_RDP_2              (0x04U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00000400 */
#define FLASH_OPTCR_RDP_3              (0x08U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00000800 */
#define FLASH_OPTCR_RDP_4              (0x10U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00001000 */
#define FLASH_OPTCR_RDP_5              (0x20U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00002000 */
#define FLASH_OPTCR_RDP_6              (0x40U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00004000 */
#define FLASH_OPTCR_RDP_7              (0x80U << FLASH_OPTCR_RDP_Pos)          /*!< 0x00008000 */
#define FLASH_OPTCR_nWRP_Pos           (16U)
#define FLASH_OPTCR_nWRP_Msk           (0xFFFU << FLASH_OPTCR_nWRP_Pos)        /*!< 0x0FFF0000 */
#define FLASH_OPTCR_nWRP               FLASH_OPTCR_nWRP_Msk
#define FLASH_OPTCR_nWRP_0             0x00010000U
#define FLASH_OPTCR_nWRP_1             0x00020000U
#define FLASH_OPTCR_nWRP_2             0x00040000U
#define FLASH_OPTCR_nWRP_3             0x00080000U
#define FLASH_OPTCR_nWRP_4             0x00100000U
#define FLASH_OPTCR_nWRP_5             0x00200000U
#define FLASH_OPTCR_nWRP_6             0x00400000U
#define FLASH_OPTCR_nWRP_7             0x00800000U
#define FLASH_OPTCR_nWRP_8             0x01000000U
#define FLASH_OPTCR_nWRP_9             0x02000000U
#define FLASH_OPTCR_nWRP_10            0x04000000U
#define FLASH_OPTCR_nWRP_11            0x08000000U

/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP_Pos          (16U)
#define FLASH_OPTCR1_nWRP_Msk          (0xFFFU << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x0FFF0000 */
#define FLASH_OPTCR1_nWRP              FLASH_OPTCR1_nWRP_Msk
#define FLASH_OPTCR1_nWRP_0            (0x001U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00010000 */
#define FLASH_OPTCR1_nWRP_1            (0x002U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00020000 */
#define FLASH_OPTCR1_nWRP_2            (0x004U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00040000 */
#define FLASH_OPTCR1_nWRP_3            (0x008U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00080000 */
#define FLASH_OPTCR1_nWRP_4            (0x010U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00100000 */
#define FLASH_OPTCR1_nWRP_5            (0x020U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00200000 */
#define FLASH_OPTCR1_nWRP_6            (0x040U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00400000 */
#define FLASH_OPTCR1_nWRP_7            (0x080U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x00800000 */
#define FLASH_OPTCR1_nWRP_8            (0x100U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x01000000 */
#define FLASH_OPTCR1_nWRP_9            (0x200U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x02000000 */
#define FLASH_OPTCR1_nWRP_10           (0x400U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x04000000 */
#define FLASH_OPTCR1_nWRP_11           (0x800U << FLASH_OPTCR1_nWRP_Pos)       /*!< 0x08000000 */

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                   (0U)
#define RCC_CR_HSION_Msk                   (0x1U << RCC_CR_HSION_Pos)          /*!< 0x00000001 */
#define RCC_CR_HSION                       RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos                  (1U)
#define RCC_CR_HSIRDY_Msk                  (0x1U << RCC_CR_HSIRDY_Pos)         /*!< 0x00000002 */
#define RCC_CR_HSIRDY                      RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos                 (3U)
#define RCC_CR_HSITRIM_Msk                 (0x1FU << RCC_CR_HSITRIM_Pos)       /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                     RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0                   (0x01U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                   (0x02U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                   (0x04U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                   (0x08U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                   (0x10U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos                  (8U)
#define RCC_CR_HSICAL_Msk                  (0xFFU << RCC_CR_HSICAL_Pos)        /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                      RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0                    (0x01U << RCC_CR_HSICAL_Pos)        /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                    (0x02U << RCC_CR_HSICAL_Pos)        /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                    (0x04U << RCC_CR_HSICAL_Pos)        /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                    (0x08U << RCC_CR_HSICAL_Pos)        /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                    (0x10U << RCC_CR_HSICAL_Pos)        /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                    (0x20U << RCC_CR_HSICAL_Pos)        /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                    (0x40U << RCC_CR_HSICAL_Pos)        /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                    (0x80U << RCC_CR_HSICAL_Pos)        /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                   (16U)
#define RCC_CR_HSEON_Msk                   (0x1U << RCC_CR_HSEON_Pos)          /*!< 0x00010000 */
#define RCC_CR_HSEON                       RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos                  (17U)
#define RCC_CR_HSERDY_Msk                  (0x1U << RCC_CR_HSERDY_Pos)         /*!< 0x00020000 */
#define RCC_CR_HSERDY                      RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos                  (18U)
#define RCC_CR_HSEBYP_Msk                  (0x1U << RCC_CR_HSEBYP_Pos)         /*!< 0x00040000 */
#define RCC_CR_HSEBYP                      RCC_CR_HSEBYP_Msk
#define RCC_CR_CSSON_Pos                   (19U)
#define RCC_CR_CSSON_Msk                   (0x1U << RCC_CR_CSSON_Pos)          /*!< 0x00080000 */
#define RCC_CR_CSSON                       RCC_CR_CSSON_Msk
#define RCC_CR_PLLON_Pos                   (24U)
#define RCC_CR_PLLON_Msk                   (0x1U << RCC_CR_PLLON_Pos)          /*!< 0x01000000 */
#define RCC_CR_PLLON                       RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos                  (25U)
#define RCC_CR_PLLRDY_Msk                  (0x1U << RCC_CR_PLLRDY_Pos)         /*!< 0x02000000 */
#define RCC_CR_PLLRDY                      RCC_CR_PLLRDY_Msk
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_PLLI2S_SUPPORT                                                     /*!< Support PLLI2S oscillator */

#define RCC_CR_PLLI2SON_Pos                (26U)
#define RCC_CR_PLLI2SON_Msk                (0x1U << RCC_CR_PLLI2SON_Pos)       /*!< 0x04000000 */
#define RCC_CR_PLLI2SON                    RCC_CR_PLLI2SON_Msk
#define RCC_CR_PLLI2SRDY_Pos               (27U)
#define RCC_CR_PLLI2SRDY_Msk               (0x1U << RCC_CR_PLLI2SRDY_Pos)      /*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY                   RCC_CR_PLLI2SRDY_Msk

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos               (0U)
#define RCC_PLLCFGR_PLLM_Msk               (0x3FU << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0                 (0x01U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1                 (0x02U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2                 (0x04U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3                 (0x08U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4                 (0x10U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5                 (0x20U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */

#define RCC_PLLCFGR_PLLN_Pos               (6U)
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFU << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0                 (0x001U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1                 (0x002U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2                 (0x004U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3                 (0x008U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4                 (0x010U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5                 (0x020U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6                 (0x040U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7                 (0x080U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8                 (0x100U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos               (16U)
#define RCC_PLLCFGR_PLLP_Msk               (0x3U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0                 (0x1U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1                 (0x2U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos             (22U)
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1U << RCC_PLLCFGR_PLLSRC_Pos)    /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1U << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U

#define RCC_PLLCFGR_PLLQ_Pos               (24U)
#define RCC_PLLCFGR_PLLQ_Msk               (0xFU << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0                 (0x1U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1                 (0x2U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2                 (0x4U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3                 (0x8U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x08000000 */


/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                    (0U)
#define RCC_CFGR_SW_Msk                    (0x3U << RCC_CFGR_SW_Pos)           /*!< 0x00000003 */
#define RCC_CFGR_SW                        RCC_CFGR_SW_Msk                     /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                      (0x1U << RCC_CFGR_SW_Pos)           /*!< 0x00000001 */
#define RCC_CFGR_SW_1                      (0x2U << RCC_CFGR_SW_Pos)           /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                    0x00000000U                         /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                    0x00000001U                         /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                    0x00000002U                         /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                   (2U)
#define RCC_CFGR_SWS_Msk                   (0x3U << RCC_CFGR_SWS_Pos)          /*!< 0x0000000C */
#define RCC_CFGR_SWS                       RCC_CFGR_SWS_Msk                    /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                     (0x1U << RCC_CFGR_SWS_Pos)          /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                     (0x2U << RCC_CFGR_SWS_Pos)          /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                   0x00000000U                         /*!< HSI oscillator used as system clock        */
#define RCC_CFGR_SWS_HSE                   0x00000004U                         /*!< HSE oscillator used as system clock        */
#define RCC_CFGR_SWS_PLL                   0x00000008U                         /*!< PLL used as system clock                   */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                  (4U)
#define RCC_CFGR_HPRE_Msk                  (0xFU << RCC_CFGR_HPRE_Pos)         /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                      RCC_CFGR_HPRE_Msk                   /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                    (0x1U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                    (0x2U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                    (0x4U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                    (0x8U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                 0x00000000U                         /*!< SYSCLK not divided    */
#define RCC_CFGR_HPRE_DIV2                 0x00000080U                         /*!< SYSCLK divided by 2   */
#define RCC_CFGR_HPRE_DIV4                 0x00000090U                         /*!< SYSCLK divided by 4   */
#define RCC_CFGR_HPRE_DIV8                 0x000000A0U                         /*!< SYSCLK divided by 8   */
#define RCC_CFGR_HPRE_DIV16                0x000000B0U                         /*!< SYSCLK divided by 16  */
#define RCC_CFGR_HPRE_DIV64                0x000000C0U                         /*!< SYSCLK divided by 64  */
#define RCC_CFGR_HPRE_DIV128               0x000000D0U                         /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256               0x000000E0U                         /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512               0x000000F0U                         /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                 (10U)
#define RCC_CFGR_PPRE1_Msk                 (0x7U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001C00 */
#define RCC_CFGR_PPRE1                     RCC_CFGR_PPRE1_Msk                  /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                   (0x1U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1                   (0x2U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2                   (0x4U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001000 */

#define RCC_CFGR_PPRE1_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE1_DIV2                0x00001000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE1_DIV8                0x00001800U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE1_DIV16               0x00001C00U                         /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                 (13U)
#define RCC_CFGR_PPRE2_Msk                 (0x7U << RCC_CFGR_PPRE2_Pos)        /*!< 0x0000E000 */
#define RCC_CFGR_PPRE2                     RCC_CFGR_PPRE2_Msk                  /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                   (0x1U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1                   (0x2U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2                   (0x4U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00008000 */

#define RCC_CFGR_PPRE2_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE2_DIV2                0x00008000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE2_DIV4                0x0000A000U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE2_DIV8                0x0000C000U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE2_DIV16               0x0000E000U                         /*!< HCLK divided by 16 */

/*!< RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos                (16U)
#define RCC_CFGR_RTCPRE_Msk                (0x1FU << RCC_CFGR_RTCPRE_Pos)      /*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE                    RCC_CFGR_RTCPRE_Msk
#define RCC_CFGR_RTCPRE_0                  (0x01U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1                  (0x02U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2                  (0x04U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3                  (0x08U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4                  (0x10U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00100000 */

/*!< MCO1 configuration */
#define RCC_CFGR_MCO1_Pos                  (21U)
#define RCC_CFGR_MCO1_Msk                  (0x3U << RCC_CFGR_MCO1_Pos)         /*!< 0x00600000 */
#define RCC_CFGR_MCO1                      RCC_CFGR_MCO1_Msk
#define RCC_CFGR_MCO1_0                    (0x1U << RCC_CFGR_MCO1_Pos)         /*!< 0x00200000 */
#define RCC_CFGR_MCO1_1                    (0x2U << RCC_CFGR_MCO1_Pos)         /*!< 0x00400000 */

#define RCC_CFGR_I2SSRC_Pos                (23U)
#define RCC_CFGR_I2SSRC_Msk                (0x1U << RCC_CFGR_I2SSRC_Pos)       /*!< 0x00800000 */
#define RCC_CFGR_I2SSRC                    RCC_CFGR_I2SSRC_Msk

#define RCC_CFGR_MCO1PRE_Pos               (24U)
#define RCC_CFGR_MCO1PRE_Msk               (0x7U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE                   RCC_CFGR_MCO1PRE_Msk
#define RCC_CFGR_MCO1PRE_0                 (0x1U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1                 (0x2U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2                 (0x4U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x04000000 */

#define RCC_CFGR_MCO2PRE_Pos               (27U)
#define RCC_CFGR_MCO2PRE_Msk               (0x7U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE                   RCC_CFGR_MCO2PRE_Msk
#define RCC_CFGR_MCO2PRE_0                 (0x1U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1                 (0x2U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2                 (0x4U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x20000000 */

#define RCC_CFGR_MCO2_Pos                  (30U)
#define RCC_CFGR_MCO2_Msk                  (0x3U << RCC_CFGR_MCO2_Pos)         /*!< 0xC0000000 */
#define RCC_CFGR_MCO2                      RCC_CFGR_MCO2_Msk
#define RCC_CFGR_MCO2_0                    (0x1U << RCC_CFGR_MCO2_Pos)         /*!< 0x40000000 */
#define RCC_CFGR_MCO2_1                    (0x2U << RCC_CFGR_MCO2_Pos)         /*!< 0x80000000 */

/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF_Pos                (0U)
#define RCC_CIR_LSIRDYF_Msk                (0x1U << RCC_CIR_LSIRDYF_Pos)       /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                    RCC_CIR_LSIRDYF_Msk
#define RCC_CIR_LSERDYF_Pos                (1U)
#define RCC_CIR_LSERDYF_Msk                (0x1U << RCC_CIR_LSERDYF_Pos)       /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                    RCC_CIR_LSERDYF_Msk
#define RCC_CIR_HSIRDYF_Pos                (2U)
#define RCC_CIR_HSIRDYF_Msk                (0x1U << RCC_CIR_HSIRDYF_Pos)       /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                    RCC_CIR_HSIRDYF_Msk
#define RCC_CIR_HSERDYF_Pos                (3U)
#define RCC_CIR_HSERDYF_Msk                (0x1U << RCC_CIR_HSERDYF_Pos)       /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                    RCC_CIR_HSERDYF_Msk
#define RCC_CIR_PLLRDYF_Pos                (4U)
#define RCC_CIR_PLLRDYF_Msk                (0x1U << RCC_CIR_PLLRDYF_Pos)       /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                    RCC_CIR_PLLRDYF_Msk
#define RCC_CIR_PLLI2SRDYF_Pos             (5U)
#define RCC_CIR_PLLI2SRDYF_Msk             (0x1U << RCC_CIR_PLLI2SRDYF_Pos)    /*!< 0x00000020 */
#define RCC_CIR_PLLI2SRDYF                 RCC_CIR_PLLI2SRDYF_Msk

#define RCC_CIR_CSSF_Pos                   (7U)
#define RCC_CIR_CSSF_Msk                   (0x1U << RCC_CIR_CSSF_Pos)          /*!< 0x00000080 */
#define RCC_CIR_CSSF                       RCC_CIR_CSSF_Msk
#define RCC_CIR_LSIRDYIE_Pos               (8U)
#define RCC_CIR_LSIRDYIE_Msk               (0x1U << RCC_CIR_LSIRDYIE_Pos)      /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                   RCC_CIR_LSIRDYIE_Msk
#define RCC_CIR_LSERDYIE_Pos               (9U)
#define RCC_CIR_LSERDYIE_Msk               (0x1U << RCC_CIR_LSERDYIE_Pos)      /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                   RCC_CIR_LSERDYIE_Msk
#define RCC_CIR_HSIRDYIE_Pos               (10U)
#define RCC_CIR_HSIRDYIE_Msk               (0x1U << RCC_CIR_HSIRDYIE_Pos)      /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                   RCC_CIR_HSIRDYIE_Msk
#define RCC_CIR_HSERDYIE_Pos               (11U)
#define RCC_CIR_HSERDYIE_Msk               (0x1U << RCC_CIR_HSERDYIE_Pos)      /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                   RCC_CIR_HSERDYIE_Msk
#define RCC_CIR_PLLRDYIE_Pos               (12U)
#define RCC_CIR_PLLRDYIE_Msk               (0x1U << RCC_CIR_PLLRDYIE_Pos)      /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                   RCC_CIR_PLLRDYIE_Msk
#define RCC_CIR_PLLI2SRDYIE_Pos            (13U)
#define RCC_CIR_PLLI2SRDYIE_Msk            (0x1U << RCC_CIR_PLLI2SRDYIE_Pos)   /*!< 0x00002000 */
#define RCC_CIR_PLLI2SRDYIE                RCC_CIR_PLLI2SRDYIE_Msk

#define RCC_CIR_LSIRDYC_Pos                (16U)
#define RCC_CIR_LSIRDYC_Msk                (0x1U << RCC_CIR_LSIRDYC_Pos)       /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                    RCC_CIR_LSIRDYC_Msk
#define RCC_CIR_LSERDYC_Pos                (17U)
#define RCC_CIR_LSERDYC_Msk                (0x1U << RCC_CIR_LSERDYC_Pos)       /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                    RCC_CIR_LSERDYC_Msk
#define RCC_CIR_HSIRDYC_Pos                (18U)
#define RCC_CIR_HSIRDYC_Msk                (0x1U << RCC_CIR_HSIRDYC_Pos)       /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                    RCC_CIR_HSIRDYC_Msk
#define RCC_CIR_HSERDYC_Pos                (19U)
#define RCC_CIR_HSERDYC_Msk                (0x1U << RCC_CIR_HSERDYC_Pos)       /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                    RCC_CIR_HSERDYC_Msk
#define RCC_CIR_PLLRDYC_Pos                (20U)
#define RCC_CIR_PLLRDYC_Msk                (0x1U << RCC_CIR_PLLRDYC_Pos)       /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                    RCC_CIR_PLLRDYC_Msk
#define RCC_CIR_PLLI2SRDYC_Pos             (21U)
#define RCC_CIR_PLLI2SRDYC_Msk             (0x1U << RCC_CIR_PLLI2SRDYC_Pos)    /*!< 0x00200000 */
#define RCC_CIR_PLLI2SRDYC                 RCC_CIR_PLLI2SRDYC_Msk

#define RCC_CIR_CSSC_Pos                   (23U)
#define RCC_CIR_CSSC_Msk                   (0x1U << RCC_CIR_CSSC_Pos)          /*!< 0x00800000 */
#define RCC_CIR_CSSC                       RCC_CIR_CSSC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST_Pos          (0U)
#define RCC_AHB1RSTR_GPIOARST_Msk          (0x1U << RCC_AHB1RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_GPIOARST              RCC_AHB1RSTR_GPIOARST_Msk
#define RCC_AHB1RSTR_GPIOBRST_Pos          (1U)
#define RCC_AHB1RSTR_GPIOBRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB1RSTR_GPIOBRST              RCC_AHB1RSTR_GPIOBRST_Msk
#define RCC_AHB1RSTR_GPIOCRST_Pos          (2U)
#define RCC_AHB1RSTR_GPIOCRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB1RSTR_GPIOCRST              RCC_AHB1RSTR_GPIOCRST_Msk
#define RCC_AHB1RSTR_GPIODRST_Pos          (3U)
#define RCC_AHB1RSTR_GPIODRST_Msk          (0x1U << RCC_AHB1RSTR_GPIODRST_Pos) /*!< 0x00000008 */
#define RCC_AHB1RSTR_GPIODRST              RCC_AHB1RSTR_GPIODRST_Msk
#define RCC_AHB1RSTR_GPIOERST_Pos          (4U)
#define RCC_AHB1RSTR_GPIOERST_Msk          (0x1U << RCC_AHB1RSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHB1RSTR_GPIOERST              RCC_AHB1RSTR_GPIOERST_Msk
#define RCC_AHB1RSTR_GPIOFRST_Pos          (5U)
#define RCC_AHB1RSTR_GPIOFRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOFRST_Pos) /*!< 0x00000020 */
#define RCC_AHB1RSTR_GPIOFRST              RCC_AHB1RSTR_GPIOFRST_Msk
#define RCC_AHB1RSTR_GPIOGRST_Pos          (6U)
#define RCC_AHB1RSTR_GPIOGRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOGRST_Pos) /*!< 0x00000040 */
#define RCC_AHB1RSTR_GPIOGRST              RCC_AHB1RSTR_GPIOGRST_Msk
#define RCC_AHB1RSTR_GPIOHRST_Pos          (7U)
#define RCC_AHB1RSTR_GPIOHRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB1RSTR_GPIOHRST              RCC_AHB1RSTR_GPIOHRST_Msk
#define RCC_AHB1RSTR_GPIOIRST_Pos          (8U)
#define RCC_AHB1RSTR_GPIOIRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOIRST_Pos) /*!< 0x00000100 */
#define RCC_AHB1RSTR_GPIOIRST              RCC_AHB1RSTR_GPIOIRST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos            (12U)
#define RCC_AHB1RSTR_CRCRST_Msk            (0x1U << RCC_AHB1RSTR_CRCRST_Pos)   /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_DMA1RST_Pos           (21U)
#define RCC_AHB1RSTR_DMA1RST_Msk           (0x1U << RCC_AHB1RSTR_DMA1RST_Pos)  /*!< 0x00200000 */
#define RCC_AHB1RSTR_DMA1RST               RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMA2RST_Pos           (22U)
#define RCC_AHB1RSTR_DMA2RST_Msk           (0x1U << RCC_AHB1RSTR_DMA2RST_Pos)  /*!< 0x00400000 */
#define RCC_AHB1RSTR_DMA2RST               RCC_AHB1RSTR_DMA2RST_Msk
#define RCC_AHB1RSTR_ETHMACRST_Pos         (25U)
#define RCC_AHB1RSTR_ETHMACRST_Msk         (0x1U << RCC_AHB1RSTR_ETHMACRST_Pos) /*!< 0x02000000 */
#define RCC_AHB1RSTR_ETHMACRST             RCC_AHB1RSTR_ETHMACRST_Msk
#define RCC_AHB1RSTR_OTGHRST_Pos           (29U)
#define RCC_AHB1RSTR_OTGHRST_Msk           (0x1U << RCC_AHB1RSTR_OTGHRST_Pos)  /*!< 0x20000000 */
#define RCC_AHB1RSTR_OTGHRST               RCC_AHB1RSTR_OTGHRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_DCMIRST_Pos           (0U)
#define RCC_AHB2RSTR_DCMIRST_Msk           (0x1U << RCC_AHB2RSTR_DCMIRST_Pos)  /*!< 0x00000001 */
#define RCC_AHB2RSTR_DCMIRST               RCC_AHB2RSTR_DCMIRST_Msk
#define RCC_AHB2RSTR_RNGRST_Pos            (6U)
#define RCC_AHB2RSTR_RNGRST_Msk            (0x1U << RCC_AHB2RSTR_RNGRST_Pos)   /*!< 0x00000040 */
#define RCC_AHB2RSTR_RNGRST                RCC_AHB2RSTR_RNGRST_Msk
#define RCC_AHB2RSTR_OTGFSRST_Pos          (7U)
#define RCC_AHB2RSTR_OTGFSRST_Msk          (0x1U << RCC_AHB2RSTR_OTGFSRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_OTGFSRST              RCC_AHB2RSTR_OTGFSRST_Msk
/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FSMCRST_Pos           (0U)
#define RCC_AHB3RSTR_FSMCRST_Msk           (0x1U << RCC_AHB3RSTR_FSMCRST_Pos)  /*!< 0x00000001 */
#define RCC_AHB3RSTR_FSMCRST               RCC_AHB3RSTR_FSMCRST_Msk


/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST_Pos           (0U)
#define RCC_APB1RSTR_TIM2RST_Msk           (0x1U << RCC_APB1RSTR_TIM2RST_Pos)  /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST               RCC_APB1RSTR_TIM2RST_Msk
#define RCC_APB1RSTR_TIM3RST_Pos           (1U)
#define RCC_APB1RSTR_TIM3RST_Msk           (0x1U << RCC_APB1RSTR_TIM3RST_Pos)  /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST               RCC_APB1RSTR_TIM3RST_Msk
#define RCC_APB1RSTR_TIM4RST_Pos           (2U)
#define RCC_APB1RSTR_TIM4RST_Msk           (0x1U << RCC_APB1RSTR_TIM4RST_Pos)  /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST               RCC_APB1RSTR_TIM4RST_Msk
#define RCC_APB1RSTR_TIM5RST_Pos           (3U)
#define RCC_APB1RSTR_TIM5RST_Msk           (0x1U << RCC_APB1RSTR_TIM5RST_Pos)  /*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST               RCC_APB1RSTR_TIM5RST_Msk
#define RCC_APB1RSTR_TIM6RST_Pos           (4U)
#define RCC_APB1RSTR_TIM6RST_Msk           (0x1U << RCC_APB1RSTR_TIM6RST_Pos)  /*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST               RCC_APB1RSTR_TIM6RST_Msk
#define RCC_APB1RSTR_TIM7RST_Pos           (5U)
#define RCC_APB1RSTR_TIM7RST_Msk           (0x1U << RCC_APB1RSTR_TIM7RST_Pos)  /*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST               RCC_APB1RSTR_TIM7RST_Msk
#define RCC_APB1RSTR_TIM12RST_Pos          (6U)
#define RCC_APB1RSTR_TIM12RST_Msk          (0x1U << RCC_APB1RSTR_TIM12RST_Pos) /*!< 0x00000040 */
#define RCC_APB1RSTR_TIM12RST              RCC_APB1RSTR_TIM12RST_Msk
#define RCC_APB1RSTR_TIM13RST_Pos          (7U)
#define RCC_APB1RSTR_TIM13RST_Msk          (0x1U << RCC_APB1RSTR_TIM13RST_Pos) /*!< 0x00000080 */
#define RCC_APB1RSTR_TIM13RST              RCC_APB1RSTR_TIM13RST_Msk
#define RCC_APB1RSTR_TIM14RST_Pos          (8U)
#define RCC_APB1RSTR_TIM14RST_Msk          (0x1U << RCC_APB1RSTR_TIM14RST_Pos) /*!< 0x00000100 */
#define RCC_APB1RSTR_TIM14RST              RCC_APB1RSTR_TIM14RST_Msk
#define RCC_APB1RSTR_WWDGRST_Pos           (11U)
#define RCC_APB1RSTR_WWDGRST_Msk           (0x1U << RCC_APB1RSTR_WWDGRST_Pos)  /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST               RCC_APB1RSTR_WWDGRST_Msk
#define RCC_APB1RSTR_SPI2RST_Pos           (14U)
#define RCC_APB1RSTR_SPI2RST_Msk           (0x1U << RCC_APB1RSTR_SPI2RST_Pos)  /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST               RCC_APB1RSTR_SPI2RST_Msk
#define RCC_APB1RSTR_SPI3RST_Pos           (15U)
#define RCC_APB1RSTR_SPI3RST_Msk           (0x1U << RCC_APB1RSTR_SPI3RST_Pos)  /*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST               RCC_APB1RSTR_SPI3RST_Msk
#define RCC_APB1RSTR_USART2RST_Pos         (17U)
#define RCC_APB1RSTR_USART2RST_Msk         (0x1U << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST             RCC_APB1RSTR_USART2RST_Msk
#define RCC_APB1RSTR_USART3RST_Pos         (18U)
#define RCC_APB1RSTR_USART3RST_Msk         (0x1U << RCC_APB1RSTR_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST             RCC_APB1RSTR_USART3RST_Msk
#define RCC_APB1RSTR_UART4RST_Pos          (19U)
#define RCC_APB1RSTR_UART4RST_Msk          (0x1U << RCC_APB1RSTR_UART4RST_Pos) /*!< 0x00080000 */
#define RCC_APB1RSTR_UART4RST              RCC_APB1RSTR_UART4RST_Msk
#define RCC_APB1RSTR_UART5RST_Pos          (20U)
#define RCC_APB1RSTR_UART5RST_Msk          (0x1U << RCC_APB1RSTR_UART5RST_Pos) /*!< 0x00100000 */
#define RCC_APB1RSTR_UART5RST              RCC_APB1RSTR_UART5RST_Msk
#define RCC_APB1RSTR_I2C1RST_Pos           (21U)
#define RCC_APB1RSTR_I2C1RST_Msk           (0x1U << RCC_APB1RSTR_I2C1RST_Pos)  /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST               RCC_APB1RSTR_I2C1RST_Msk
#define RCC_APB1RSTR_I2C2RST_Pos           (22U)
#define RCC_APB1RSTR_I2C2RST_Msk           (0x1U << RCC_APB1RSTR_I2C2RST_Pos)  /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST               RCC_APB1RSTR_I2C2RST_Msk
#define RCC_APB1RSTR_I2C3RST_Pos           (23U)
#define RCC_APB1RSTR_I2C3RST_Msk           (0x1U << RCC_APB1RSTR_I2C3RST_Pos)  /*!< 0x00800000 */
#define RCC_APB1RSTR_I2C3RST               RCC_APB1RSTR_I2C3RST_Msk
#define RCC_APB1RSTR_CAN1RST_Pos           (25U)
#define RCC_APB1RSTR_CAN1RST_Msk           (0x1U << RCC_APB1RSTR_CAN1RST_Pos)  /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST               RCC_APB1RSTR_CAN1RST_Msk
#define RCC_APB1RSTR_CAN2RST_Pos           (26U)
#define RCC_APB1RSTR_CAN2RST_Msk           (0x1U << RCC_APB1RSTR_CAN2RST_Pos)  /*!< 0x04000000 */
#define RCC_APB1RSTR_CAN2RST               RCC_APB1RSTR_CAN2RST_Msk
#define RCC_APB1RSTR_PWRRST_Pos            (28U)
#define RCC_APB1RSTR_PWRRST_Msk            (0x1U << RCC_APB1RSTR_PWRRST_Pos)   /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                RCC_APB1RSTR_PWRRST_Msk
#define RCC_APB1RSTR_DACRST_Pos            (29U)
#define RCC_APB1RSTR_DACRST_Msk            (0x1U << RCC_APB1RSTR_DACRST_Pos)   /*!< 0x20000000 */
#define RCC_APB1RSTR_DACRST                RCC_APB1RSTR_DACRST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos           (0U)
#define RCC_APB2RSTR_TIM1RST_Msk           (0x1U << RCC_APB2RSTR_TIM1RST_Pos)  /*!< 0x00000001 */
#define RCC_APB2RSTR_TIM1RST               RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_TIM8RST_Pos           (1U)
#define RCC_APB2RSTR_TIM8RST_Msk           (0x1U << RCC_APB2RSTR_TIM8RST_Pos)  /*!< 0x00000002 */
#define RCC_APB2RSTR_TIM8RST               RCC_APB2RSTR_TIM8RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos         (4U)
#define RCC_APB2RSTR_USART1RST_Msk         (0x1U << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_USART1RST             RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_USART6RST_Pos         (5U)
#define RCC_APB2RSTR_USART6RST_Msk         (0x1U << RCC_APB2RSTR_USART6RST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST             RCC_APB2RSTR_USART6RST_Msk
#define RCC_APB2RSTR_ADCRST_Pos            (8U)
#define RCC_APB2RSTR_ADCRST_Msk            (0x1U << RCC_APB2RSTR_ADCRST_Pos)   /*!< 0x00000100 */
#define RCC_APB2RSTR_ADCRST                RCC_APB2RSTR_ADCRST_Msk
#define RCC_APB2RSTR_SDIORST_Pos           (11U)
#define RCC_APB2RSTR_SDIORST_Msk           (0x1U << RCC_APB2RSTR_SDIORST_Pos)  /*!< 0x00000800 */
#define RCC_APB2RSTR_SDIORST               RCC_APB2RSTR_SDIORST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos           (12U)
#define RCC_APB2RSTR_SPI1RST_Msk           (0x1U << RCC_APB2RSTR_SPI1RST_Pos)  /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST               RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_SYSCFGRST_Pos         (14U)
#define RCC_APB2RSTR_SYSCFGRST_Msk         (0x1U << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_SYSCFGRST             RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_TIM9RST_Pos           (16U)
#define RCC_APB2RSTR_TIM9RST_Msk           (0x1U << RCC_APB2RSTR_TIM9RST_Pos)  /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM9RST               RCC_APB2RSTR_TIM9RST_Msk
#define RCC_APB2RSTR_TIM10RST_Pos          (17U)
#define RCC_APB2RSTR_TIM10RST_Msk          (0x1U << RCC_APB2RSTR_TIM10RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM10RST              RCC_APB2RSTR_TIM10RST_Msk
#define RCC_APB2RSTR_TIM11RST_Pos          (18U)
#define RCC_APB2RSTR_TIM11RST_Msk          (0x1U << RCC_APB2RSTR_TIM11RST_Pos) /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM11RST              RCC_APB2RSTR_TIM11RST_Msk

/* Old SPI1RST bit definition, maintained for legacy purpose */
#define  RCC_APB2RSTR_SPI1                   RCC_APB2RSTR_SPI1RST

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN_Pos            (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk            (0x1U << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
#define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk
#define RCC_AHB1ENR_GPIOBEN_Pos            (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk            (0x1U << RCC_AHB1ENR_GPIOBEN_Pos)   /*!< 0x00000002 */
#define RCC_AHB1ENR_GPIOBEN                RCC_AHB1ENR_GPIOBEN_Msk
#define RCC_AHB1ENR_GPIOCEN_Pos            (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk            (0x1U << RCC_AHB1ENR_GPIOCEN_Pos)   /*!< 0x00000004 */
#define RCC_AHB1ENR_GPIOCEN                RCC_AHB1ENR_GPIOCEN_Msk
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1U << RCC_AHB1ENR_GPIODEN_Pos)   /*!< 0x00000008 */
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk
#define RCC_AHB1ENR_GPIOEEN_Pos            (4U)
#define RCC_AHB1ENR_GPIOEEN_Msk            (0x1U << RCC_AHB1ENR_GPIOEEN_Pos)   /*!< 0x00000010 */
#define RCC_AHB1ENR_GPIOEEN                RCC_AHB1ENR_GPIOEEN_Msk
#define RCC_AHB1ENR_GPIOFEN_Pos            (5U)
#define RCC_AHB1ENR_GPIOFEN_Msk            (0x1U << RCC_AHB1ENR_GPIOFEN_Pos)   /*!< 0x00000020 */
#define RCC_AHB1ENR_GPIOFEN                RCC_AHB1ENR_GPIOFEN_Msk
#define RCC_AHB1ENR_GPIOGEN_Pos            (6U)
#define RCC_AHB1ENR_GPIOGEN_Msk            (0x1U << RCC_AHB1ENR_GPIOGEN_Pos)   /*!< 0x00000040 */
#define RCC_AHB1ENR_GPIOGEN                RCC_AHB1ENR_GPIOGEN_Msk
#define RCC_AHB1ENR_GPIOHEN_Pos            (7U)
#define RCC_AHB1ENR_GPIOHEN_Msk            (0x1U << RCC_AHB1ENR_GPIOHEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB1ENR_GPIOHEN                RCC_AHB1ENR_GPIOHEN_Msk
#define RCC_AHB1ENR_GPIOIEN_Pos            (8U)
#define RCC_AHB1ENR_GPIOIEN_Msk            (0x1U << RCC_AHB1ENR_GPIOIEN_Pos)   /*!< 0x00000100 */
#define RCC_AHB1ENR_GPIOIEN                RCC_AHB1ENR_GPIOIEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos              (12U)
#define RCC_AHB1ENR_CRCEN_Msk              (0x1U << RCC_AHB1ENR_CRCEN_Pos)     /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                  RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_BKPSRAMEN_Pos          (18U)
#define RCC_AHB1ENR_BKPSRAMEN_Msk          (0x1U << RCC_AHB1ENR_BKPSRAMEN_Pos) /*!< 0x00040000 */
#define RCC_AHB1ENR_BKPSRAMEN              RCC_AHB1ENR_BKPSRAMEN_Msk
#define RCC_AHB1ENR_CCMDATARAMEN_Pos       (20U)
#define RCC_AHB1ENR_CCMDATARAMEN_Msk       (0x1U << RCC_AHB1ENR_CCMDATARAMEN_Pos) /*!< 0x00100000 */
#define RCC_AHB1ENR_CCMDATARAMEN           RCC_AHB1ENR_CCMDATARAMEN_Msk
#define RCC_AHB1ENR_DMA1EN_Pos             (21U)
#define RCC_AHB1ENR_DMA1EN_Msk             (0x1U << RCC_AHB1ENR_DMA1EN_Pos)    /*!< 0x00200000 */
#define RCC_AHB1ENR_DMA1EN                 RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMA2EN_Pos             (22U)
#define RCC_AHB1ENR_DMA2EN_Msk             (0x1U << RCC_AHB1ENR_DMA2EN_Pos)    /*!< 0x00400000 */
#define RCC_AHB1ENR_DMA2EN                 RCC_AHB1ENR_DMA2EN_Msk
#define RCC_AHB1ENR_ETHMACEN_Pos           (25U)
#define RCC_AHB1ENR_ETHMACEN_Msk           (0x1U << RCC_AHB1ENR_ETHMACEN_Pos)  /*!< 0x02000000 */
#define RCC_AHB1ENR_ETHMACEN               RCC_AHB1ENR_ETHMACEN_Msk
#define RCC_AHB1ENR_ETHMACTXEN_Pos         (26U)
#define RCC_AHB1ENR_ETHMACTXEN_Msk         (0x1U << RCC_AHB1ENR_ETHMACTXEN_Pos) /*!< 0x04000000 */
#define RCC_AHB1ENR_ETHMACTXEN             RCC_AHB1ENR_ETHMACTXEN_Msk
#define RCC_AHB1ENR_ETHMACRXEN_Pos         (27U)
#define RCC_AHB1ENR_ETHMACRXEN_Msk         (0x1U << RCC_AHB1ENR_ETHMACRXEN_Pos) /*!< 0x08000000 */
#define RCC_AHB1ENR_ETHMACRXEN             RCC_AHB1ENR_ETHMACRXEN_Msk
#define RCC_AHB1ENR_ETHMACPTPEN_Pos        (28U)
#define RCC_AHB1ENR_ETHMACPTPEN_Msk        (0x1U << RCC_AHB1ENR_ETHMACPTPEN_Pos) /*!< 0x10000000 */
#define RCC_AHB1ENR_ETHMACPTPEN            RCC_AHB1ENR_ETHMACPTPEN_Msk
#define RCC_AHB1ENR_OTGHSEN_Pos            (29U)
#define RCC_AHB1ENR_OTGHSEN_Msk            (0x1U << RCC_AHB1ENR_OTGHSEN_Pos)   /*!< 0x20000000 */
#define RCC_AHB1ENR_OTGHSEN                RCC_AHB1ENR_OTGHSEN_Msk
#define RCC_AHB1ENR_OTGHSULPIEN_Pos        (30U)
#define RCC_AHB1ENR_OTGHSULPIEN_Msk        (0x1U << RCC_AHB1ENR_OTGHSULPIEN_Pos) /*!< 0x40000000 */
#define RCC_AHB1ENR_OTGHSULPIEN            RCC_AHB1ENR_OTGHSULPIEN_Msk
/********************  Bit definition for RCC_AHB2ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_AHB2_SUPPORT                   /*!< AHB2 Bus is supported */

#define RCC_AHB2ENR_DCMIEN_Pos             (0U)
#define RCC_AHB2ENR_DCMIEN_Msk             (0x1U << RCC_AHB2ENR_DCMIEN_Pos)    /*!< 0x00000001 */
#define RCC_AHB2ENR_DCMIEN                 RCC_AHB2ENR_DCMIEN_Msk
#define RCC_AHB2ENR_RNGEN_Pos              (6U)
#define RCC_AHB2ENR_RNGEN_Msk              (0x1U << RCC_AHB2ENR_RNGEN_Pos)     /*!< 0x00000040 */
#define RCC_AHB2ENR_RNGEN                  RCC_AHB2ENR_RNGEN_Msk
#define RCC_AHB2ENR_OTGFSEN_Pos            (7U)
#define RCC_AHB2ENR_OTGFSEN_Msk            (0x1U << RCC_AHB2ENR_OTGFSEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB2ENR_OTGFSEN                RCC_AHB2ENR_OTGFSEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_AHB3_SUPPORT                   /*!< AHB3 Bus is supported */

#define RCC_AHB3ENR_FSMCEN_Pos             (0U)
#define RCC_AHB3ENR_FSMCEN_Msk             (0x1U << RCC_AHB3ENR_FSMCEN_Pos)    /*!< 0x00000001 */
#define RCC_AHB3ENR_FSMCEN                 RCC_AHB3ENR_FSMCEN_Msk

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)
#define RCC_APB1ENR_TIM2EN_Msk             (0x1U << RCC_APB1ENR_TIM2EN_Pos)    /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk
#define RCC_APB1ENR_TIM3EN_Pos             (1U)
#define RCC_APB1ENR_TIM3EN_Msk             (0x1U << RCC_APB1ENR_TIM3EN_Pos)    /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk
#define RCC_APB1ENR_TIM4EN_Pos             (2U)
#define RCC_APB1ENR_TIM4EN_Msk             (0x1U << RCC_APB1ENR_TIM4EN_Pos)    /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk
#define RCC_APB1ENR_TIM5EN_Pos             (3U)
#define RCC_APB1ENR_TIM5EN_Msk             (0x1U << RCC_APB1ENR_TIM5EN_Pos)    /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk
#define RCC_APB1ENR_TIM6EN_Pos             (4U)
#define RCC_APB1ENR_TIM6EN_Msk             (0x1U << RCC_APB1ENR_TIM6EN_Pos)    /*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN                 RCC_APB1ENR_TIM6EN_Msk
#define RCC_APB1ENR_TIM7EN_Pos             (5U)
#define RCC_APB1ENR_TIM7EN_Msk             (0x1U << RCC_APB1ENR_TIM7EN_Pos)    /*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN                 RCC_APB1ENR_TIM7EN_Msk
#define RCC_APB1ENR_TIM12EN_Pos            (6U)
#define RCC_APB1ENR_TIM12EN_Msk            (0x1U << RCC_APB1ENR_TIM12EN_Pos)   /*!< 0x00000040 */
#define RCC_APB1ENR_TIM12EN                RCC_APB1ENR_TIM12EN_Msk
#define RCC_APB1ENR_TIM13EN_Pos            (7U)
#define RCC_APB1ENR_TIM13EN_Msk            (0x1U << RCC_APB1ENR_TIM13EN_Pos)   /*!< 0x00000080 */
#define RCC_APB1ENR_TIM13EN                RCC_APB1ENR_TIM13EN_Msk
#define RCC_APB1ENR_TIM14EN_Pos            (8U)
#define RCC_APB1ENR_TIM14EN_Msk            (0x1U << RCC_APB1ENR_TIM14EN_Pos)   /*!< 0x00000100 */
#define RCC_APB1ENR_TIM14EN                RCC_APB1ENR_TIM14EN_Msk
#define RCC_APB1ENR_WWDGEN_Pos             (11U)
#define RCC_APB1ENR_WWDGEN_Msk             (0x1U << RCC_APB1ENR_WWDGEN_Pos)    /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                 RCC_APB1ENR_WWDGEN_Msk
#define RCC_APB1ENR_SPI2EN_Pos             (14U)
#define RCC_APB1ENR_SPI2EN_Msk             (0x1U << RCC_APB1ENR_SPI2EN_Pos)    /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                 RCC_APB1ENR_SPI2EN_Msk
#define RCC_APB1ENR_SPI3EN_Pos             (15U)
#define RCC_APB1ENR_SPI3EN_Msk             (0x1U << RCC_APB1ENR_SPI3EN_Pos)    /*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN                 RCC_APB1ENR_SPI3EN_Msk
#define RCC_APB1ENR_USART2EN_Pos           (17U)
#define RCC_APB1ENR_USART2EN_Msk           (0x1U << RCC_APB1ENR_USART2EN_Pos)  /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk
#define RCC_APB1ENR_USART3EN_Pos           (18U)
#define RCC_APB1ENR_USART3EN_Msk           (0x1U << RCC_APB1ENR_USART3EN_Pos)  /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN               RCC_APB1ENR_USART3EN_Msk
#define RCC_APB1ENR_UART4EN_Pos            (19U)
#define RCC_APB1ENR_UART4EN_Msk            (0x1U << RCC_APB1ENR_UART4EN_Pos)   /*!< 0x00080000 */
#define RCC_APB1ENR_UART4EN                RCC_APB1ENR_UART4EN_Msk
#define RCC_APB1ENR_UART5EN_Pos            (20U)
#define RCC_APB1ENR_UART5EN_Msk            (0x1U << RCC_APB1ENR_UART5EN_Pos)   /*!< 0x00100000 */
#define RCC_APB1ENR_UART5EN                RCC_APB1ENR_UART5EN_Msk
#define RCC_APB1ENR_I2C1EN_Pos             (21U)
#define RCC_APB1ENR_I2C1EN_Msk             (0x1U << RCC_APB1ENR_I2C1EN_Pos)    /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                 RCC_APB1ENR_I2C1EN_Msk
#define RCC_APB1ENR_I2C2EN_Pos             (22U)
#define RCC_APB1ENR_I2C2EN_Msk             (0x1U << RCC_APB1ENR_I2C2EN_Pos)    /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                 RCC_APB1ENR_I2C2EN_Msk
#define RCC_APB1ENR_I2C3EN_Pos             (23U)
#define RCC_APB1ENR_I2C3EN_Msk             (0x1U << RCC_APB1ENR_I2C3EN_Pos)    /*!< 0x00800000 */
#define RCC_APB1ENR_I2C3EN                 RCC_APB1ENR_I2C3EN_Msk
#define RCC_APB1ENR_CAN1EN_Pos             (25U)
#define RCC_APB1ENR_CAN1EN_Msk             (0x1U << RCC_APB1ENR_CAN1EN_Pos)    /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN                 RCC_APB1ENR_CAN1EN_Msk
#define RCC_APB1ENR_CAN2EN_Pos             (26U)
#define RCC_APB1ENR_CAN2EN_Msk             (0x1U << RCC_APB1ENR_CAN2EN_Pos)    /*!< 0x04000000 */
#define RCC_APB1ENR_CAN2EN                 RCC_APB1ENR_CAN2EN_Msk
#define RCC_APB1ENR_PWREN_Pos              (28U)
#define RCC_APB1ENR_PWREN_Msk              (0x1U << RCC_APB1ENR_PWREN_Pos)     /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                  RCC_APB1ENR_PWREN_Msk
#define RCC_APB1ENR_DACEN_Pos              (29U)
#define RCC_APB1ENR_DACEN_Msk              (0x1U << RCC_APB1ENR_DACEN_Pos)     /*!< 0x20000000 */
#define RCC_APB1ENR_DACEN                  RCC_APB1ENR_DACEN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos             (0U)
#define RCC_APB2ENR_TIM1EN_Msk             (0x1U << RCC_APB2ENR_TIM1EN_Pos)    /*!< 0x00000001 */
#define RCC_APB2ENR_TIM1EN                 RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_TIM8EN_Pos             (1U)
#define RCC_APB2ENR_TIM8EN_Msk             (0x1U << RCC_APB2ENR_TIM8EN_Pos)    /*!< 0x00000002 */
#define RCC_APB2ENR_TIM8EN                 RCC_APB2ENR_TIM8EN_Msk
#define RCC_APB2ENR_USART1EN_Pos           (4U)
#define RCC_APB2ENR_USART1EN_Msk           (0x1U << RCC_APB2ENR_USART1EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_USART6EN_Pos           (5U)
#define RCC_APB2ENR_USART6EN_Msk           (0x1U << RCC_APB2ENR_USART6EN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN               RCC_APB2ENR_USART6EN_Msk
#define RCC_APB2ENR_ADC1EN_Pos             (8U)
#define RCC_APB2ENR_ADC1EN_Msk             (0x1U << RCC_APB2ENR_ADC1EN_Pos)    /*!< 0x00000100 */
#define RCC_APB2ENR_ADC1EN                 RCC_APB2ENR_ADC1EN_Msk
#define RCC_APB2ENR_ADC2EN_Pos             (9U)
#define RCC_APB2ENR_ADC2EN_Msk             (0x1U << RCC_APB2ENR_ADC2EN_Pos)    /*!< 0x00000200 */
#define RCC_APB2ENR_ADC2EN                 RCC_APB2ENR_ADC2EN_Msk
#define RCC_APB2ENR_ADC3EN_Pos             (10U)
#define RCC_APB2ENR_ADC3EN_Msk             (0x1U << RCC_APB2ENR_ADC3EN_Pos)    /*!< 0x00000400 */
#define RCC_APB2ENR_ADC3EN                 RCC_APB2ENR_ADC3EN_Msk
#define RCC_APB2ENR_SDIOEN_Pos             (11U)
#define RCC_APB2ENR_SDIOEN_Msk             (0x1U << RCC_APB2ENR_SDIOEN_Pos)    /*!< 0x00000800 */
#define RCC_APB2ENR_SDIOEN                 RCC_APB2ENR_SDIOEN_Msk
#define RCC_APB2ENR_SPI1EN_Pos             (12U)
#define RCC_APB2ENR_SPI1EN_Msk             (0x1U << RCC_APB2ENR_SPI1EN_Pos)    /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                 RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1U << RCC_APB2ENR_SYSCFGEN_Pos)  /*!< 0x00004000 */
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_TIM9EN_Pos             (16U)
#define RCC_APB2ENR_TIM9EN_Msk             (0x1U << RCC_APB2ENR_TIM9EN_Pos)    /*!< 0x00010000 */
#define RCC_APB2ENR_TIM9EN                 RCC_APB2ENR_TIM9EN_Msk
#define RCC_APB2ENR_TIM10EN_Pos            (17U)
#define RCC_APB2ENR_TIM10EN_Msk            (0x1U << RCC_APB2ENR_TIM10EN_Pos)   /*!< 0x00020000 */
#define RCC_APB2ENR_TIM10EN                RCC_APB2ENR_TIM10EN_Msk
#define RCC_APB2ENR_TIM11EN_Pos            (18U)
#define RCC_APB2ENR_TIM11EN_Msk            (0x1U << RCC_APB2ENR_TIM11EN_Pos)   /*!< 0x00040000 */
#define RCC_APB2ENR_TIM11EN                RCC_APB2ENR_TIM11EN_Msk

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos        (0U)
#define RCC_AHB1LPENR_GPIOALPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOALPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN            RCC_AHB1LPENR_GPIOALPEN_Msk
#define RCC_AHB1LPENR_GPIOBLPEN_Pos        (1U)
#define RCC_AHB1LPENR_GPIOBLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOBLPEN_Pos) /*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN            RCC_AHB1LPENR_GPIOBLPEN_Msk
#define RCC_AHB1LPENR_GPIOCLPEN_Pos        (2U)
#define RCC_AHB1LPENR_GPIOCLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOCLPEN_Pos) /*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN            RCC_AHB1LPENR_GPIOCLPEN_Msk
#define RCC_AHB1LPENR_GPIODLPEN_Pos        (3U)
#define RCC_AHB1LPENR_GPIODLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIODLPEN_Pos) /*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN            RCC_AHB1LPENR_GPIODLPEN_Msk
#define RCC_AHB1LPENR_GPIOELPEN_Pos        (4U)
#define RCC_AHB1LPENR_GPIOELPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOELPEN_Pos) /*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN            RCC_AHB1LPENR_GPIOELPEN_Msk
#define RCC_AHB1LPENR_GPIOFLPEN_Pos        (5U)
#define RCC_AHB1LPENR_GPIOFLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOFLPEN_Pos) /*!< 0x00000020 */
#define RCC_AHB1LPENR_GPIOFLPEN            RCC_AHB1LPENR_GPIOFLPEN_Msk
#define RCC_AHB1LPENR_GPIOGLPEN_Pos        (6U)
#define RCC_AHB1LPENR_GPIOGLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOGLPEN_Pos) /*!< 0x00000040 */
#define RCC_AHB1LPENR_GPIOGLPEN            RCC_AHB1LPENR_GPIOGLPEN_Msk
#define RCC_AHB1LPENR_GPIOHLPEN_Pos        (7U)
#define RCC_AHB1LPENR_GPIOHLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOHLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN            RCC_AHB1LPENR_GPIOHLPEN_Msk
#define RCC_AHB1LPENR_GPIOILPEN_Pos        (8U)
#define RCC_AHB1LPENR_GPIOILPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOILPEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1LPENR_GPIOILPEN            RCC_AHB1LPENR_GPIOILPEN_Msk
#define RCC_AHB1LPENR_CRCLPEN_Pos          (12U)
#define RCC_AHB1LPENR_CRCLPEN_Msk          (0x1U << RCC_AHB1LPENR_CRCLPEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN              RCC_AHB1LPENR_CRCLPEN_Msk
#define RCC_AHB1LPENR_FLITFLPEN_Pos        (15U)
#define RCC_AHB1LPENR_FLITFLPEN_Msk        (0x1U << RCC_AHB1LPENR_FLITFLPEN_Pos) /*!< 0x00008000 */
#define RCC_AHB1LPENR_FLITFLPEN            RCC_AHB1LPENR_FLITFLPEN_Msk
#define RCC_AHB1LPENR_SRAM1LPEN_Pos        (16U)
#define RCC_AHB1LPENR_SRAM1LPEN_Msk        (0x1U << RCC_AHB1LPENR_SRAM1LPEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1LPENR_SRAM1LPEN            RCC_AHB1LPENR_SRAM1LPEN_Msk
#define RCC_AHB1LPENR_SRAM2LPEN_Pos        (17U)
#define RCC_AHB1LPENR_SRAM2LPEN_Msk        (0x1U << RCC_AHB1LPENR_SRAM2LPEN_Pos) /*!< 0x00020000 */
#define RCC_AHB1LPENR_SRAM2LPEN            RCC_AHB1LPENR_SRAM2LPEN_Msk
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos      (18U)
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk      (0x1U << RCC_AHB1LPENR_BKPSRAMLPEN_Pos) /*!< 0x00040000 */
#define RCC_AHB1LPENR_BKPSRAMLPEN          RCC_AHB1LPENR_BKPSRAMLPEN_Msk
#define RCC_AHB1LPENR_DMA1LPEN_Pos         (21U)
#define RCC_AHB1LPENR_DMA1LPEN_Msk         (0x1U << RCC_AHB1LPENR_DMA1LPEN_Pos) /*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN             RCC_AHB1LPENR_DMA1LPEN_Msk
#define RCC_AHB1LPENR_DMA2LPEN_Pos         (22U)
#define RCC_AHB1LPENR_DMA2LPEN_Msk         (0x1U << RCC_AHB1LPENR_DMA2LPEN_Pos) /*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN             RCC_AHB1LPENR_DMA2LPEN_Msk

#define RCC_AHB1LPENR_ETHMACLPEN_Pos       (25U)
#define RCC_AHB1LPENR_ETHMACLPEN_Msk       (0x1U << RCC_AHB1LPENR_ETHMACLPEN_Pos) /*!< 0x02000000 */
#define RCC_AHB1LPENR_ETHMACLPEN           RCC_AHB1LPENR_ETHMACLPEN_Msk
#define RCC_AHB1LPENR_ETHMACTXLPEN_Pos     (26U)
#define RCC_AHB1LPENR_ETHMACTXLPEN_Msk     (0x1U << RCC_AHB1LPENR_ETHMACTXLPEN_Pos) /*!< 0x04000000 */
#define RCC_AHB1LPENR_ETHMACTXLPEN         RCC_AHB1LPENR_ETHMACTXLPEN_Msk
#define RCC_AHB1LPENR_ETHMACRXLPEN_Pos     (27U)
#define RCC_AHB1LPENR_ETHMACRXLPEN_Msk     (0x1U << RCC_AHB1LPENR_ETHMACRXLPEN_Pos) /*!< 0x08000000 */
#define RCC_AHB1LPENR_ETHMACRXLPEN         RCC_AHB1LPENR_ETHMACRXLPEN_Msk
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Pos    (28U)
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Msk    (0x1U << RCC_AHB1LPENR_ETHMACPTPLPEN_Pos) /*!< 0x10000000 */
#define RCC_AHB1LPENR_ETHMACPTPLPEN        RCC_AHB1LPENR_ETHMACPTPLPEN_Msk
#define RCC_AHB1LPENR_OTGHSLPEN_Pos        (29U)
#define RCC_AHB1LPENR_OTGHSLPEN_Msk        (0x1U << RCC_AHB1LPENR_OTGHSLPEN_Pos) /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSLPEN            RCC_AHB1LPENR_OTGHSLPEN_Msk
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos    (30U)
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk    (0x1U << RCC_AHB1LPENR_OTGHSULPILPEN_Pos) /*!< 0x40000000 */
#define RCC_AHB1LPENR_OTGHSULPILPEN        RCC_AHB1LPENR_OTGHSULPILPEN_Msk

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_DCMILPEN_Pos         (0U)
#define RCC_AHB2LPENR_DCMILPEN_Msk         (0x1U << RCC_AHB2LPENR_DCMILPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2LPENR_DCMILPEN             RCC_AHB2LPENR_DCMILPEN_Msk
#define RCC_AHB2LPENR_RNGLPEN_Pos          (6U)
#define RCC_AHB2LPENR_RNGLPEN_Msk          (0x1U << RCC_AHB2LPENR_RNGLPEN_Pos) /*!< 0x00000040 */
#define RCC_AHB2LPENR_RNGLPEN              RCC_AHB2LPENR_RNGLPEN_Msk
#define RCC_AHB2LPENR_OTGFSLPEN_Pos        (7U)
#define RCC_AHB2LPENR_OTGFSLPEN_Msk        (0x1U << RCC_AHB2LPENR_OTGFSLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN            RCC_AHB2LPENR_OTGFSLPEN_Msk

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define RCC_AHB3LPENR_FSMCLPEN_Pos         (0U)
#define RCC_AHB3LPENR_FSMCLPEN_Msk         (0x1U << RCC_AHB3LPENR_FSMCLPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB3LPENR_FSMCLPEN             RCC_AHB3LPENR_FSMCLPEN_Msk

/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN_Pos         (0U)
#define RCC_APB1LPENR_TIM2LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM2LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN             RCC_APB1LPENR_TIM2LPEN_Msk
#define RCC_APB1LPENR_TIM3LPEN_Pos         (1U)
#define RCC_APB1LPENR_TIM3LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM3LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN             RCC_APB1LPENR_TIM3LPEN_Msk
#define RCC_APB1LPENR_TIM4LPEN_Pos         (2U)
#define RCC_APB1LPENR_TIM4LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM4LPEN_Pos) /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN             RCC_APB1LPENR_TIM4LPEN_Msk
#define RCC_APB1LPENR_TIM5LPEN_Pos         (3U)
#define RCC_APB1LPENR_TIM5LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM5LPEN_Pos) /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN             RCC_APB1LPENR_TIM5LPEN_Msk
#define RCC_APB1LPENR_TIM6LPEN_Pos         (4U)
#define RCC_APB1LPENR_TIM6LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM6LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN             RCC_APB1LPENR_TIM6LPEN_Msk
#define RCC_APB1LPENR_TIM7LPEN_Pos         (5U)
#define RCC_APB1LPENR_TIM7LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM7LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN             RCC_APB1LPENR_TIM7LPEN_Msk
#define RCC_APB1LPENR_TIM12LPEN_Pos        (6U)
#define RCC_APB1LPENR_TIM12LPEN_Msk        (0x1U << RCC_APB1LPENR_TIM12LPEN_Pos) /*!< 0x00000040 */
#define RCC_APB1LPENR_TIM12LPEN            RCC_APB1LPENR_TIM12LPEN_Msk
#define RCC_APB1LPENR_TIM13LPEN_Pos        (7U)
#define RCC_APB1LPENR_TIM13LPEN_Msk        (0x1U << RCC_APB1LPENR_TIM13LPEN_Pos) /*!< 0x00000080 */
#define RCC_APB1LPENR_TIM13LPEN            RCC_APB1LPENR_TIM13LPEN_Msk
#define RCC_APB1LPENR_TIM14LPEN_Pos        (8U)
#define RCC_APB1LPENR_TIM14LPEN_Msk        (0x1U << RCC_APB1LPENR_TIM14LPEN_Pos) /*!< 0x00000100 */
#define RCC_APB1LPENR_TIM14LPEN            RCC_APB1LPENR_TIM14LPEN_Msk
#define RCC_APB1LPENR_WWDGLPEN_Pos         (11U)
#define RCC_APB1LPENR_WWDGLPEN_Msk         (0x1U << RCC_APB1LPENR_WWDGLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN             RCC_APB1LPENR_WWDGLPEN_Msk
#define RCC_APB1LPENR_SPI2LPEN_Pos         (14U)
#define RCC_APB1LPENR_SPI2LPEN_Msk         (0x1U << RCC_APB1LPENR_SPI2LPEN_Pos) /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN             RCC_APB1LPENR_SPI2LPEN_Msk
#define RCC_APB1LPENR_SPI3LPEN_Pos         (15U)
#define RCC_APB1LPENR_SPI3LPEN_Msk         (0x1U << RCC_APB1LPENR_SPI3LPEN_Pos) /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN             RCC_APB1LPENR_SPI3LPEN_Msk
#define RCC_APB1LPENR_USART2LPEN_Pos       (17U)
#define RCC_APB1LPENR_USART2LPEN_Msk       (0x1U << RCC_APB1LPENR_USART2LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN           RCC_APB1LPENR_USART2LPEN_Msk
#define RCC_APB1LPENR_USART3LPEN_Pos       (18U)
#define RCC_APB1LPENR_USART3LPEN_Msk       (0x1U << RCC_APB1LPENR_USART3LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN           RCC_APB1LPENR_USART3LPEN_Msk
#define RCC_APB1LPENR_UART4LPEN_Pos        (19U)
#define RCC_APB1LPENR_UART4LPEN_Msk        (0x1U << RCC_APB1LPENR_UART4LPEN_Pos) /*!< 0x00080000 */
#define RCC_APB1LPENR_UART4LPEN            RCC_APB1LPENR_UART4LPEN_Msk
#define RCC_APB1LPENR_UART5LPEN_Pos        (20U)
#define RCC_APB1LPENR_UART5LPEN_Msk        (0x1U << RCC_APB1LPENR_UART5LPEN_Pos) /*!< 0x00100000 */
#define RCC_APB1LPENR_UART5LPEN            RCC_APB1LPENR_UART5LPEN_Msk
#define RCC_APB1LPENR_I2C1LPEN_Pos         (21U)
#define RCC_APB1LPENR_I2C1LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C1LPEN_Pos) /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN             RCC_APB1LPENR_I2C1LPEN_Msk
#define RCC_APB1LPENR_I2C2LPEN_Pos         (22U)
#define RCC_APB1LPENR_I2C2LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C2LPEN_Pos) /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN             RCC_APB1LPENR_I2C2LPEN_Msk
#define RCC_APB1LPENR_I2C3LPEN_Pos         (23U)
#define RCC_APB1LPENR_I2C3LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C3LPEN_Pos) /*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN             RCC_APB1LPENR_I2C3LPEN_Msk
#define RCC_APB1LPENR_CAN1LPEN_Pos         (25U)
#define RCC_APB1LPENR_CAN1LPEN_Msk         (0x1U << RCC_APB1LPENR_CAN1LPEN_Pos) /*!< 0x02000000 */
#define RCC_APB1LPENR_CAN1LPEN             RCC_APB1LPENR_CAN1LPEN_Msk
#define RCC_APB1LPENR_CAN2LPEN_Pos         (26U)
#define RCC_APB1LPENR_CAN2LPEN_Msk         (0x1U << RCC_APB1LPENR_CAN2LPEN_Pos) /*!< 0x04000000 */
#define RCC_APB1LPENR_CAN2LPEN             RCC_APB1LPENR_CAN2LPEN_Msk
#define RCC_APB1LPENR_PWRLPEN_Pos          (28U)
#define RCC_APB1LPENR_PWRLPEN_Msk          (0x1U << RCC_APB1LPENR_PWRLPEN_Pos) /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN              RCC_APB1LPENR_PWRLPEN_Msk
#define RCC_APB1LPENR_DACLPEN_Pos          (29U)
#define RCC_APB1LPENR_DACLPEN_Msk          (0x1U << RCC_APB1LPENR_DACLPEN_Pos) /*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN              RCC_APB1LPENR_DACLPEN_Msk

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN_Pos         (0U)
#define RCC_APB2LPENR_TIM1LPEN_Msk         (0x1U << RCC_APB2LPENR_TIM1LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN             RCC_APB2LPENR_TIM1LPEN_Msk
#define RCC_APB2LPENR_TIM8LPEN_Pos         (1U)
#define RCC_APB2LPENR_TIM8LPEN_Msk         (0x1U << RCC_APB2LPENR_TIM8LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB2LPENR_TIM8LPEN             RCC_APB2LPENR_TIM8LPEN_Msk
#define RCC_APB2LPENR_USART1LPEN_Pos       (4U)
#define RCC_APB2LPENR_USART1LPEN_Msk       (0x1U << RCC_APB2LPENR_USART1LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN           RCC_APB2LPENR_USART1LPEN_Msk
#define RCC_APB2LPENR_USART6LPEN_Pos       (5U)
#define RCC_APB2LPENR_USART6LPEN_Msk       (0x1U << RCC_APB2LPENR_USART6LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN           RCC_APB2LPENR_USART6LPEN_Msk
#define RCC_APB2LPENR_ADC1LPEN_Pos         (8U)
#define RCC_APB2LPENR_ADC1LPEN_Msk         (0x1U << RCC_APB2LPENR_ADC1LPEN_Pos) /*!< 0x00000100 */
#define RCC_APB2LPENR_ADC1LPEN             RCC_APB2LPENR_ADC1LPEN_Msk
#define RCC_APB2LPENR_ADC2LPEN_Pos         (9U)
#define RCC_APB2LPENR_ADC2LPEN_Msk         (0x1U << RCC_APB2LPENR_ADC2LPEN_Pos) /*!< 0x00000200 */
#define RCC_APB2LPENR_ADC2LPEN             RCC_APB2LPENR_ADC2LPEN_Msk
#define RCC_APB2LPENR_ADC3LPEN_Pos         (10U)
#define RCC_APB2LPENR_ADC3LPEN_Msk         (0x1U << RCC_APB2LPENR_ADC3LPEN_Pos) /*!< 0x00000400 */
#define RCC_APB2LPENR_ADC3LPEN             RCC_APB2LPENR_ADC3LPEN_Msk
#define RCC_APB2LPENR_SDIOLPEN_Pos         (11U)
#define RCC_APB2LPENR_SDIOLPEN_Msk         (0x1U << RCC_APB2LPENR_SDIOLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB2LPENR_SDIOLPEN             RCC_APB2LPENR_SDIOLPEN_Msk
#define RCC_APB2LPENR_SPI1LPEN_Pos         (12U)
#define RCC_APB2LPENR_SPI1LPEN_Msk         (0x1U << RCC_APB2LPENR_SPI1LPEN_Pos) /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN             RCC_APB2LPENR_SPI1LPEN_Msk
#define RCC_APB2LPENR_SYSCFGLPEN_Pos       (14U)
#define RCC_APB2LPENR_SYSCFGLPEN_Msk       (0x1U << RCC_APB2LPENR_SYSCFGLPEN_Pos) /*!< 0x00004000 */
#define RCC_APB2LPENR_SYSCFGLPEN           RCC_APB2LPENR_SYSCFGLPEN_Msk
#define RCC_APB2LPENR_TIM9LPEN_Pos         (16U)
#define RCC_APB2LPENR_TIM9LPEN_Msk         (0x1U << RCC_APB2LPENR_TIM9LPEN_Pos) /*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN             RCC_APB2LPENR_TIM9LPEN_Msk
#define RCC_APB2LPENR_TIM10LPEN_Pos        (17U)
#define RCC_APB2LPENR_TIM10LPEN_Msk        (0x1U << RCC_APB2LPENR_TIM10LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN            RCC_APB2LPENR_TIM10LPEN_Msk
#define RCC_APB2LPENR_TIM11LPEN_Pos        (18U)
#define RCC_APB2LPENR_TIM11LPEN_Msk        (0x1U << RCC_APB2LPENR_TIM11LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN            RCC_APB2LPENR_TIM11LPEN_Msk

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                 (0U)
#define RCC_BDCR_LSEON_Msk                 (0x1U << RCC_BDCR_LSEON_Pos)        /*!< 0x00000001 */
#define RCC_BDCR_LSEON                     RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                (1U)
#define RCC_BDCR_LSERDY_Msk                (0x1U << RCC_BDCR_LSERDY_Pos)       /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                    RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                (2U)
#define RCC_BDCR_LSEBYP_Msk                (0x1U << RCC_BDCR_LSEBYP_Pos)       /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                    RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_RTCSEL_Pos                (8U)
#define RCC_BDCR_RTCSEL_Msk                (0x3U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                    RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                  (0x1U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                  (0x2U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                 (15U)
#define RCC_BDCR_RTCEN_Msk                 (0x1U << RCC_BDCR_RTCEN_Pos)        /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                     RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                 (16U)
#define RCC_BDCR_BDRST_Msk                 (0x1U << RCC_BDCR_BDRST_Pos)        /*!< 0x00010000 */
#define RCC_BDCR_BDRST                     RCC_BDCR_BDRST_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                  (0U)
#define RCC_CSR_LSION_Msk                  (0x1U << RCC_CSR_LSION_Pos)         /*!< 0x00000001 */
#define RCC_CSR_LSION                      RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                 (1U)
#define RCC_CSR_LSIRDY_Msk                 (0x1U << RCC_CSR_LSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                     RCC_CSR_LSIRDY_Msk
#define RCC_CSR_RMVF_Pos                   (24U)
#define RCC_CSR_RMVF_Msk                   (0x1U << RCC_CSR_RMVF_Pos)          /*!< 0x01000000 */
#define RCC_CSR_RMVF                       RCC_CSR_RMVF_Msk
#define RCC_CSR_BORRSTF_Pos                (25U)
#define RCC_CSR_BORRSTF_Msk                (0x1U << RCC_CSR_BORRSTF_Pos)       /*!< 0x02000000 */
#define RCC_CSR_BORRSTF                    RCC_CSR_BORRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                (26U)
#define RCC_CSR_PINRSTF_Msk                (0x1U << RCC_CSR_PINRSTF_Pos)       /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                    RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                (27U)
#define RCC_CSR_PORRSTF_Msk                (0x1U << RCC_CSR_PORRSTF_Pos)       /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                    RCC_CSR_PORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                (28U)
#define RCC_CSR_SFTRSTF_Msk                (0x1U << RCC_CSR_SFTRSTF_Pos)       /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                    RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos               (29U)
#define RCC_CSR_IWDGRSTF_Msk               (0x1U << RCC_CSR_IWDGRSTF_Pos)      /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                   RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos               (30U)
#define RCC_CSR_WWDGRSTF_Msk               (0x1U << RCC_CSR_WWDGRSTF_Pos)      /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                   RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos               (31U)
#define RCC_CSR_LPWRRSTF_Msk               (0x1U << RCC_CSR_LPWRRSTF_Pos)      /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                   RCC_CSR_LPWRRSTF_Msk
/* Legacy defines */
#define RCC_CSR_PADRSTF                    RCC_CSR_PINRSTF
#define RCC_CSR_WDGRSTF                    RCC_CSR_IWDGRSTF

/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER_Pos               (0U)
#define RCC_SSCGR_MODPER_Msk               (0x1FFFU << RCC_SSCGR_MODPER_Pos)   /*!< 0x00001FFF */
#define RCC_SSCGR_MODPER                   RCC_SSCGR_MODPER_Msk
#define RCC_SSCGR_INCSTEP_Pos              (13U)
#define RCC_SSCGR_INCSTEP_Msk              (0x7FFFU << RCC_SSCGR_INCSTEP_Pos)  /*!< 0x0FFFE000 */
#define RCC_SSCGR_INCSTEP                  RCC_SSCGR_INCSTEP_Msk
#define RCC_SSCGR_SPREADSEL_Pos            (30U)
#define RCC_SSCGR_SPREADSEL_Msk            (0x1U << RCC_SSCGR_SPREADSEL_Pos)   /*!< 0x40000000 */
#define RCC_SSCGR_SPREADSEL                RCC_SSCGR_SPREADSEL_Msk
#define RCC_SSCGR_SSCGEN_Pos               (31U)
#define RCC_SSCGR_SSCGEN_Msk               (0x1U << RCC_SSCGR_SSCGEN_Pos)      /*!< 0x80000000 */
#define RCC_SSCGR_SSCGEN                   RCC_SSCGR_SSCGEN_Msk

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SN_Pos         (6U)
#define RCC_PLLI2SCFGR_PLLI2SN_Msk         (0x1FFU << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00007FC0 */
#define RCC_PLLI2SCFGR_PLLI2SN             RCC_PLLI2SCFGR_PLLI2SN_Msk
#define RCC_PLLI2SCFGR_PLLI2SN_0           (0x001U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000040 */
#define RCC_PLLI2SCFGR_PLLI2SN_1           (0x002U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000080 */
#define RCC_PLLI2SCFGR_PLLI2SN_2           (0x004U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000100 */
#define RCC_PLLI2SCFGR_PLLI2SN_3           (0x008U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000200 */
#define RCC_PLLI2SCFGR_PLLI2SN_4           (0x010U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000400 */
#define RCC_PLLI2SCFGR_PLLI2SN_5           (0x020U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000800 */
#define RCC_PLLI2SCFGR_PLLI2SN_6           (0x040U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00001000 */
#define RCC_PLLI2SCFGR_PLLI2SN_7           (0x080U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00002000 */
#define RCC_PLLI2SCFGR_PLLI2SN_8           (0x100U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00004000 */

#define RCC_PLLI2SCFGR_PLLI2SR_Pos         (28U)
#define RCC_PLLI2SCFGR_PLLI2SR_Msk         (0x7U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x70000000 */
#define RCC_PLLI2SCFGR_PLLI2SR             RCC_PLLI2SCFGR_PLLI2SR_Msk
#define RCC_PLLI2SCFGR_PLLI2SR_0           (0x1U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x10000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_1           (0x2U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x20000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_2           (0x4U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x40000000 */


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/* SCB CPUID Register Definitions */
#define SCB_CPUID_IMPLEMENTER_Pos          24U                                            /*!< SCB CPUID: IMPLEMENTER Position */
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER Mask */
#define SCB_CPUID_VARIANT_Pos              20U                                            /*!< SCB CPUID: VARIANT Position */
#define SCB_CPUID_VARIANT_Msk              (0xFUL << SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT Mask */
#define SCB_CPUID_ARCHITECTURE_Pos         16U                                            /*!< SCB CPUID: ARCHITECTURE Position */
#define SCB_CPUID_ARCHITECTURE_Msk         (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)          /*!< SCB CPUID: ARCHITECTURE Mask */
#define SCB_CPUID_PARTNO_Pos                4U                                            /*!< SCB CPUID: PARTNO Position */
#define SCB_CPUID_PARTNO_Msk               (0xFFFUL << SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO Mask */
#define SCB_CPUID_REVISION_Pos              0U                                            /*!< SCB CPUID: REVISION Position */
#define SCB_CPUID_REVISION_Msk             (0xFUL /*<< SCB_CPUID_REVISION_Pos*/)          /*!< SCB CPUID: REVISION Mask */

/* SCB Interrupt Control State Register Definitions */
#define SCB_ICSR_NMIPENDSET_Pos            31U                                            /*!< SCB ICSR: NMIPENDSET Position */
#define SCB_ICSR_NMIPENDSET_Msk            (1UL << SCB_ICSR_NMIPENDSET_Pos)               /*!< SCB ICSR: NMIPENDSET Mask */
#define SCB_ICSR_PENDSVSET_Pos             28U                                            /*!< SCB ICSR: PENDSVSET Position */
#define SCB_ICSR_PENDSVSET_Msk             (1UL << SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET Mask */
#define SCB_ICSR_PENDSVCLR_Pos             27U                                            /*!< SCB ICSR: PENDSVCLR Position */
#define SCB_ICSR_PENDSVCLR_Msk             (1UL << SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR Mask */
#define SCB_ICSR_PENDSTSET_Pos             26U                                            /*!< SCB ICSR: PENDSTSET Position */
#define SCB_ICSR_PENDSTSET_Msk             (1UL << SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET Mask */
#define SCB_ICSR_PENDSTCLR_Pos             25U                                            /*!< SCB ICSR: PENDSTCLR Position */
#define SCB_ICSR_PENDSTCLR_Msk             (1UL << SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR Mask */
#define SCB_ICSR_ISRPREEMPT_Pos            23U                                            /*!< SCB ICSR: ISRPREEMPT Position */
#define SCB_ICSR_ISRPREEMPT_Msk            (1UL << SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT Mask */
#define SCB_ICSR_ISRPENDING_Pos            22U                                            /*!< SCB ICSR: ISRPENDING Position */
#define SCB_ICSR_ISRPENDING_Msk            (1UL << SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING Mask */
#define SCB_ICSR_VECTPENDING_Pos           12U                                            /*!< SCB ICSR: VECTPENDING Position */
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING Mask */
#define SCB_ICSR_RETTOBASE_Pos             11U                                            /*!< SCB ICSR: RETTOBASE Position */
#define SCB_ICSR_RETTOBASE_Msk             (1UL << SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE Mask */
#define SCB_ICSR_VECTACTIVE_Pos             0U                                            /*!< SCB ICSR: VECTACTIVE Position */
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL /*<< SCB_ICSR_VECTACTIVE_Pos*/)       /*!< SCB ICSR: VECTACTIVE Mask */

/* SCB Vector Table Offset Register Definitions */
#define SCB_VTOR_TBLOFF_Pos                 7U                                            /*!< SCB VTOR: TBLOFF Position */
#define SCB_VTOR_TBLOFF_Msk                (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)           /*!< SCB VTOR: TBLOFF Mask */

/* SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16U                                            /*!< SCB AIRCR: VECTKEY Position */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */
#define SCB_AIRCR_VECTKEYSTAT_Pos          16U                                            /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */
#define SCB_AIRCR_ENDIANESS_Pos            15U                                            /*!< SCB AIRCR: ENDIANESS Position */
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */
#define SCB_AIRCR_PRIGROUP_Pos              8U                                            /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */
#define SCB_AIRCR_SYSRESETREQ_Pos           2U                                            /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */
#define SCB_AIRCR_VECTCLRACTIVE_Pos         1U                                            /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */
#define SCB_AIRCR_VECTRESET_Pos             0U                                            /*!< SCB AIRCR: VECTRESET Position */
#define SCB_AIRCR_VECTRESET_Msk            (1UL /*<< SCB_AIRCR_VECTRESET_Pos*/)           /*!< SCB AIRCR: VECTRESET Mask */

/* SCB System Control Register Definitions */
#define SCB_SCR_SEVONPEND_Pos               4U                                            /*!< SCB SCR: SEVONPEND Position */
#define SCB_SCR_SEVONPEND_Msk              (1UL << SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND Mask */
#define SCB_SCR_SLEEPDEEP_Pos               2U                                            /*!< SCB SCR: SLEEPDEEP Position */
#define SCB_SCR_SLEEPDEEP_Msk              (1UL << SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP Mask */
#define SCB_SCR_SLEEPONEXIT_Pos             1U                                            /*!< SCB SCR: SLEEPONEXIT Position */
#define SCB_SCR_SLEEPONEXIT_Msk            (1UL << SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT Mask */

/* SCB Configuration Control Register Definitions */
#define SCB_CCR_STKALIGN_Pos                9U                                            /*!< SCB CCR: STKALIGN Position */
#define SCB_CCR_STKALIGN_Msk               (1UL << SCB_CCR_STKALIGN_Pos)                  /*!< SCB CCR: STKALIGN Mask */
#define SCB_CCR_BFHFNMIGN_Pos               8U                                            /*!< SCB CCR: BFHFNMIGN Position */
#define SCB_CCR_BFHFNMIGN_Msk              (1UL << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */
#define SCB_CCR_DIV_0_TRP_Pos               4U                                            /*!< SCB CCR: DIV_0_TRP Position */
#define SCB_CCR_DIV_0_TRP_Msk              (1UL << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */
#define SCB_CCR_UNALIGN_TRP_Pos             3U                                            /*!< SCB CCR: UNALIGN_TRP Position */
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */
#define SCB_CCR_USERSETMPEND_Pos            1U                                            /*!< SCB CCR: USERSETMPEND Position */
#define SCB_CCR_USERSETMPEND_Msk           (1UL << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */
#define SCB_CCR_NONBASETHRDENA_Pos          0U                                            /*!< SCB CCR: NONBASETHRDENA Position */
#define SCB_CCR_NONBASETHRDENA_Msk         (1UL /*<< SCB_CCR_NONBASETHRDENA_Pos*/)        /*!< SCB CCR: NONBASETHRDENA Mask */

/* SCB System Handler Control and State Register Definitions */
#define SCB_SHCSR_USGFAULTENA_Pos          18U                                            /*!< SCB SHCSR: USGFAULTENA Position */
#define SCB_SHCSR_USGFAULTENA_Msk          (1UL << SCB_SHCSR_USGFAULTENA_Pos)             /*!< SCB SHCSR: USGFAULTENA Mask */
#define SCB_SHCSR_BUSFAULTENA_Pos          17U                                            /*!< SCB SHCSR: BUSFAULTENA Position */
#define SCB_SHCSR_BUSFAULTENA_Msk          (1UL << SCB_SHCSR_BUSFAULTENA_Pos)             /*!< SCB SHCSR: BUSFAULTENA Mask */
#define SCB_SHCSR_MEMFAULTENA_Pos          16U                                            /*!< SCB SHCSR: MEMFAULTENA Position */
#define SCB_SHCSR_MEMFAULTENA_Msk          (1UL << SCB_SHCSR_MEMFAULTENA_Pos)             /*!< SCB SHCSR: MEMFAULTENA Mask */
#define SCB_SHCSR_SVCALLPENDED_Pos         15U                                            /*!< SCB SHCSR: SVCALLPENDED Position */
#define SCB_SHCSR_SVCALLPENDED_Msk         (1UL << SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED Mask */

#define SCB_SHCSR_BUSFAULTPENDED_Pos       14U                                            /*!< SCB SHCSR: BUSFAULTPENDED Position */
#define SCB_SHCSR_BUSFAULTPENDED_Msk       (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)          /*!< SCB SHCSR: BUSFAULTPENDED Mask */
#define SCB_SHCSR_MEMFAULTPENDED_Pos       13U                                            /*!< SCB SHCSR: MEMFAULTPENDED Position */
#define SCB_SHCSR_MEMFAULTPENDED_Msk       (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)          /*!< SCB SHCSR: MEMFAULTPENDED Mask */
#define SCB_SHCSR_USGFAULTPENDED_Pos       12U                                            /*!< SCB SHCSR: USGFAULTPENDED Position */
#define SCB_SHCSR_USGFAULTPENDED_Msk       (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)          /*!< SCB SHCSR: USGFAULTPENDED Mask */
#define SCB_SHCSR_SYSTICKACT_Pos           11U                                            /*!< SCB SHCSR: SYSTICKACT Position */
#define SCB_SHCSR_SYSTICKACT_Msk           (1UL << SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT Mask */
#define SCB_SHCSR_PENDSVACT_Pos            10U                                            /*!< SCB SHCSR: PENDSVACT Position */
#define SCB_SHCSR_PENDSVACT_Msk            (1UL << SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT Mask */
#define SCB_SHCSR_MONITORACT_Pos            8U                                            /*!< SCB SHCSR: MONITORACT Position */
#define SCB_SHCSR_MONITORACT_Msk           (1UL << SCB_SHCSR_MONITORACT_Pos)              /*!< SCB SHCSR: MONITORACT Mask */
#define SCB_SHCSR_SVCALLACT_Pos             7U                                            /*!< SCB SHCSR: SVCALLACT Position */
#define SCB_SHCSR_SVCALLACT_Msk            (1UL << SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT Mask */
#define SCB_SHCSR_USGFAULTACT_Pos           3U                                            /*!< SCB SHCSR: USGFAULTACT Position */
#define SCB_SHCSR_USGFAULTACT_Msk          (1UL << SCB_SHCSR_USGFAULTACT_Pos)             /*!< SCB SHCSR: USGFAULTACT Mask */
#define SCB_SHCSR_BUSFAULTACT_Pos           1U                                            /*!< SCB SHCSR: BUSFAULTACT Position */
#define SCB_SHCSR_BUSFAULTACT_Msk          (1UL << SCB_SHCSR_BUSFAULTACT_Pos)             /*!< SCB SHCSR: BUSFAULTACT Mask */
#define SCB_SHCSR_MEMFAULTACT_Pos           0U                                            /*!< SCB SHCSR: MEMFAULTACT Position */
#define SCB_SHCSR_MEMFAULTACT_Msk          (1UL /*<< SCB_SHCSR_MEMFAULTACT_Pos*/)         /*!< SCB SHCSR: MEMFAULTACT Mask */

/* SCB Configurable Fault Status Register Definitions */
#define SCB_CFSR_USGFAULTSR_Pos            16U                                            /*!< SCB CFSR: Usage Fault Status Register Position */
#define SCB_CFSR_USGFAULTSR_Msk            (0xFFFFUL << SCB_CFSR_USGFAULTSR_Pos)          /*!< SCB CFSR: Usage Fault Status Register Mask */
#define SCB_CFSR_BUSFAULTSR_Pos             8U                                            /*!< SCB CFSR: Bus Fault Status Register Position */
#define SCB_CFSR_BUSFAULTSR_Msk            (0xFFUL << SCB_CFSR_BUSFAULTSR_Pos)            /*!< SCB CFSR: Bus Fault Status Register Mask */
#define SCB_CFSR_MEMFAULTSR_Pos             0U                                            /*!< SCB CFSR: Memory Manage Fault Status Register Position */
#define SCB_CFSR_MEMFAULTSR_Msk            (0xFFUL /*<< SCB_CFSR_MEMFAULTSR_Pos*/)        /*!< SCB CFSR: Memory Manage Fault Status Register Mask */

/* SCB Hard Fault Status Register Definitions */
#define SCB_HFSR_DEBUGEVT_Pos              31U                                            /*!< SCB HFSR: DEBUGEVT Position */
#define SCB_HFSR_DEBUGEVT_Msk              (1UL << SCB_HFSR_DEBUGEVT_Pos)                 /*!< SCB HFSR: DEBUGEVT Mask */
#define SCB_HFSR_FORCED_Pos                30U                                            /*!< SCB HFSR: FORCED Position */
#define SCB_HFSR_FORCED_Msk                (1UL << SCB_HFSR_FORCED_Pos)                   /*!< SCB HFSR: FORCED Mask */
#define SCB_HFSR_VECTTBL_Pos                1U                                            /*!< SCB HFSR: VECTTBL Position */
#define SCB_HFSR_VECTTBL_Msk               (1UL << SCB_HFSR_VECTTBL_Pos)                  /*!< SCB HFSR: VECTTBL Mask */

/* SCB Debug Fault Status Register Definitions */
#define SCB_DFSR_EXTERNAL_Pos               4U                                            /*!< SCB DFSR: EXTERNAL Position */
#define SCB_DFSR_EXTERNAL_Msk              (1UL << SCB_DFSR_EXTERNAL_Pos)                 /*!< SCB DFSR: EXTERNAL Mask */
#define SCB_DFSR_VCATCH_Pos                 3U                                            /*!< SCB DFSR: VCATCH Position */
#define SCB_DFSR_VCATCH_Msk                (1UL << SCB_DFSR_VCATCH_Pos)                   /*!< SCB DFSR: VCATCH Mask */
#define SCB_DFSR_DWTTRAP_Pos                2U                                            /*!< SCB DFSR: DWTTRAP Position */
#define SCB_DFSR_DWTTRAP_Msk               (1UL << SCB_DFSR_DWTTRAP_Pos)                  /*!< SCB DFSR: DWTTRAP Mask */
#define SCB_DFSR_BKPT_Pos                   1U                                            /*!< SCB DFSR: BKPT Position */
#define SCB_DFSR_BKPT_Msk                  (1UL << SCB_DFSR_BKPT_Pos)                     /*!< SCB DFSR: BKPT Mask */
#define SCB_DFSR_HALTED_Pos                 0U                                            /*!< SCB DFSR: HALTED Position */
#define SCB_DFSR_HALTED_Msk                (1UL /*<< SCB_DFSR_HALTED_Pos*/)               /*!< SCB DFSR: HALTED Mask */

/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    /*!< SysTick CALIB: TENMS Mask */

/*@} end of group CMSIS_SysTick */


/* ##########################   NVIC functions  #################################### */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_NVICFunctions NVIC Functions
  \brief    Functions that manage interrupts and exceptions via the NVIC.
  @{
 */

/**
  \brief   Set Priority Grouping
  \details Sets the priority grouping field using the required unlock sequence.
           The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
           Only values from 0..7 are used.
           In case of a conflict between priority grouping and available
           priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set.
  \param [in]      PriorityGroup  Priority grouping field.
 */
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);             /* only values 0..7 are used          */

  reg_value  =  SCB->AIRCR;                                                   /* read old register configuration    */
  reg_value &= ~((uint32_t)(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk)); /* clear bits to change               */
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
                (PriorityGroupTmp << 8U)                      );              /* Insert write key and priorty group */
  SCB->AIRCR =  reg_value;
}


/**
  \brief   Get Priority Grouping
  \details Reads the priority grouping field from the NVIC Interrupt Controller.
  \return                Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos));
}


/**
  \brief   Enable External Interrupt
  \details Enables a device-specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}


/**
  \brief   Disable External Interrupt
  \details Disables a device-specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}


/**
  \brief   Get Pending Interrupt
  \details Reads the pending register in the NVIC and returns the pending bit for the specified interrupt.
  \param [in]      IRQn  Interrupt number.
  \return             0  Interrupt status is not pending.
  \return             1  Interrupt status is pending.
 */
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((NVIC->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}


/**
  \brief   Set Pending Interrupt
  \details Sets the pending bit of an external interrupt.
  \param [in]      IRQn  Interrupt number. Value cannot be negative.
 */
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}


/**
  \brief   Clear Pending Interrupt
  \details Clears the pending bit of an external interrupt.
  \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}


/**
  \brief   Get Active Interrupt
  \details Reads the active register in NVIC and returns the active bit.
  \param [in]      IRQn  Interrupt number.
  \return             0  Interrupt status is not active.
  \return             1  Interrupt status is active.
 */
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)(((NVIC->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}


/**
  \brief   Set Interrupt Priority
  \details Sets the priority of an interrupt.
  \note    The priority cannot be set for every core interrupt.
  \param [in]      IRQn  Interrupt number.
  \param [in]  priority  Priority to set.
 */
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    SCB->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
  }
  else
  {
    NVIC->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
  }
}


/**
  \brief   Get Interrupt Priority
  \details Reads the priority of an interrupt.
           The interrupt number can be positive to specify an external (device specific) interrupt,
           or negative to specify an internal (core) interrupt.
  \param [in]   IRQn  Interrupt number.
  \return             Interrupt Priority.
                      Value is aligned automatically to the implemented priority bits of the microcontroller.
 */
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return(((uint32_t)SCB->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - __NVIC_PRIO_BITS)));
  }
  else
  {
    return(((uint32_t)NVIC->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - __NVIC_PRIO_BITS)));
  }
}


/**
  \brief   Encode Priority
  \details Encodes the priority for an interrupt with the given priority group,
           preemptive priority value, and subpriority value.
           In case of a conflict between priority grouping and available
           priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set.
  \param [in]     PriorityGroup  Used priority group.
  \param [in]   PreemptPriority  Preemptive priority value (starting from 0).
  \param [in]       SubPriority  Subpriority value (starting from 0).
  \return                        Encoded priority. Value can be used in the function \ref NVIC_SetPriority().
 */
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}


/**
  \brief   Decode Priority
  \details Decodes an interrupt priority value with a given priority group to
           preemptive priority value and subpriority value.
           In case of a conflict between priority grouping and available
           priority bits (__NVIC_PRIO_BITS) the smallest possible priority group is set.
  \param [in]         Priority   Priority value, which can be retrieved with the function \ref NVIC_GetPriority().
  \param [in]     PriorityGroup  Used priority group.
  \param [out] pPreemptPriority  Preemptive priority value (starting from 0).
  \param [out]     pSubPriority  Subpriority value (starting from 0).
 */
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}


/**
  \brief   System Reset
  \details Initiates a system reset request to reset the MCU.
 */
static __inline void NVIC_SystemReset(void)
{
  __DSB();                                                          /* Ensure all outstanding memory accesses included
                                                                       buffered write are completed before reset */
  SCB->AIRCR  = (uint32_t)((0x5FAUL << SCB_AIRCR_VECTKEY_Pos)    |
                           (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |
                            SCB_AIRCR_SYSRESETREQ_Msk    );         /* Keep priority group unchanged */
  __DSB();                                                          /* Ensure completion of memory access */

  for(;;)                                                           /* wait until reset */
  {
    __NOP();
  }
}

/*@} end of CMSIS_Core_NVICFunctions */



/* ##################################    SysTick function  ############################################ */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_SysTickFunctions SysTick Functions
  \brief    Functions that configure the System.
  @{
 */

/**
  \brief   System Tick Configuration
  \details Initializes the System Timer and its interrupt, and starts the System Tick Timer.
           Counter is in free running mode to generate periodic interrupts.
  \param [in]  ticks  Number of ticks between two interrupts.
  \return          0  Function succeeded.
  \return          1  Function failed.
  \note    When the variable <b>__Vendor_SysTickConfig</b> is set to 1, then the
           function <b>SysTick_Config</b> is not included. In this case, the file <b><i>device</i>.h</b>
           must contain a vendor-specific implementation of this function.
 */
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                   /* Reload value impossible */
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
  return (0UL);                                                     /* Function successful */
}

/*@} end of CMSIS_Core_SysTickFunctions */




#endif /* __STM32F407_H */
