#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define ERROR -1

static int stack[STACK_SIZE];
int stack_pointer;

int push(int);

int main(int argc, char *argv[])
{
  stack_pointer = 0;
  printf("got %d args\n", argc);
  --argc;
  ++argv;
  while(--argc > 0) {
    push(atoi(*++argv));
  }
  for(int i = 0; i < stack_pointer; i++) {
    printf("%d: %d\n", i, stack[i]);
  }
}

int push(int n)
{
  if (stack_pointer >= STACK_SIZE) {
    return ERROR;
  }
  stack[stack_pointer] = n;
  stack_pointer++;
  return 0;
}

