#include "arithmetic.h"

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
