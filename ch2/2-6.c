#include <stdio.h>
#include <limits.h>

/* getbits: get n bits from position p */
unsigned int getbits(unsigned int x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

//Returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
  unsigned int all_ones_mask = (~0 << p) & ~(0 << (n+p+1));
  return x | (~0 << p);
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
  printbits(0);
  printbits(1);
  printbits(2);
  printbits(3);
  printbits(4);
  printbits(8);
}
