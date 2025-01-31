#include <stdio.h>
#include <cstdio>

// BEGIN
void number_printer(int number) {
  switch (number) {
    case 0:
      printf("Zero");
      break;
    case 1:
      printf("One");
      break;
    case 2:
      printf("Two");
      break;
    case 3:
      printf("Three");
      break;
    default:
      printf("%d", number);
  }
}
// END
