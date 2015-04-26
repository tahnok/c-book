#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

static int stack[STACK_SIZE];
int stack_pointer;

void push(int);
int pop(void);
void parse(char*);

int main(int argc, char *argv[])
{
  stack_pointer = 0;
  --argc;
  ++argv; //ignore program file name
  while(--argc >= 0) {
    parse(*argv++);
  }
  /* for(int i = 0; i < stack_pointer; i++) { */
  /*   printf("%d: %d\n", i, stack[i]); */
  /* } */
  /* while(stack_pointer > 0) { */
  /*   printf("%d\n", pop()); */
  /* } */
  printf("%d\n", pop());
}

void push(int n)
{
  if (stack_pointer >= STACK_SIZE) {
    printf("ERROR: stack empty\n");
  }
  stack[stack_pointer] = n;
  stack_pointer++;
}

int pop()
{
  if (stack_pointer < 0) {
    printf("ERROR: stack empty\n");
    return 0;
  }
  return stack[--stack_pointer];
}

void parse(char *input)
{
  char op;
  int temp;
  int temp2;

  if (isdigit(*input)) {
    push(atoi(input));
  } else if( strlen(input) == 1){
    op = input[0];
    switch(op) {
      case '+':
        push(pop() + pop());
        break;
      case '*':
        temp = pop();
        temp2 = pop();
        printf("%d * %d = %d\n", temp, temp2, temp * temp2);
        break;
      case '-':
        temp = pop();
        push(pop() - temp);
        break;
      default:
        printf("unknown op\n");
    }
  } else {
    printf("%s\n", input);
  }
}
