#include "LIS2DS12.h"
#include "I2C_RW.h"
#include "arithmetic.h"

/* -------------------------- *
 * -------------------------- *
 * LIS2DS12 WHO_AM_I Function *
 * -------------------------- *
 * -------------------------- */

uint8_t LIS2_who_am_i(){
	   /* 
	    * WHO_AM_I register is read only in 0x0F register
	    * Should return 0x43
	    */
	   
	   return I2C_ReadReg((uint8_t) 0x0F);

}

/* ----------------------------- *
 * ----------------------------- *
 * LIS2DS12 Power Mode Functions *
 * ----------------------------- *
 * ----------------------------- */

void LIS2_odr_powerdown(){
	   /* 
	    * Sends ODR of sensor into Power Down mode
	    */
	   
	   LIS2_ctrl1_change_odr(0x0);

}

void LIS2_odr_lp_1(){
	   /* 
	    * Send ODR of sensor into Low Power mode
	    * at 1 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x8);

}

void LIS2_odr_lp_13(){
	   /* 
	    * Send ODR of sensor into Low Power mode
	    * at 12.5 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x9);

}

void LIS2_odr_lp_25(){
	   /* 
	    * Send ODR of sensor into Low Power mode
	    * at 25 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xA);

}

void LIS2_odr_lp_50(){
	   /* 
	    * Send ODR of sensor into Low Power mode
	    * at 50 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xB);

}

void LIS2_odr_lp_100(){
	   /*
	    * Send ODR of sensor into Low Power mode
	    * at 100 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xC);

}

void LIS2_odr_lp_200(){
	   /* 
	    * Send ODR of sensor into Low Power mode
	    * at 200 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xD);

}

void LIS2_odr_lp_400(){
	   /*
	    * Send ODR of sensor into Low Power mode
	    * at 400 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xE);

}

void LIS2_odr_lp_800(){
	   /*
	    * Send ODR of sensor into Low Power mode
	    * at 800 Hz
	    * 10 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0xF);

}

void LIS2_odr_hr_13(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 12.5 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x1);

}

void LIS2_odr_hr_25(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 25 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x2);

}

void LIS2_odr_hr_50(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 50 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x3);

}

void LIS2_odr_hr_100(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 100 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_odr(0x4);

}

void LIS2_odr_hr_200(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 200 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x0);
	   LIS2_ctrl1_change_odr(0x5);

}

void LIS2_odr_hr_400(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 400 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x0);
	   LIS2_ctrl1_change_odr(0x6);

}

void LIS2_odr_hr_800(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 800 Hz
	    * 14 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x0);
	   LIS2_ctrl1_change_odr(0x7);

}

void LIS2_odr_hf_1600(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 1600 Hz
	    * 12 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x1);
	   LIS2_ctrl1_change_odr(0x5);

}

void LIS2_odr_hf_3200(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 3200 Hz
	    * 12 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x1);
	   LIS2_ctrl1_change_odr(0x6);

}

void LIS2_odr_hf_6400(){
	   /*
	    * Send ODR of sensor into High Resolution mode
	    * at 6400 Hz
	    * 12 bit resolution
	    */

	   LIS2_ctrl1_change_hf_odr(0x1);
	   LIS2_ctrl1_change_odr(0x7);

}

void LIS2_fs_2g(){
	   /*
	    * Change sensitivity to 2g's
	    */

	   LIS2_ctrl1_change_fs(0x0);
}

void LIS2_fs_16g(){
	   /*
	    * Change sensitivity to 16g's
	    */

	   LIS2_ctrl1_change_fs(0x1);
}

void LIS2_fs_4g(){
	   /*
	    * Change sensitivity to 4g's
	    */

	   LIS2_ctrl1_change_fs(0x2);
}

void LIS2_fs_8g(){
	   /*
	    * Change sensitivity to 8g's
	    */

	   LIS2_ctrl1_change_fs(0x3);
}

void LIS2_bdu_enable(){
	   /*
	    * Enable BDU
	    */

	   LIS2_ctrl1_change_bdu(1);
}

void LIS2_bdu_disable(){
	   /*
	    * Disable BDU
	    */

	   LIS2_ctrl1_change_bdu(0);
}

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

/* ---------------------------- *
 * ---------------------------- *
 * LIS2DS12 Interrupt Functions *
 * ---------------------------- *
 * ---------------------------- */

