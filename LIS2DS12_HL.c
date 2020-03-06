#include "LIS2DS12_HL.h"
#include "LIS2DS12_LL.h"

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

/* ---------------------------------- *
 * ---------------------------------- *
 * High Level Accelerometer Functions *
 * ---------------------------------- *
 * ---------------------------------- */

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
