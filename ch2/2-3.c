#include <stdio.h>
#include <ctype.h>

int htoi(char[]);

int main()
{
  char test1[] = "0x0";
  printf("%s,%d\n", test1, htoi(test1));

  char test2[] = "0";
  printf("%s,%d\n", test2, htoi(test2));

  char test3[] = "110";
  printf("%s,%d\n", test3, htoi(test3));

  char test4[] = "f";
  printf("%s,%d\n", test4, htoi(test4));

  char test5[] = "0xff";
  printf("%s,%d\n", test5, htoi(test5));

  char test6[] = "0x00091ff";
  printf("%s,%d\n", test6, htoi(test6));
}


int htoi(char input[])
{
  int index = 0;
  int total = 0;
  char current = 0;
  if(input[0] == '0' && tolower(input[1]) == 'x') {
    index = 2;
  }
  while((current = tolower(input[index])) != '\0') {
    if(current >= 'a' && current <= 'z') {
      total = total * 16 + (current - 'a' + 10);
    } else if (current >= '0' && current <= '9') {
      total = total * 16 + (current - '0');
    }
    index++;
  }
  return total;
}

