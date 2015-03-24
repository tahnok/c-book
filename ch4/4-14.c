#include <stdio.h>

#define swap(t,x,y) \
  t temp = x; \
  x = y; \
  y = temp;


int main()
{
  int i = 2;
  int j = 3;
  swap(int,i,j);
  printf("i was 2, now is %d, j was 3, now is %d\n", i, j);
}