void LIS2_Interrupt_Enable(uint8_t interrupt, uint8_t interrupt_type){
	   /*
	    * Enables interrupt_type on interrupt interrupt
	    *
	    * interrupt is which interrupt to use
	    * (1 or 2)
	    * interrupt_type is what type of interrupt to use
	    * (i.e. single tap, double tap, etc.)
	    */

	   switch(interrupt){
			 case 1: 
				    switch(interrupt_type){
						  case MASTER_DRDY:
								LIS2_ctrl4_int1_master_drdy(1);
								break;
						  case SINGLE_TAP:
								LIS2_ctrl4_int1_s_tap(1);
								break;
						  case WAKEUP:
								LIS2_ctrl4_int1_wu(1);
								break;
						  case FREEFALL:
								LIS2_ctrl4_int1_ff(1);
								break;
						  case DOUBLE_TAP:
								LIS2_ctrl4_int1_dtap(1);
								break;
						  case SIX_D:
								LIS2_ctrl4_int1_6D(1);
								break;
						  case FIFO_THRES:
								LIS2_ctrl4_int1_fth(1);
								break;
						  case DRDY:
								LIS2_ctrl4_int1_drdy(1);
								break;
						  default: break;
				    }
				    break;
			 case 2:

				    switch(interrupt_type){
						  case MASTER_DRDY:
								LIS2_ctrl5_int2_master_drdy(1);
								break;
						  case SINGLE_TAP:
								LIS2_ctrl5_int2_s_tap(1);
								break;
						  case WAKEUP:
								LIS2_ctrl5_int2_wu(1);
								break;
						  case FREEFALL:
								LIS2_ctrl5_int2_ff(1);
								break;
						  case DOUBLE_TAP:
								LIS2_ctrl5_int2_dtap(1);
								break;
						  case SIX_D:
								LIS2_ctrl5_int2_6D(1);
								break;
						  case FIFO_THRES:
								LIS2_ctrl5_int2_fth(1);
								break;
						  case DRDY:
								LIS2_ctrl5_int2_drdy(1);
								break;
						  default: break;
				    }
				    break;
			 default: break;
	   }

}

void LIS2_Interrupt_Disable(uint8_t interrupt, uint8_t interrupt_type){
	   /*
	    * Disables interrupt_type on interrupt interrupt
	    *
	    * interrupt is which interrupt to use
	    * (1 or 2)
	    * interrupt_type is what type of interrupt to use
	    * (i.e. single tap, double tap, etc.)
	    */

	   switch(interrupt){
			 case 1: 
				    switch(interrupt_type){
						  case MASTER_DRDY:
								LIS2_ctrl4_int1_master_drdy(0);
								break;
						  case SINGLE_TAP:
								LIS2_ctrl4_int1_s_tap(0);
								break;
						  case WAKEUP:
								LIS2_ctrl4_int1_wu(0);
								break;
						  case FREEFALL:
								LIS2_ctrl4_int1_ff(0);
								break;
						  case DOUBLE_TAP:
								LIS2_ctrl4_int1_dtap(0);
								break;
						  case SIX_D:
								LIS2_ctrl4_int1_6D(0);
								break;
						  case FIFO_THRES:
								LIS2_ctrl4_int1_fth(0);
								break;
						  case DRDY:
								LIS2_ctrl4_int1_drdy(0);
								break;
						  default: break;
				    }
				    break;
			 case 2:

				    switch(interrupt_type){
						  case MASTER_DRDY:
								LIS2_ctrl5_int2_master_drdy(0);
								break;
						  case SINGLE_TAP:
								LIS2_ctrl5_int2_s_tap(0);
								break;
						  case WAKEUP:
								LIS2_ctrl5_int2_wu(0);
								break;
						  case FREEFALL:
								LIS2_ctrl5_int2_ff(0);
								break;
						  case DOUBLE_TAP:
								LIS2_ctrl5_int2_dtap(0);
								break;
						  case SIX_D:
								LIS2_ctrl5_int2_6D(0);
								break;
						  case FIFO_THRES:
								LIS2_ctrl5_int2_fth(0);
								break;
						  case DRDY:
								LIS2_ctrl5_int2_drdy(0);
								break;
						  default: break;
				    }
				    break;
			 default: break;
	   }

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


/* -------------------------------- *
 * -------------------------------- *
 * LIS2DS12 Accelerometer Functions *
 * -------------------------------- *
 * -------------------------------- */

float LIS2_get_x_accel(){
	   /* 
	    * Used to grab the current accelerometer information for
	    * x axis
	    */

	   return get_accel(0x29, 0x28);
}

float LIS2_get_y_accel(){
	   /* 
	    * Used to grab the current accelerometer information for
	    * y axis
	    */

	   return get_accel(0x2B, 0x2A);
}

float LIS2_get_z_accel(){
	   /* 
	    * Used to grab the current accelerometer information for
	    * z axis
	    */

	   return get_accel(0x2D, 0x2C);
}

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

