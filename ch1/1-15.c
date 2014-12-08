#include <stdio.h>

/* print Celsius-Fahrenheit table
 fahr = 0,20, ..., 300 */

float fahr_to_celc(int);

main ()
{
  int fahr;
  for(fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%3d %6.1f\n", fahr, fahr_to_celc(fahr));;
  return 0;
}

float fahr_to_celc(int fahr)
{
  return (5.0/9.0)*(fahr - 32);
}
