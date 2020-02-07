#include "LIS2DS12.h"
#include "project.h"

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

/* ------------------------ *
 * ------------------------ *
 * LIS2DS12 CTRL1 Functions *
 * ------------------------ *
 * ------------------------ */

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

float get_x_accel(){
	   /* 
	    * Used to grab the current accelerometer information for
	    * x axis
	    */

	   return get_accel(0x29, 0x28);
}

float get_y_accel(){
	   /* 
	    * Used to grab the current accelerometer information for
	    * y axis
	    */

	   return get_accel(0x2B, 0x2A);
}

float get_z_accel(){
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

	   /* calculate prescaled integer by concatenating the high byte and low byte and
	    * undoing two's complimenting of the 2 byte number */
	   prescale = twos_compliment(num_cat(high_byte, low_byte));

	   return ((float) prescale / scaling_f)*9.8;
}

float get_scaling_factor(uint8_t fs){

	   uint16_t scale_f_2g = 0x4000;

	   switch(fs){
			 case 0:
				    return (float) scale_f_2g; /* Case for +/- 2g config */
				    break;
			 case 1:
				    return (float) scale_f_2g/8; /* Case for +/- 16g config */
				    break;
			 case 2:
				    return (float) scale_f_2g/2; /* Case for +/- 4g config */
				    break;
			 case 3:
				    return (float) scale_f_2g/4; /* Case for +/- 8g config */
				    break;
			 default:
				    return (float) scale_f_2g; /* default config */
				    break;
	   }

}

/* ---------------------- *
 * ---------------------- *
 * PSoC I2C R/W Functions *
 * ---------------------- *
 * ---------------------- */

/* --------------------------------------------------- *
 * To repurpose this sensor for other microcontrollers *
 * this should be the only code that needs changing    *
 * --------------------------------------------------- *
 */

uint8_t I2C_ReadReg(uint8_t reg){
	   /*
	    * Performs a Master->Slave read of registry of interest
	    *
	    * reg : registry of interest
	    *
	    * @returns : byte in registry reg
	    */

	   uint8_t readBuf[1] = {0};
	   volatile cy_en_scb_i2c_command_t ackNack = 1u;

	   // Start I2C transaction
	   I2C_MasterSendStart(AGENT_ADDRESS, CY_SCB_I2C_WRITE_XFER, 100);
	   CyDelay(1);

	   // Write Register of interest
	   I2C_MasterWriteByte(reg,100);
	   CyDelay(1);

	   // Change to Read mode
	   I2C_MasterSendReStart(AGENT_ADDRESS, CY_SCB_I2C_READ_XFER, 100);
	   CyDelay(1);

	   // Read from Register specified
	   I2C_MasterReadByte(ackNack, readBuf, 100);
	   CyDelay(1);

	   // End I2C Transaction
	   I2C_MasterSendStop(100);

	   return readBuf[0];

}

void I2C_WriteReg(uint8_t reg, uint8_t val){
	   /*
	    * Performs a Master->Slave write of val to registry of interest
	    *
	    * reg : registry of interest
	    * val : byte to write to registry
	    *
	    * @returns : nothing
	    */

	   // Start I2C transaction
	   I2C_MasterSendStart(AGENT_ADDRESS, CY_SCB_I2C_WRITE_XFER, 100);
	   CyDelay(1);

	   // Write Register of interest
	   I2C_MasterWriteByte(reg, 100);

	   // Write Value to register
	   I2C_MasterWriteByte(val, 100);

	   CyDelay(1);

	   // End I2C Transaction
	   I2C_MasterSendStop(100);
}

/* ------------------------------- *
 * ------------------------------- *
 * Functions for Arithmetic Needed *
 * ------------------------------- *
 * ------------------------------- */

uint16_t num_cat(uint8_t nh, uint8_t nl){
	   /*
	    * Concatenates two 8-bit numbers into one 16-bit number
	    *
	    * nh : high byte number.
	    * nl : low byte number.
	    *
	    * @returns : 16 bit number of the two concatenated.
	    */

	   // Concatenates two unsigned integers
	   return (((uint16_t)nh)<<8)|((uint16_t)nl);

}

int twos_compliment(uint16_t num){
	   /*
	    * Converts 16-bit binary number in two's compliment
	    * to decimal.
	    *
	    * num : number to convert
	    *
	    * @returns : decimal number represented by 16-bit two's compliment
	    */

	   uint8_t negative;
	   int true_int = num;

	   // Determine from first bit is negative
	   negative = num >> 15;
	   // Alternative way of determining negativity
	   // negative = (num & (1 << 15)) != 0;

	   if(negative){
			 return (true_int | ~((1 << 16)-1));
	   }
	   else{
			 return true_int;
	   }
}

uint8_t power(uint8_t base, uint8_t exponent){
	   /*
	    * Standard base^exponent function
	    *
	    * base : base of operation
	    * exponent : exponent of operation
	    *
	    * @returns : base to the power of exponent
	    */

	   int i;
	   int val = 1;

	   for(i = 0; i < exponent; i++)
			 val *= base;

	   return val;

}

uint8_t bitwise_substr_ed(uint8_t word, uint8_t replace, uint8_t index_l, uint8_t index_h){
	   /*
	    * Replaces bits in word from index low to index high with replace
	    *
	    * word : original word to replace part of
	    * replace : sub word to put in word
	    * index_l : lower index of word to replace
	    * index_h : upper index of word to replace
	    *
	    * @returns : word with bits between index_l and index_h (inclusive)
	    * 		  replaced with word in replace.
	    */

	   uint8_t length;
	   uint8_t mask;

	   // Return the word if impossible conditions are provided
	   if((1+index_h-index_l)>8) return word;
	   if(index_h > 7) return word;
	   if(index_l < 0) return word;

	   length = (index_h - index_l) + 1;

	   mask = (power(2,length)-1)<<index_l;

	   return (~(mask) & word) | ((replace << index_l) & mask);

}

uint8_t bitwise_substr_p(uint8_t word, uint8_t index_l, uint8_t index_h){
	   /*
	    * Returns the bits between high and low shifted down to align with LSB
	    *
	    * word : original word to parse
	    * index_l : lower index of word of interest
	    * index_h : upper index of word of interest
	    *
	    * @returns : bits of word between index_h and index_l
	    */

	   uint8_t length;
	   uint8_t mask;

	   // Return the word if impossible conditions are provided
	   if((1+index_h-index_l)>8) return word;
	   if(index_h > 7) return word;
	   if(index_l < 0) return word;

	   length = (index_h - index_l) + 1;

	   mask = (power(2,length)-1) << index_l;

	   return (mask & word) >> index_l;

}
