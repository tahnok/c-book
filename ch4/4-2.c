#include <stdio.h>

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

  return sign * val / power;
}

int main()
{

}
