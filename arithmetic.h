#ifndef ARITHMETIC_h
#define ARITHMETIC_h

/* ------------------------------- *
 * ------------------------------- *
 * Functions for Arithmetic Needed *
 * ------------------------------- *
 * ------------------------------- */

uint16_t num_cat(uint8_t nh, uint8_t nl);

int twos_compliment(uint16_t num);

uint8_t power(uint8_t base, uint8_t exponent);

uint8_t bitwise_substr_ed(uint8_t word, uint8_t replace, uint8_t index_l, uint8_t index_h);

uint8_t bitwise_substr_p(uint8_t word, uint8_t index_l, uint8_t index_h);

#endif

/* [] END OF FILE */
