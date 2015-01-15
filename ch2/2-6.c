#include <stdio.h>
#include <limits.h>

/* getbits: get n bits from position p */
unsigned int getbits(unsigned int x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

//Returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
  //will have 0s at position p to p+n and 1s everywhere else
  unsigned int ones_mask = (~0 << p) | (~0 >> (p+n+1));
  return x | (~0 << p);
}
//setbits(0b001,3,2,0b010) -> 0b101
//
unsigned int ones_mask(int p, int n)
{
  return (~0 << p) | ~(~0 << (p-n));
}

void printbits(unsigned int counter)
{
  printf("%u: ", counter);
  for(int x = 0; x < 33; x++){
    printf("%u", (counter >> (32 - x)) & 1);
  }
  printf("\n");
}

int main()
{
  printbits(ones_mask(9,8));
}
