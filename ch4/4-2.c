#include <stdio.h>
#include <math.h>

#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
  double val, power, exp;
  int i, sign, exp_sign;
  for (i = 0; isspace(s[i]); i++) /* skip white space */ ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (exp = 0.0; isdigit(s[i]); i++)
    exp = 10.0 * exp + (s[i] - '0');
  return sign * val / power * pow(10.0, exp_sign * exp);
}

int main()
{
  char test1[] = "12.34E-2";
  printf("%s: %f\n", test1,  atof(test1));

  char test2[] = "12.34E2";
  printf("%s: %f\n", test2, atof(test2));

  char test3[] = "12.34";
  printf("%s: %f\n", test3, atof(test3));


  char test4[] = "12.34e+10";
  printf("%s: %f\n", test4, atof(test4));
}
