#include <stdio.h>

void printbits(unsigned int counter)
{
  for(int x = 0; x < 33; x++){
    printf("%u", (counter >> (32 - x)) & 1);
  }
  printf(": %u", counter);
  printf("\n");
}

unsigned int ones_mask(int p, int n)
{
  return (~0 << p) | ~(~0 << (p-n));
}


unsigned int invert(unsigned int x, int p, int n)
{
  unsigned mask = ones_mask(p,n);
  return (x & mask) | (~x & ~mask);
}

int main()
{
  unsigned int x = 13;
  int p = 4;
  int n = 3;

  printf("x: ");
  printbits(x);
  printf("=: ");
  printbits(invert(x,p,n));

}
