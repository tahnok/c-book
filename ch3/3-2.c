#include <stdio.h>
/*
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

void escape(char source[], char dest[])
{
  int i,j = 0;
  char c;
  while ((c = source[i++]) != '\0')
  {
    switch (c) {
      case '\t':
        putchar('+');
        dest[j] = '\\';
        ++j;
        dest[j] = 't';
        break;
      case '\n':
        putchar('+');
        dest[j] = '\\';
        ++j;
        dest[j] = 'n';
        break;
      default:
        putchar('.');
        dest[j] = c;
        break;
    }
    ++j;
  }
  dest[j] = '\0';
  putchar('\n');
}

void print_chars(char s[])
{
  int i = 0;
  char c;
  while((c = s[i]) != '\0')
  {
    printf("%d ",c);
    ++i;
  }
  printf("\n");
}

int main()
{
  char test[] = "\t\n";
  char output[sizeof(test) / sizeof(char)];
  printf("input: %s\n", test);
  escape(test,output);
  printf("input: %s\n", test);
  printf("output: %s\n", output);
  print_chars(output);
}
