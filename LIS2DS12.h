#ifndef
#define LIS2DS12_h

#include "project.h"

#define AGENT_ADDRESS 0x1E

/* -------------------------- *
 * -------------------------- *
 * LIS2DS12 WHO_AM_I Function *
 * -------------------------- *
 * -------------------------- */

uint8_t LIS2_who_am_i();


/* ------------------------ *
 * ------------------------ *
 * LIS2DS12 CTRL1 Functions *
 * ------------------------ *
 * ------------------------ */

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
void LIS2_ctrl1_change_odr(uint8_t state);
void LIS2_ctrl1_change_fs(uint8_t state);
void LIS2_ctrl1_change_hf_odr(uint8_t state);
void LIS2_ctrl1_change_bdu(uint8_t state);

/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 CTRL4 INT1 Functions *
 * ----------------------------- *
 * ----------------------------- */

void LIS2_ctrl4_int1_master_drdy(uint8_t state);
void LIS2_ctrl4_int1_s_tap(uint8_t state);

/* --------------------------------- *
 * --------------------------------- *
 * LIS2DS12 Registry State Functions *
 * --------------------------------- *
 * --------------------------------- */

uint8_t LIS2_ctrl1_state();
uint8_t LIS_ctrl2_state();
uint8_t LIS_ctrl3_state();
uint8_t LIS_ctrl4_state();
uint8_t LIS_ctrl5_state();
uint8_t LIS_fifo_ctrl_state();
uint8_t LIS_status_state();

/* -------------------------------- *
 * -------------------------------- *
 * LIS2DS12 Accelerometer Functions *
 * -------------------------------- *
 * -------------------------------- */

float get_x_accel();
float get_y_accel();
float get_z_accel();
float get_accel(uint8_t reg_h, uint8_t reg_l);
float get_scaling_factor(uint8_t fs);

/* ---------------------- *
 * ---------------------- *
 * PSoC I2C R/W Functions *
 * ---------------------- *
 * ---------------------- */

uint8_t I2C_ReadReg(uint8_t reg);
void I2C_WriteReg(uint8_t reg, uint8_t val);

/* ------------------------------- *
 * ------------------------------- *
 * Functions for Arithmetic Needed *
 * ------------------------------- *
 * ------------------------------- */

uint16_t num_cat(uint8_t nh, uint8_t nl);
int twos_compliment(uint16_t num);
uint8_t bitwise_substr_ed(uint8_t word, uint8_t replace, uint8_t index_l, uint8_t index_h);
uint8_t bitwise_substr_p(uint8_t word, uint8_t index_l, uint8_t index_h);

#endif

/* [] END OF FILE */
