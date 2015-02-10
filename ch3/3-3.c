#include <stdio.h>

void expand(char s1[], char s2[])
{
  int i = 0;
  int j = 0;
  int used = 0;
  char c, start, end;
  while((c = s1[i++]) != '\0'){
    if(c == '-' && (i-2) >= 0 && s1[i] != '\0')
    {
      j--;
      used = 1;
      start = s1[i-2];
      end = s1[i];
      while(start <= end)
      {
        s2[j++] = start++;
      }
    } else {
      used = 0;
      s2[j++] = c;
    }
  }
  s2[j] = '\0';

}

int main()
{
  char output[1000];

  char test1[] = "a-z";
  expand(test1, output);
  printf("%s\n",output);

  char test2[] = "a-c-f";
  expand(test2, output);
  printf("%s\n",output);

  char test3[] = "a-z0-9";
  expand(test3, output);
  printf("%s\n",output);


  char test4[] = "-a-z0-9-";
  expand(test4, output);
  printf("%s\n",output);
}
