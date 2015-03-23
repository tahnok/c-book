#include <stdio.h>
#include <stdlib.h>

void my_reverse(char toreverse[], int start, int end)
{
  //TODO

}

void reverse(char toreverse[])
{
  int pos, i, j;
  pos = 0;
  char temp;
  while(toreverse[pos++] != '\0');
  pos--;
  for(i = 0; i < pos / 2; i++) {
    j = pos - i - 1;
    temp = toreverse[i];
    toreverse[i] = toreverse[j];
    toreverse[j] = temp;
  }
}

int main()
{
  char number[] = "1234567890";
  reverse(number);
  printf("%s\n", number);
}
