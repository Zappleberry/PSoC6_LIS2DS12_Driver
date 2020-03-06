#ifndef LIS2DS12_HL_H
#define LIS2DS12_HL_H

#include "LIS2DS12_LL.h"

#define MASTER_DRDY 7
#define SINGLE_TAP 6
#define WAKEUP 5
#define FREEFALL 4
#define DOUBLE_TAP 3
#define SIX_D 2
#define FIFO_THRES 1
#define DRDY 0

/* -------------------------- *
 * -------------------------- *
 * LIS2DS12 WHO_AM_I Function *
 * -------------------------- *
 * -------------------------- */

uint8_t LIS2_who_am_i();


/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 Power Mode Functions *
 * ----------------------------- *
 * ----------------------------- */

void LIS2_odr_powerdown();

void LIS2_odr_lp_1();
void LIS2_odr_lp_13();
void LIS2_odr_lp_25();
void LIS2_odr_lp_50();
void LIS2_odr_lp_100();
void LIS2_odr_lp_200();
void LIS2_odr_lp_400();
void LIS2_odr_lp_800();
void LIS2_odr_hr_13();
void LIS2_odr_hr_25();
void LIS2_odr_hr_50();
void LIS2_odr_hr_100();
void LIS2_odr_hr_200();
void LIS2_odr_hr_400();
void LIS2_odr_hr_800();
void LIS2_odr_hf_1600();
void LIS2_odr_hf_3200();
void LIS2_odr_hf_6400();
void LIS2_fs_2g();
void LIS2_fs_16g();
void LIS2_fs_4g();
void LIS2_fs_8g();
void LIS2_bdu_enable();
void LIS2_bdu_disable();

/* ---------------------------- *
 * ---------------------------- *
 * LIS2DS12 Interrupt Functions *
 * ---------------------------- *
 * ---------------------------- */

void LIS2_Interrupt_Enable(uint8_t interrupt, uint8_t interrupt_type);
void LIS2_Interrupt_Disable(uint8_t interrupt, uint8_t interrupt_type);

/* ---------------------------------- *
 * ---------------------------------- *
 * High Level Accelerometer Functions *
 * ---------------------------------- *
 * ---------------------------------- */

float LIS2_get_x_accel();
float LIS2_get_y_accel();
float LIS2_get_z_accel();

#endif

/* [] END OF FILE */
