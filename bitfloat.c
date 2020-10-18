#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// Return the bit value (0 or 1) at position pos of unsigned int n
// Note that the least significant bit position is 0. 
int get_bit_at_pos(unsigned int n, int pos)
{
  // TODO: Your code here. 
  return 1 & (n>>pos); 
}

// Set the bit value to 1 at position pos of unsigned int n,
// while leaving other bits unchanged. 
// Return the changed integer.
// Note that the least significant bit position is 0. 
int set_bit_at_pos(unsigned int n, int pos)
{
  // TODO: Your code here.
  int mask = 1 << pos; 
  return (n & ~mask | mask); 
}

// Return the most significant byte of unsigned int n
char get_most_significant_byte(unsigned int n)
{
  // TODO: Your code here.
  return (n>>24); 

}

// Return true if n1+n2 causes overflow, return false otherwise
bool sum_overflowed(int n1, int n2)
{
  // TODO: Your code here.
  if (n1 > 0 && n2 > 0 && n1 + n2 < 0) {
    return true; 
  }
  if (n1 < 0 && n2 < 0 && n1 + n2 > 0) {
    return true; 
  }
  return false; 
} 

//Extract the 8-bit exponent field of single precision floating point number f 
//and return it as an unsigned byte
unsigned char get_exponent_field(float f) 
{
  //TODO: Your code here.
  //return (char)(((int)f & 0x7f800000) >> 23);
  int *i = (int*)&f; 
  return ((*i & 0x7f800000)>>23); 
}

