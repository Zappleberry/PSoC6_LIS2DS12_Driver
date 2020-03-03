#include "I2C_RW.h"
#include "project.h"

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
