#include <stdio.h>
#include <stdlib.h>

int kelvin_to_celcius(int);

int main(int argc, char **argv)
{
    int num = atoi(argv[1]);
    printf("%d\n", kelvin_to_celcius(num));
    return 0;
}

// BEGIN
int kelvin_to_celcius(int kelvin) {

    int celcius;
    celcius = kelvin - 273;
    return celcius;
}
// END
