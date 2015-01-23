//Q: (In two's compliment) x &= (x-1) deletes the rightmost bit of x. Why?
//A: If x is odd x = x & x-1 will set the rightmost bit to 0.
//Anding the 2 numbers will leave all the bits the same,
//EXCEPT the last one which will always be 0, since anything & 0 is 0
//If x is even, then all consecutive rightmosts ones become zeros and the last
//bit will become 1. That number & x will cancel out the new ones so they are
//the same as before, but the last bit of an even number was already 0, so it
//will stay 0
#include <stdio.h>

/* improved bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x &= (x-1))
      b++;
  return b;
}

int main()
{
  printf("%u\n", bitcount(0));
  printf("%u\n", bitcount(~0));
  printf("%u\n", bitcount(31));
}
