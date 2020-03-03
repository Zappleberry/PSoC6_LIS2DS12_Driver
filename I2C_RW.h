#ifndef I2C_RW_h
#define I2C_RW_h

#include "project.h"

#define AGENT_ADDRESS 0x1E

/* ---------------------- *
 * ---------------------- *
 * PSoC I2C R/W Functions *
 * ---------------------- *
 * ---------------------- */

uint8_t I2C_ReadReg(uint8_t reg);
void I2C_WriteReg(uint8_t reg, uint8_t val);

#endif

/* [] END OF FILE */
