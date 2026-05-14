#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(void) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    celsius_to_kelvin();

    fflush(stdout);
    close(pipefd[1]);
    dup2(stdout_bk, fileno(stdout));
    int buf_size = 10240;
    char actual[buf_size];
    read(pipefd[0], actual, buf_size);

    char* expected =
        "0 : 273\n"
        "20 : 293\n"
        "40 : 313\n"
        "60 : 333\n"
        "80 : 353\n"
        "100 : 373\n"
        "120 : 393\n"
        "140 : 413\n"
        "160 : 433\n"
        "180 : 453\n"
        "200 : 473\n"
        "220 : 493\n"
        "240 : 513\n"
        "260 : 533\n"
        "280 : 553\n"
        "300 : 573\n";

    ASSERT_STR_EQ(expected, actual);
    memset(actual, 0, buf_size);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_INIT();
    greatest_parse_options(argc, argv);
    RUN_TEST(test_base);
    GREATEST_PRINT_REPORT();
    return (greatest_all_passed() ? EXIT_SUCCESS : EXIT_FAILURE);
}
