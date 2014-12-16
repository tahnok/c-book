#include <limits.h>
#include <stdio.h>
#include <float.h>

int main()
{
  int a = 1;
  int b = 0;
  while( a > b) {
    b = a;
    ++a;
  }
  printf("ints\n");
  printf("%d\n", b);
  printf("%d\n", INT_MAX);

  unsigned int unsigned_long = 1;
  unsigned int unsigned_longb = 0;
  while( unsigned_long > unsigned_longb) {
    unsigned_longb = unsigned_long;
    ++unsigned_long;
  }
  printf("unsigned_long\n");
  printf("%u\n", unsigned_longb);
  printf("%u\n", UINT_MAX);

  char c = 1;
  char d = 0;
  while( c > d) {
    d = c;
    ++c;
  }
  printf("chars\n");
  printf("%d\n", d);
  printf("%d\n", CHAR_MAX);


  unsigned short unsigned_short = 1;
  unsigned short unsigned_shortb = 0;
  while( unsigned_short > unsigned_shortb) {
    unsigned_shortb = unsigned_short;
    ++unsigned_short;
  }
  printf("unsigned_short\n");
  printf("%u\n", unsigned_shortb);
  printf("%u\n", USHRT_MAX);
}
