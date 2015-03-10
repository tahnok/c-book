#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VAR '1' /* signal that a variable was found */
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
double vartoval(char []);
double setvar(double);

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
int stackop = 0;

int lastvar;
double vars[26];

/* reverse Polish calculator */
int main()
{
  int type;
  double op2;
  double op1;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case VAR:
        push(vartoval(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push(fmod(pop(), op2));
        break;
      case '\n':
        if(!stackop) {
          printf("\t%.8g\n", pop());
        } else {
          stackop = 0;
        }
        break;
      case '@':
        stackop = 1;
        op1 = pop();
        push(op1);
        printf("\t%.8g\n", op1);
        break;
      case '$':
        sp = 0;
        break;
      case ':':
        op2 = pop();
        op1 = pop();
        push(op2);
        push(op1);
        break;
      case ';':
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case '(':
        push(sin(pop()));
        break;
      case ')':
        push(cos(pop()));
        break;
      case '{':
        push(exp(pop()));
        break;
      case '}':
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case '=':
        op2 = pop();
        push(setvar(pop()));
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n"); return 0.0;
  }
}

#define LINE_LIMIT  1000
char line[LINE_LIMIT];
int line_index = 0;
int getline2(char s[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c;
  if(line[line_index] == '\0')
    getline2(line, LINE_LIMIT);

  while ((s[0] = c = line[line_index++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-') {
    if (isalpha(c)) {
      return VAR;
    } else {
      return c; /* not a number */
    }
  }
  i = 0;
  if (isdigit(c) || c == '-') /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  if(!strcmp("-", s))
      return '-';
  return NUMBER;
}

double vartoval(char c[])
{
  return vars[lastvar = (tolower(c[0]) - 'a')];
}

double setvar(double v)
{
  vars[lastvar] = v;
  return v;
}
