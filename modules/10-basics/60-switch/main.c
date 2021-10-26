#include <stdio.h>
#include <stdlib.h>

void number_printer(int number);

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  number_printer(num);
  return 0;
}

// BEGIN
void number_printer(int number)
{

  switch(number)
  {
    case 0:
      printf ("Zero");
      break;
    case 1:
      printf ("One");
      break;
    case 2:
      printf ("Two");
      break;
    case 3:
      printf ("Three");
      break;
    default:
      printf("%d", number);
  }
}
// END
