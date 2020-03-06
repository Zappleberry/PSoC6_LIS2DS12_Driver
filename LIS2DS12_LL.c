#include "LIS2DS12_LL.h"
#include "I2C_RW.h"
#include "arithmetic.h"

/* ---------------------------------- *
 * ---------------------------------- *
 * LIS2DS12 CTRL1 Low Level Functions *
 * ---------------------------------- *
 * ---------------------------------- */

void LIS2_ctrl1_change_odr(uint8_t state){
	   /*
	    * Used internally to change the power state
	    * in registry CTRL1
	    * state must be 4 bits
	    */

	   uint8_t ctrl1_state = LIS2_ctrl1_state();
	   //uint8_t write_val = (0x0F & ctrl1_state) | ((state<<4) & ~(0x0F));
	   uint8_t write_val = bitwise_substr_ed(ctrl1_state, state, 4, 7);
	   I2C_WriteReg((uint8_t) 0x20, (uint8_t) write_val);

}

void LIS2_ctrl1_change_fs(uint8_t state){
	   /*
	    * Used internally to change the full scale selection
	    * in registry CTRL1
	    * state must be 2 bits
	    */

	   uint8_t ctrl1_state = LIS2_ctrl1_state();
	   //uint8_t write_val = (~(0x0C) & ctrl1_state) | ((state << 2) & 0x0C);
	   uint8_t write_val = bitwise_substr_ed(ctrl1_state, state, 2, 3);
	   I2C_WriteReg((uint8_t) 0x20, (uint8_t) write_val);

}

void LIS2_ctrl1_change_hf_odr(uint8_t state){
	   /*
	    * Used internally to change the High Frequency ODR mode
	    * in registry CTRL1
	    * state must be 1 bit
	    */

	   uint8_t ctrl1_state = LIS2_ctrl1_state();
	   //uint8_t write_val = (~(0x02) & ctrl1_state) | ((state << 1) & 0x02);
	   uint8_t write_val = bitwise_substr_ed(ctrl1_state, state, 1, 1);
	   I2C_WriteReg((uint8_t) 0x20, (uint8_t) write_val);

}

