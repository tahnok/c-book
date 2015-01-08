#include <stdio.h>

/* squeeze2: delete all chars in remove from string */
void squeeze2(char string[], char remove[])
{
  int eos = 0;
  for(int i = 0; string[i] != '\0'; i++) {
    int found = 0;
    for(int j = 0; remove[j] != '\0'; j++) {
      if(string[i] == remove[j]) {
        found = 1;
        break;
      }
    }
    if(!found)
      string[eos++] = string[i];
  }
  string[eos] = '\0';
}

int main()
{
  char string[] = "abbccaaccdda";
  char remove[] = "ab";
  squeeze2(string, remove);
  printf("%s\n", string);
}
