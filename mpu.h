#ifndef MPU_H
#define MPU_H

#include "stm32f407xx.h"


/* MPU Type Register Definitions */
#define MPU_TYPE_IREGION                   MPU_TYPE_IREGION_Msk                /*!< Number of Instruction Regions, Always 0x0 in ARMv7-M */
#define MPU_TYPE_DREGION                   MPU_TYPE_DREGION_Msk                /*!< Number of regions supported by this MPU */
#define MPU_TYPE_SEPARATE                  MPU_TYPE_SEPARATE_Msk               /*!< This is always 0 as MPU is unified*/


/* MPU Control Register Definitions */
#define MPU_CTRL_PRIVDEFENA            MPU_CTRL_PRIVDEFENA_Msk                 /*!< MPU CTRL: PRIVDEFENA Mask */
#define MPU_CTRL_HFNMIENA              MPU_CTRL_HFNMIENA_Msk                   /*!< MPU CTRL: HFNMIENA Mask */
#define MPU_CTRL_ENABLE                MPU_CTRL_ENABLE_Msk                     /*!< Enable if MPu is set to 1*/

/* MPU Region Number Register Definitions */
#define MPU_RNR_REGION                 MPU_RNR_REGION_Msk                      /*!< MPU RNR: REGION Mask */
#define MPU_RNR_REGION_0               (0x0 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_1               (0x1 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_2               (0x2 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_3               (0x3 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_4               (0x4 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_5               (0x5 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_6               (0x6 << MPU_RNR_REGION_Pos)
#define MPU_RNR_REGION_7               (0x7 << MPU_RNR_REGION_Pos)

/* MPU Region Base Address Register Definitions */
#define MPU_RBAR_ADDR                  MPU_RBAR_ADDR_Msk                       /*!< MPU RBAR: ADDR Mask */
#define MPU_RBAR_VALID                 MPU_RBAR_VALID_Msk                      /*!< MPU RBAR: VALID Mask */
#define MPU_RBAR_REGION                MPU_RBAR_REGION_Msk                     /*!< MPU RBAR: REGION Mask */
#define MPU_RBAR_REGION_0              (0x0 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_1              (0x1 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_2              (0x2 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_3              (0x3 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_4              (0x4 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_5              (0x5 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_6              (0x6 << MPU_RBAR_REGION_Pos)
#define MPU_RBAR_REGION_7              (0x7 << MPU_RBAR_REGION_Pos)

/* MPU Region Attribute and Size Register Definitions */
#define MPU_RASR_ATTRS                 MPU_RASR_ATTRS_Msk                      /*!< MPU RASR: MPU Region Attribute field Mask */
#define MPU_RASR_XN                    MPU_RASR_XN_Msk                         /*!< MPU RASR: ATTRS.XN Mask */
#define MPU_RASR_AP                    MPU_RASR_AP_Msk                         /*!< MPU RASR: ATTRS.AP Mask */
#define MPU_RASR_AP_NA_NA             (0x0 << MPU_RASR_AP_Pos)                /*!< No Access */
#define MPU_RASR_AP_RW_NA             (0x1 << MPU_RASR_AP_Pos)                /*!< Previleged Access Only */
#define MPU_RASR_AP_RW_RO             (0x2 << MPU_RASR_AP_Pos)                /*!< Write in a user program generates a fault */
#define MPU_RASR_AP_RW_RW             (0x3 << MPU_RASR_AP_Pos)                /*!< Full Access */
#define MPU_RASR_AP_UP_UP             (0x4 << MPU_RASR_AP_Pos)                /*!< Unpredictable */
#define MPU_RASR_AP_RO_NA             (0x5 << MPU_RASR_AP_Pos)                /*!< Previleged Read Only */
#define MPU_RASR_AP_RO_RO             (0x6 << MPU_RASR_AP_Pos)                /*!< Read Only */
#define MPU_RASR_AP_RO_RO_1           (0x7 << MPU_RASR_AP_Pos)                /*!< Read Only */
#define MPU_RASR_TEX                   MPU_RASR_TEX_Msk                        /*!< MPU RASR: ATTRS.TEX Mask */
#define MPU_RASR_S                     MPU_RASR_S_Msk                          /*!< MPU RASR: ATTRS.S Mask */
#define MPU_RASR_C                     MPU_RASR_C_Msk                          /*!< MPU RASR: ATTRS.C Mask */
#define MPU_RASR_B                     MPU_RASR_B_Msk                          /*!< MPU RASR: ATTRS.B Mask */
#define MPU_RASR_NORMAL_MEM_WT        (MPU_RASR_C)                             /*!< Non-Shareable, write through */
#define MPU_RASR_NORMAL_MEM_WB        (MPU_RASR_C|MPU_RASR_B)                  /*!< Non-Shareable, write back */
#define MPU_RASR_NORMAL_SHARED_MEM_WT (MPU_RASR_C|MPU_RASR_S)                  /*!< Shareable, write through */
#define MPU_RASR_NORMAL_SHARED_MEM_WB (MPU_RASR_B|MPU_RASR_C|MPU_RASR_S)       /*!< Shareable, write back */
#define MPU_RASR_NORMAL_SHARED_DEVICE (MPU_RASR_B)                             /*!< Shareable Device */
#define MPU_RASR_SRD                  MPU_RASR_SRD_Msk                         /*!< MPU RASR: Sub-Region Disable Mask */
#define MPU_RASR_SIZE                 MPU_RASR_SIZE_Msk                        /*!< MPU RASR: Region Size Field Mask */
#define MPU_RASR_SIZE_32              (0x04 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_64              (0x05 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_128             (0x06 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_256             (0x07 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_512             (0x08 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_1K              (0x09 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_2K              (0x0a << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_4K              (0x0b << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_8K              (0x0c << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_16K             (0x0d << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_32K             (0x0e << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_64K             (0x0f << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_128K            (0x10 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_256K            (0x11 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_512K            (0x12 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_1M              (0x13 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_2M              (0x14 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_4M              (0x15 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_8M              (0x16 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_16M             (0x17 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_32M             (0x18 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_64M             (0x19 << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_128M            (0x1a << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_256M            (0x1b << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_512M            (0x1c << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_1G              (0x1d << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_2G              (0x1e << MPU_RASR_SIZE_Pos)
#define MPU_RASR_SIZE_4G              (0x1f << MPU_RASR_SIZE_Pos)

#define MPU_RASR_ENABLE               MPU_RASR_ENABLE_Msk                      /*!< MPU RASR: Region enable bit Disable Mask */

int mpu_enable(void);
void mpu_task_stack_permit(void *start);

#endif /* MPU_H */