void LIS2_ctrl1_change_bdu(uint8_t state){
	   /*
	    * Used internally to change the block data update selection
	    * in registry CTRL1
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl1_state = LIS2_ctrl1_state();
	   //uint8_t write_val = (~(0x01) & ctrl1_state) | (state & 0x01);
	   uint8_t write_val = bitwise_substr_ed(ctrl1_state, state, 0, 0);
	   I2C_WriteReg((uint8_t) 0x20, (uint8_t) write_val);

}


/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 CTRL4 INT1 Functions *
 * ----------------------------- *
 * ----------------------------- */

void LIS2_ctrl4_int1_master_drdy(uint8_t state){
	   /*
	    * Used internally to change the Master DRDY Signal
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 7, 7);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_s_tap(uint8_t state){
	   /*
	    * Used internally to change the single tap recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 6, 6);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_wu(uint8_t state){
	   /*
	    * Used internally to change the wake recognition recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 5, 5);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_ff(uint8_t state){
	   /*
	    * Used internally to change the free-fall recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 4, 4);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_dtap(uint8_t state){
	   /*
	    * Used internally to change the double tap recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 3, 3);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_6D(uint8_t state){
	   /*
	    * Used internally to change the 6D recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 2, 2);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_fth(uint8_t state){
	   /*
	    * Used internally to change the FIFO threshold recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 1, 1);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

void LIS2_ctrl4_int1_drdy(uint8_t state){
	   /*
	    * Used internally to change the data ready recognition
	    * on INT1 pad
	    * in registry CTRL4
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl4_state = LIS2_ctrl4_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl4_state, state, 0, 0);

	   I2C_WriteReg((uint8_t) 0x23, (uint8_t) write_val);
}

/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 CTRL5 INT2 Functions *
 * ----------------------------- *
 * ------------------------------*/

void LIS2_ctrl5_int2_master_drdy(uint8_t state){
	   /*
	    * Used internally to change the Master DRDY Signal
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 7, 7);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_s_tap(uint8_t state){
	   /*
	    * Used internally to change the single tap recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 6, 6);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_wu(uint8_t state){
	   /*
	    * Used internally to change the wake recognition recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 5, 5);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_ff(uint8_t state){
	   /*
	    * Used internally to change the free-fall recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 4, 4);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_dtap(uint8_t state){
	   /*
	    * Used internally to change the double tap recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 3, 3);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_6D(uint8_t state){
	   /*
	    * Used internally to change the 6D recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 2, 2);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_fth(uint8_t state){
	   /*
	    * Used internally to change the FIFO threshold recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 1, 1);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

void LIS2_ctrl5_int2_drdy(uint8_t state){
	   /*
	    * Used internally to change the data ready recognition
	    * on INT2 pad
	    * in registry CTRL5
	    *
	    * state must be 1 bit
	    */

	   uint8_t ctrl5_state = LIS2_ctrl5_state();
	   uint8_t write_val = bitwise_substr_ed(ctrl5_state, state, 0, 0);

	   I2C_WriteReg((uint8_t) 0x24, (uint8_t) write_val);
}

/* --------------------------------- *
 * --------------------------------- *
 * LIS2DS12 Registry State Functions *
 * --------------------------------- *
 * --------------------------------- */

uint8_t LIS2_ctrl1_state(){
	   /*
	    * Read and return the current state of the CTRL1 Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x20);
}

uint8_t LIS2_ctrl2_state(){
	   /*
	    * Read and return the current state of the CTRL2 Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x21);
}

uint8_t LIS2_ctrl3_state(){
	   /*
	    * Read and return the current state of the CTRL3 Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x22);
}

uint8_t LIS2_ctrl4_state(){
	   /*
	    * Read and return the current state of the CTRL4 Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x23);
}

uint8_t LIS2_ctrl5_state(){
	   /*
	    * Read and return the current state of the CTRL5 Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x24);
}

uint8_t LIS2_fifo_ctrl_state(){
	   /*
	    * Read and return the current state of the FIFO_CTRL Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x25);
}

uint8_t LIS2_status_state(){
	   /*
	    * Read and return the current state of the STATUS Registry
	    */
	   return I2C_ReadReg((uint8_t) 0x27);
}


/* --------------------------------- *
 * --------------------------------- *
 * Low Level Accelerometer Functions *
 * --------------------------------- *
 * --------------------------------- */

float get_accel(uint8_t reg_h, uint8_t reg_l){
	   /* 
	    * Used to grab the current accelerometer information
	    * from arbituary axis
	    */

	   uint8_t high_byte, low_byte;
	   int prescale;
	   uint8_t ctrl1_state;
	   uint8_t fs;
	   float scaling_f;

	   /* Determine the current full-scale selection */
	   ctrl1_state = LIS2_ctrl1_state();
	   fs = bitwise_substr_p(ctrl1_state,2,3);

	   /* Use current full-scale selection to determine the scaling factor */
	   scaling_f = get_scaling_factor(fs);

	   /* Get accelerations of registers */
	   high_byte = I2C_ReadReg(reg_h);
	   low_byte = I2C_ReadReg(reg_l);

	   /* calculate prescaled integer by concatenating the high byte and low byte and
	    * undoing two's complimenting of the 2 byte number */
	   prescale = twos_compliment(num_cat(high_byte, low_byte));

	   return ((float) prescale / (float) scaling_f)*9.8;
}

float get_scaling_factor(uint8_t fs){

	   uint16_t scale_f_2g = 0x8000; /* Maximum prescale value in one direction */

	   switch(fs){
			 case 0:
				    return (float) scale_f_2g/2; /* Case for +/- 2g config */
				    break;
			 case 1:
				    return (float) scale_f_2g/16; /* Case for +/- 16g config */
				    break;
			 case 2:
				    return (float) scale_f_2g/4; /* Case for +/- 4g config */
				    break;
			 case 3:
				    return (float) scale_f_2g/8; /* Case for +/- 8g config */
				    break;
			 default:
				    return (float) scale_f_2g; /* default config */
				    break;
	   }

}

/* ------------------------------------- *
 * ------------------------------------- *
 * LIS2DS12 Low Level Interrupt Settings *
 * ------------------------------------- *
 * ------------------------------------- */

void LIS2_set_FIFO_THS(uint8_t FTH){
	   /* 
	    * Sets FIFO Threshold Value
	    *
	    * Stored in Register 2E
	    */
	   
	   I2C_WriteReg((uint8_t) 0x2E, (uint8_t) FTH);
}

uint8_t LIS2_get_FIFO_THS(){
	   /*
	    * Gets FIFO Threshold Value
	    *
	    * Stored in Register 2E
	    */
	   
	   return I2C_ReadReg((uint8_t) 0x2E);
}

/* Reg 2F */
uint8_t LIS2_get_FIFO_SRC_FTH(){
	   /*
	    * Get FIFO Thresthold Status
	    */

	   return bitwise_substr_p(I2C_ReadReg((uint8_t) 0x2F), 7, 7);
}
uint8_t LIS2_get_FIFO_SRC_OVR(){
	   /*
	    * Get FIFO Overrun Status
	    */

	   return bitwise_substr_p(I2C_ReadReg((uint8_t) 0x2F), 6, 6);
}

uint16_t LIS2_get_FIFO_SAMPLES(){
	   /*
	    * Get the number of unread FIFO Samples
	    * Stored in Register 2F and 30
	    */

	   uint8_t highbit = bitwise_substr_p(I2C_ReadReg((uint8_t) 0x2F), 5, 5);
	   uint8_t lowbyte = I2C_ReadReg((uint8_t) 0x30);

	   return num_cat(highbit, lowbyte);
}

/* Reg 31 */
uint8_t LIS2_get_TAP_6D_THS(){
	   /*
	    * Read and return the current state of the TAP_6D_THS Registry
	    */

	   return I2C_ReadReg((uint8_t) 0x31);
}

void LIS2_set_TAP_6D_THS_4D_EN(uint8_t en){
	   /*
	    * Change the 4D detection of portrait/landscape mode
	    *
	    * enable must be 1 bit, enforced by bitwise_substr_ed
	    *
	    * 0 is no position is detected
	    * 1 is portrait/landscape, face-up/down detection enabled
	    */

	   uint8_t tap_6d_state = LIS2_get_TAP_6D_THS();
	   uint8_t write_val = bitwise_substr_ed(tap_6d_state, en, 7, 7);

	   I2C_WriteReg((uint8_t) 0x31, (uint8_t) write_val);
}

void LIS2_set_TAP_6D_THS_6D_THS(uint8_t thres){
	   /*
	    * Change the threshold for the 4D/6D detection
	    *
	    * thres must be 2 bits. enforced
	    *
	    * 00 is threshold of 6 (80 Degrees)
	    * 01 is threshold of 11 (70 Degrees)
	    * 10 is threshold of 16 (60 Degrees)
	    * 11 is threshold of 21 (50 Degrees)
	    */

	   uint8_t tap_6d_state = LIS2_get_TAP_6D_THS();
	   uint8_t write_val = bitwise_substr_ed(tap_6d_state, thres, 5, 6);

	   I2C_WriteReg((uint8_t) 0x31, (uint8_t) write_val);
}
void LIS2_set_TAP_6D_THS_TAP_THS(uint8_t thres){
	   /*
	    * Threshold for tap recognition
	    *
	    * thre must be 5 bits. enforced
	    *
	    * 1 LSB = FS/32
	    */

	   uint8_t tap_6d_state = LIS2_get_TAP_6D_THS();
	   uint8_t write_val = bitwise_substr_ed(tap_6d_state, thres, 0, 4);

	   I2C_WriteReg((uint8_t) 0x31, (uint8_t) write_val);
}

/* Reg 32 */
uint8_t LIS2_get_INT_DUR(){
	   /*
	    * Read and return the current state of the INT_DUR Registry
	    */

	   return I2C_ReadReg((uint8_t) 0x32);
}
void LIS2_set_INT_DUR_LAT(uint8_t lat){
	   /*
	    * Write for max time gap for double tap recognition to be detected
	    *
	    * lat must be 4 bits
	    *
	    * 1 LSB = 32 TODR
	    */

	   uint8_t int_dur_state = LIS2_get_INT_DUR();
	   uint8_t write_val = bitwise_substr_ed(int_dur_state, lat, 4, 7);

	   I2C_WriteReg((uint8_t) 0x32, (uint8_t) write_val);
}

uint8_t LIS2_get_INT_DUR_LAT(){
	   /*
	    * Read the current LAT from INT_DUR registry
	    */

	   return bitwise_substr_p(LIS2_get_INT_DUR(), 4, 7);
}

void LIS2_set_INT_DUR_QUIET(uint8_t quiet){
	   /*
	    * Expected quiet time after tap detection:
	    * Represents the time after the first tap in
	    * which there must not be any over-threshold event
	    *
	    * quiet must be 2 bits
	    *
	    * 1 LSB = 4 TODR
	    */

	   uint8_t int_dur_state = LIS2_get_INT_DUR();
	   uint8_t write_val = bitwise_substr_ed(int_dur_state, quiet, 2, 3);

	   I2C_WriteReg((uint8_t) 0x32, (uint8_t) write_val);
}

uint8_t LIS2_get_INT_DUR_QUIET(){
	   /* 
	    * Read the current QUIET from the INT_DUR registry
	    */

	   return bitwise_substr_p(LIS2_get_INT_DUR(), 2, 3);
}

void LIS2_set_INT_DUR_SHOCK(uint8_t shock){
	   /*
	    * Maximum duration of overthreshold event:
	    * Represents the max time for an overthreshold
	    * signal detection to be recognized as a tap event
	    *
	    * shock must be 2 bits
	    *
	    * 1 LSB = 8 TODR
	    */

	   uint8_t int_dur_state = LIS2_get_INT_DUR();
	   uint8_t write_val = bitwise_substr_ed(int_dur_state, shock, 0, 1);

	   I2C_WriteReg((uint8_t) 0x32, (uint8_t) write_val);
}

uint8_t LIS2_get_INT_DUR_SHOCK(){
	   /*
	    * Red the current SHOCK from the INT_DUR registry
	    */

	   return bitwise_substr_p(LIS2_get_INT_DUR(), 0, 1);
}

/* Reg 33 */
uint8_t LIS2_get_WAKE_UP_THS(){
	   /*
	    * This reads the content of the
	    * WAKE_UP_THS register
	    */

	   return I2C_ReadReg((uint8_t) 0x33);
}
void LIS2_set_WAKE_UP_THS_S_D_TAP(uint8_t en){
	   /*
	    * This registry will switch between
	    * single and double tap being used for
	    * wake up
	    */

	   uint8_t wake_up_ths_state = LIS2_get_WAKE_UP_THS();
	   uint8_t write_val = bitwise_substr_ed(wake_up_ths_state, en, 7, 7);

	   I2C_WriteReg((uint8_t) 0x33, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_THS_S_D_TAP(){
	   /*
	    * This will return a 0 or 1 from the single and double tap
	    * value of the WAKE_UP_THS registry
	    * This value is 0 for single tap enabled
	    * 			1 for double tap enabled
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_THS(), 7, 7);
}
void LIS2_set_WAKE_UP_THS_SLEEP_ON(uint8_t en){
	   /*
	    * This command is used to switch sleep enabled
	    * and disabled in the WAKE_UP_THS registry
	    *
	    * 0 is sleep is disabled
	    * 1 is sleep is enabled
	    */

	   uint8_t wake_up_ths_state = LIS2_get_WAKE_UP_THS();
	   uint8_t write_val = bitwise_substr_ed(wake_up_ths_state, en, 6, 6);

	   I2C_WriteReg((uint8_t) 0x33, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_THS_SLEEP_ON(){
	   /*
	    * This command will return the state of the
	    * sleep enable in the WAKE_UP_THS registry
	    *
	    * 0 is sleep is disabled
	    * 1 is sleep is enabled
	    */
	   return bitwise_substr_p(LIS2_get_WAKE_UP_THS(), 6, 6);
}
void LIS2_set_WAKE_UP_THS_WU_THS(uint8_t wu_ths){
	   /*
	    * This command will set the low level threshold 
	    * for wake up.
	    *
	    * 1 LSB = 1/64 FS
	    */

	   uint8_t wake_up_ths_state = LIS2_get_WAKE_UP_THS();
	   uint8_t write_val = bitwise_substr_ed(wake_up_ths_state, wu_ths, 0, 5);

	   I2C_WriteReg((uint8_t) 0x33, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_THS_WU_THS(){
	   /*
	    * This command will read the low level threshold 
	    * for wake up.
	    *
	    * 1 LSB = 1/64 FS
	    */
	   return bitwise_substr_p(LIS2_get_WAKE_UP_THS(), 0, 5);
}

/* Reg 34 */
uint8_t LIS2_get_WAKE_UP_DUR(){
	   /*
	    * This command reads the full byte from the
	    * WAKE_UP_DUR registry.
	    *
	    * Registry 34
	    */

	   return I2C_ReadReg((uint8_t) 0x34);
}
void LIS2_set_WAKE_UP_DUR_WU_DUR(uint8_t dur){
	   /*
	    * This command sets the 2 bits for wakeup duration
	    *
	    * 1 LSB = 1 TODR
	    */

	   uint8_t wake_up_dur_state = LIS2_get_WAKE_UP_DUR();
	   uint8_t write_val = bitwise_substr_ed(wake_up_dur_state, dur, 5, 6);

	   I2C_WriteReg((uint8_t) 0x34, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_DUR_WU_DUR(){
	   /*
	    * This command reads the 2 bit for wakeup duration
	    *
	    * 1 LSB = 1 TODR
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_DUR(), 5, 6);
}
void LIS2_set_WAKE_UP_DUR_INT1_FSS7(uint8_t en){
	   /*
	    * This commands sets the 1 bit to enable or disable the
	    * FSS7 flag for FIFO on INT1 pad
	    *
	    * 0 is disable
	    * 1 is enable
	    */

	   uint8_t wake_up_dur_state = LIS2_get_WAKE_UP_DUR();
	   uint8_t write_val = bitwise_substr_ed(wake_up_dur_state, en, 4, 4);

	   I2C_WriteReg((uint8_t) 0x34, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_DUR_INT1_FSS7(){
	   /*
	    * This commands sets the 1 bit to enable or disable the
	    * FSS7 flag for FIFO on INT1 pad
	    *
	    * 0 is disable
	    * 1 is enable
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_DUR(), 4, 4);
}
void LIS2_set_WAKE_UP_DUR_SLEEP_DUR(uint8_t dur){
	   /*
	    * This command sets the 4 bit number to set the duration
	    * of time to go into sleep mode
	    *
	    * 1 LSB = 512 TODR
	    */

	   uint8_t wake_up_dur_state = LIS2_get_WAKE_UP_DUR();
	   uint8_t write_val = bitwise_substr_ed(wake_up_dur_state, dur, 0, 3);

	   I2C_WriteReg((uint8_t) 0x34, (uint8_t) write_val);
}
uint8_t LIS2_get_WAKE_UP_DUR_SLEEP_DUR(){
	   /*
	    * This command sets the 4 bit number to set the duration
	    * of time to go into sleep mode
	    *
	    * 1 LSB = 512 TODR
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_DUR(), 0, 3);
}

/* Reg 35 */
uint8_t LIS2_get_FREE_FALL(){
	   /*
	    * Reads the byte from the FREE_FALL registry
	    */

	   return I2C_ReadReg((uint8_t) 0x35);
}
void LIS2_set_FREE_FALL_FF_DUR(uint8_t dur){
	   /*
	    * This command will set the FF_DUR setting across registry
	    * 0x34 and 0x35
	    *
	    * dur is 5 bits
	    * 1 LSB = 1 TODR
	    */

	   uint8_t wake_up_dur_state = LIS2_get_WAKE_UP_DUR();
	   uint8_t free_fall_state = LIS2_get_FREE_FALL();

	   uint8_t wake_up_dur_write = bitwise_substr_ed(wake_up_dur_state, dur>>4, 7, 7);
	   uint8_t free_fall_write = bitwise_substr_ed(free_fall_state, dur, 3, 7);

	   I2C_WriteReg((uint8_t) 0x34, (uint8_t) wake_up_dur_write);
	   I2C_WriteReg((uint8_t) 0x35, (uint8_t) free_fall_write);
}
uint8_t LIS2_get_FREE_FALL_FF_DUR(){
	   /*
	    * This command will return the FF_DUR setting across registries
	    * 0x34 and 0x35
	    *
	    * will return 5 bits
	    * 1 LSB = 1 TODR
	    */

	   uint8_t wake_up_dur_state = LIS2_get_WAKE_UP_DUR();
	   uint8_t free_fall_state = LIS2_get_FREE_FALL();

	   return (uint8_t) num_cat(bitwise_substr_p(wake_up_dur_state, 7, 7), bitwise_substr_p(free_fall_state, 3, 7));
}
void LIS2_set_FREE_FALL_FF_THS(uint8_t thres){
	   /*
	    * This command will set the FF_THS in the
	    * FREE_FALL Registry
	    *
	    * Will be 3 bits
	    * 1 LSB = 31.25 mg
	    */

	   uint8_t free_fall_state = LIS2_get_FREE_FALL();

	   uint8_t free_fall_write = bitwise_substr_ed(free_fall_state, thres, 0, 2);

	   I2C_WriteReg((uint8_t) 0x35, (uint8_t) free_fall_write);
}
uint8_t LIS2_get_FREE_FALL_FF_THS(){
	   /*
	    * This command will read the FF_THS in the
	    * FREE_FALL Registry
	    *
	    * will be 3 bits
	    * 1 LSB = 31.25mg
	    */

	   return bitwise_substr_p(LIS2_get_FREE_FALL(), 0, 2);
}

/* Reg 37 */
uint8_t LIS2_get_WAKE_UP_SRC(){
	   /*
	    * Returns the content of the
	    * WAKE_UP_SRC registry
	    */

	   return I2C_ReadReg((uint8_t) 0x37);
}
uint8_t LIS2_get_WAKE_UP_SRC_FF_IA(){
	   /*
	    * Returns the Free fall detection status bit
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 5, 5);
}
uint8_t LIS2_get_WAKE_UP_SRC_SLEEP_STATE_IA(){
	   /*
	    * Returns the sleep event status
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 4, 4);
}
uint8_t LIS2_get_WAKE_UP_SRC_WU_IA(){
	   /*
	    * Returns the wake up detection status
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 3, 3);
}
uint8_t LIS2_get_WAKE_UP_SRC_X_WU(){
	   /*
	    * Returns the wake up detection status on the X axis
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 2, 2);
}
uint8_t LIS2_get_WAKE_UP_SRC_Y_WU(){
	   /*
	    * Returns the wake up detection status on the Y axis
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 1, 1);
}
uint8_t LIS2_get_WAKE_UP_SRC_Z_WU(){
	   /*
	    * Returns the wake up detection status on the Z axis
	    * in the WAKE_UP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_WAKE_UP_SRC(), 0, 0);
}

/* Reg 38 */
uint8_t LIS2_get_TAP_SRC(){
	   /*
	    * Returns the content of the
	    * TAP_SRC Registry
	    */

	   return I2C_ReadReg((uint8_t) 0x38);
}
uint8_t LIS2_get_TAP_SRC_TAP_IA(){
	   /*
	    * Returns the TAP event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 6, 6);
}
uint8_t LIS2_get_TAP_SRC_S_TAP(){
	   /*
	    * Returns the single tap event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 5, 5);
}
uint8_t LIS2_get_TAP_SRC_D_TAP(){
	   /*
	    * Returns the double tap event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 4, 4);
}
uint8_t LIS2_get_TAP_SRC_TAP_SIGN(){
	   /*
	    * Returns the tap sign event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 3, 3);
}
uint8_t LIS2_get_TAP_SRC_X_TAP(){
	   /*
	    * Returns the x tap event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 2, 2);
}
uint8_t LIS2_get_TAP_SRC_Y_TAP(){
	   /*
	    * Returns the y tap event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 1, 1);
}
uint8_t LIS2_get_TAP_SRC_Z_TAP(){
	   /*
	    * Returns the x tap event status
	    * in TAP_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_TAP_SRC(), 0, 0);
}

/* Reg 39 */
uint8_t LIS2_get_6D_SRC(){
	   /*
	    * Returns the content of the
	    * 6D_SRC Registry
	    */

	   return I2C_ReadReg((uint8_t) 0x39);
}
uint8_t LIS2_get_6D_SRC_6D_IA(){
	   /*
	    * Returns the change in postition event
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 6, 6);
}
uint8_t LIS2_get_6D_SRC_ZH(){
	   /*
	    * Returns the overthreshold of ZH
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 5, 5);
}
uint8_t LIS2_get_6D_SRC_ZL(){
	   /*
	    * Returns the overthreshold of ZL
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 4, 4);
}
uint8_t LIS2_get_6D_SRC_YH(){
	   /*
	    * Returns the overthreshold of YH
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 3, 3);
}
uint8_t LIS2_get_6D_SRC_YL(){
	   /*
	    * Returns the overthreshold of YL
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 2, 2);
}
uint8_t LIS2_get_6D_SRC_XH(){
	   /*
	    * Returns the overthreshold of XH
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 1, 1);
}
uint8_t LIS2_get_6D_SRC_XL(){
	   /*
	    * Returns the overthreshold of XL
	    * in 6D_SRC registry
	    */

	   return bitwise_substr_p(LIS2_get_6D_SRC(), 0, 0);
}
