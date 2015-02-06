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
        dest[j] = '\\';
        ++j;
        dest[j] = 't';
        break;
      case '\n':
        dest[j] = '\\';
        ++j;
        dest[j] = 'n';
        break;
      default:
        dest[j] = c;
        break;
    }
    ++j;
  }
  dest[j] = '\0';
}

void unescape(char source[], char dest[])
{
  int i,j = 0;
  char c,d,e;
  while ((c = source[i++]) != '\0')
  {
    switch (c) {
      case '\\':
        d = source[i];
        i++;
        switch (d) {
          case 'n':
            e = '\n';
            break;
          case 't':
            e = '\t';
            break;
        }
        break;
      default:
        dest[j] = c;
        break;
    }
    dest[j++] = e;
  }
  dest[j+1] = '\0';
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
  char output[1000];
  char output2[1000];
  printf("input: %s\n", test);
  escape(test,output);
  printf("input: %s\n", test);
  printf("output: %s\n", output);
  unescape(output, output2);
  printf("output 2: %s\n", output2);
  print_chars(test);
  print_chars(output2);
}
