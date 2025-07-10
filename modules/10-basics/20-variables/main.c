#include <stdio.h>

void celsius_to_kelvin(void) {
  // BEGIN
  int celsius, kelvin;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  while (celsius <= upper) {
    kelvin = celsius + 273;
    printf("%d : %d\n", celsius, kelvin);
    celsius = celsius + step;
  }
  // END
}
