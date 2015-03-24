#include <stdio.h>
#include <stdlib.h>

void my_reverse(char toreverse[], int start, int end)
{
  if(start >= end)
    return;
  printf("swapping %d and %d\n", start, end);
  char temp = toreverse[start];
  toreverse[start] = toreverse[end];
  toreverse[end] = temp;
  my_reverse(toreverse, ++start, --end);
  return;
}

void reverse(char toreverse[])
{
  int pos = 0;
  do {
    pos++;
  } while(toreverse[pos] != '\0');
  printf("%d chars\n", pos);
  pos--;
  my_reverse(toreverse, 0, pos);
}

int main()
{
  char number[] = "123456789";
  reverse(number);
  printf("%s\n", number);
}
