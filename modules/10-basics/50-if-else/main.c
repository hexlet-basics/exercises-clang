#include <stdio.h>

void fizzbuzz(int limit);

int main(void)
{
    fizzbuzz(20);
    return 0;
}

// BEGIN
void fizzbuzz(int limit)
{
    int i;

    for (i=1; i<=limit; ++i) {
        if (!(i % 15))
            printf("FizzBuzz");
        else if (!(i % 3))
            printf("Fizz");
        else if (!(i % 5))
            printf("Buzz");
        else
            printf("%d", i);

        if (i < limit)
            printf(" ");
    }
}
// END
