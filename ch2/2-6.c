#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

//Returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return x & (getbits(y, p, n) << p);
}

int main()
{

}
