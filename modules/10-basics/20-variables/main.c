#include <stdio.h>

// BEGIN
int main(void)
{
  int celcius, kelvin;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celcius = lower;

  while (celcius <= upper) {
    kelvin = celcius + 273;
    printf("%d : %d\n", celcius, kelvin);
    celcius = celcius + step;
  }

  return 0;
}
// END
