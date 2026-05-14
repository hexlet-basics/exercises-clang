#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(int limit, char *expected) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    fizzbuzz(limit);

    fflush(stdout);
    close(pipefd[1]);
    dup2(stdout_bk, fileno(stdout));
    int buf_size = 10240;
    char actual[buf_size];
    read(pipefd[0], actual, buf_size);

    ASSERT_STR_EQ(expected, actual);
    memset(actual, 0, buf_size);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_INIT();
    greatest_parse_options(argc, argv);
    RUN_TESTp(
        test_base,
        5,
        "1 2 Fizz 4 Buzz"
    );
    RUN_TESTp(
        test_base,
        10,
        "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz"
    );
    RUN_TESTp(
        test_base,
        20,
        "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz"
    );
    GREATEST_PRINT_REPORT();
    return (greatest_all_passed() ? EXIT_SUCCESS : EXIT_FAILURE);
}
