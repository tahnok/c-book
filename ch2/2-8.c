#include <stdio.h>

void printbits(unsigned int counter)
{
  for(int x = 0; x < 33; x++){
    printf("%u", (counter >> (32 - x)) & 1);
  }
  printf(": %u", counter);
  printf("\n");
}

unsigned int rightrot(unsigned int x, int n)
{
  return (x >> n) | (x << (x - n));
}

int main()
{
  unsigned int x = ~31;
  int n = 5;
  printf("x: ");
  printbits(x);
  printf("=: ");
  printbits(rightrot(x,n));
}
