#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(int number, char *expected) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    number_printer(number);

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
    GREATEST_MAIN_BEGIN();
    RUN_TESTp(test_base, 0, "Zero");
    RUN_TESTp(test_base, 1, "One");
    RUN_TESTp(test_base, 2, "Two");
    RUN_TESTp(test_base, 3, "Three");
    RUN_TESTp(test_base, 4, "4");
    RUN_TESTp(test_base, 9, "9");
    GREATEST_MAIN_END();
}
