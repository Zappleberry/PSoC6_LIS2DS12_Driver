#ifndef LIS2DS12_h
#define LIS2DS12_h

#include "I2C_RW.h"
#include "arithmetic.h"

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

/* ---------------------------------- *
 * ---------------------------------- *
 * LIS2DS12 CTRL1 Low Level Functions *
 * ---------------------------------- *
 * ---------------------------------- */

void LIS2_ctrl1_change_odr(uint8_t state);
void LIS2_ctrl1_change_fs(uint8_t state);
void LIS2_ctrl1_change_hf_odr(uint8_t state);
void LIS2_ctrl1_change_bdu(uint8_t state);

/* ---------------------------- *
 * ---------------------------- *
 * LIS2DS12 Interrupt Functions *
 * ---------------------------- *
 * ---------------------------- */

void LIS2_Interrupt_Enable(uint8_t interrupt, uint8_t interrupt_type);
void LIS2_Interrupt_Disable(uint8_t interrupt, uint8_t interrupt_type);

/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 CTRL4 INT1 Functions *
 * ----------------------------- *
 * ----------------------------- */

void LIS2_ctrl4_int1_master_drdy(uint8_t state);
void LIS2_ctrl4_int1_s_tap(uint8_t state);
void LIS2_ctrl4_int1_wu(uint8_t state);
void LIS2_ctrl4_int1_ff(uint8_t state);
void LIS2_ctrl4_int1_dtap(uint8_t state);
void LIS2_ctrl4_int1_6D(uint8_t state);
void LIS2_ctrl4_int1_fth(uint8_t state);
void LIS2_ctrl4_int1_drdy(uint8_t state);

/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 CTRL5 INT2 Functions *
 * ----------------------------- *
 * ------------------------------*/

void LIS2_ctrl5_int2_master_drdy(uint8_t state);
void LIS2_ctrl5_int2_s_tap(uint8_t state);
void LIS2_ctrl5_int2_wu(uint8_t state);
void LIS2_ctrl5_int2_ff(uint8_t state);
void LIS2_ctrl5_int2_dtap(uint8_t state);
void LIS2_ctrl5_int2_6D(uint8_t state);
void LIS2_ctrl5_int2_fth(uint8_t state);
void LIS2_ctrl5_int2_drdy(uint8_t state);

/* --------------------------------- *
 * --------------------------------- *
 * LIS2DS12 Registry State Functions *
 * --------------------------------- *
 * --------------------------------- */

uint8_t LIS2_ctrl1_state();
uint8_t LIS2_ctrl2_state();
uint8_t LIS2_ctrl3_state();
uint8_t LIS2_ctrl4_state();
uint8_t LIS2_ctrl5_state();
uint8_t LIS2_fifo_ctrl_state();
uint8_t LIS2_status_state();

/* -------------------------------- *
 * -------------------------------- *
 * LIS2DS12 Accelerometer Functions *
 * -------------------------------- *
 * -------------------------------- */

float LIS2_get_x_accel();
float LIS2_get_y_accel();
float LIS2_get_z_accel();
float get_accel(uint8_t reg_h, uint8_t reg_l);
float get_scaling_factor(uint8_t fs);

/* ------------------------------------- *
 * ------------------------------------- *
 * LIS2DS12 Low Level Interrupt Settings *
 * ------------------------------------- *
 * ------------------------------------- */

/* Reg 2E */
void LIS2_set_FIFO_THS(uint8_t FTH);
uint8_t LIS2_get_FIFO_THS();

/* Reg 2F */
uint8_t LIS2_get_FIFO_SRC_FTH();
uint8_t LIS2_get_FIFO_SRC_OVR();
uint8_t LIS2_get_FIFO_SRC_DIFF();

/* Reg 30 */
uint8_t LIS2_get_FIFO_SAMPLES();

