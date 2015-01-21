#include <stdio.h>

/* getbits: get n bits from position p */
unsigned int getbits(unsigned int x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned int ones_mask(int p, int n)
{
  return (~0 << p) | ~(~0 << (p-n));
}


//Returns x with the n bits that begin
//at position p set to the rightmost n bits of y,
//leaving the other bits unchanged
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
  unsigned int mask = x & ones_mask(p,n);
  unsigned int set = getbits(y, n-1, n) << (p - n);
  return mask | set;
}

void printbits(unsigned int counter)
{
  for(int x = 0; x < 33; x++){
    printf("%u", (counter >> (32 - x)) & 1);
  }
  printf(": %u", counter);
  printf("\n");
}

int main()
{
  unsigned int x = 0;
  int p = 5;
  int n = 3;
  unsigned int y = ~0;

  printf("x: ");
  printbits(x);
  printf("p: ");
  printbits(p);
  printf("n: ");
  printbits(n);
  printf("y: ");
  printbits(y);
  printbits(x & ones_mask(p,n));
  printbits(getbits(y,n-1,n) << (p -n));
  printf("=  ");
  printbits(setbits(x,p,n,y));
}
