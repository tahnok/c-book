#include <stdio.h>

/* squeeze2: delete all c from s */
void squeeze(char s[], char c[])
{
  int i, j, k;
  for (i = j = 0; s[i] != '\0'; i++)
    for(k = 0; c[k] != '\0'; k++)
      if (s[i] != c[k])
        s[j++] = s[i];
  s[j] = '\0';
}

int main()
{
  char string[] = "abbccaaccdda";
  char remove[] = "";
  squeeze(string, remove);
  printf("%s\n", &string);
}