/* Reg 31 */
uint8_t LIS2_get_TAP_6D_THS();
void LIS2_set_TAP_6D_THS_4D_EN(uint8_t en);
void LIS2_set_TAP_6D_THS_6D_THS(uint8_t thres);
void LIS2_set_TAP_6D_THS_TAP_THS(uint8_t thres);

/* Reg 32 */
uint8_t LIS2_get_INT_DUR();
void LIS2_set_INT_DUR_LAT(uint8_t lat);
uint8_t LIS2_get_INT_DUR_LAT();
void LIS2_set_INT_DUR_QUIET(uint8_t quiet);
uint8_t LIS2_get_INT_DUR_QUIET();
void LIS2_set_INT_DUR_SHOCK(uint8_t shock);
uint8_t LIS2_get_INT_DUR_SHOCK();

/* Reg 33 */
uint8_t LIS2_get_WAKE_UP_THS();
void LIS2_set_WAKE_UP_THS_S_D_TAP(uint8_t en);
uint8_t LIS2_get_WAKE_UP_THS_S_D_TAP();
void LIS2_set_WAKE_UP_THS_SLEEP_ON(uint8_t en);
uint8_t LIS2_get_WAKE_UP_THS_SLEEP_ON();
void LIS2_set_WAKE_UP_THS_WU_THS(uint8_t wu_ths);
uint8_t LIS2_get_WAKE_UP_THS_WU_THS();

/* Reg 34 */
uint8_t LIS2_get_WAKE_UP_DUR();
void LIS2_set_WAKE_UP_DUR_WU_DUR(uint8_t dur);
uint8_t LIS2_get_WAKE_UP_DUR_WU_DUR();
void LIS2_set_WAKE_UP_DUR_INT1_FSS7(uint8_t en);
uint8_t LIS2_get_WAKE_UP_DUR_INT1_FSS7();
void LIS2_set_WAKE_UP_DUR_SLEEP_DUR(uint8_t dur);
uint8_t LIS2_get_WAKE_UP_DUR_SLEEP_DUR();

/* Reg 35 */
uint8_t LIS2_get_FREE_FALL();
void LIS2_set_FREE_FALL_FF_DUR(uint8_t dur);
uint8_t LIS2_get_FREE_FALL_FF_DUR();
void LIS2_set_FREE_FALL_FF_THS(uint8_t thres);
uint8_t LIS2_get_FREE_FALL_FF_THS();

/* Reg 37 */
uint8_t LIS2_get_WAKE_UP_SRC();
uint8_t LIS2_get_WAKE_UP_SRC_FF_IA();
uint8_t LIS2_get_WAKE_UP_SRC_SLEEP_STATE_IA();
uint8_t LIS2_get_WAKE_UP_SRC_WU_IA();
uint8_t LIS2_get_WAKE_UP_SRC_X_WU();
uint8_t LIS2_get_WAKE_UP_SRC_Y_WU();
uint8_t LIS2_get_WAKE_UP_SRC_Z_WU();

/* Reg 38 */
uint8_t LIS2_get_TAP_SRC();
uint8_t LIS2_get_TAP_SRC_TAP_IA();
uint8_t LIS2_get_TAP_SRC_S_TAP();
uint8_t LIS2_get_TAP_SRC_D_TAP();
uint8_t LIS2_get_TAP_SRC_TAP_SIGN();
uint8_t LIS2_get_TAP_SRC_X_TAP();
uint8_t LIS2_get_TAP_SRC_Y_TAP();
uint8_t LIS2_get_TAP_SRC_Z_TAP();

/* Reg 39 */
uint8_t LIS2_get_6D_SRC();
uint8_t LIS2_get_6D_SRC_6D_IA();
uint8_t LIS2_get_6D_SRC_ZH();
uint8_t LIS2_get_6D_SRC_ZL();
uint8_t LIS2_get_6D_SRC_YH();
uint8_t LIS2_get_6D_SRC_YL();
uint8_t LIS2_get_6D_SRC_XH();
uint8_t LIS2_get_6D_SRC_XL();

#endif

/* [] END OF FILE */
