#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(void) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    fahr_to_celcius();

    fflush(stdout);
    close(pipefd[1]);
    dup2(stdout_bk, fileno(stdout));
    int buf_size = 10240;
    char actual[buf_size];
    read(pipefd[0], actual, buf_size);

    char* expected =
        "0.00 : -17.78\n"
        "20.00 :  -6.67\n"
        "40.00 :   4.44\n"
        "60.00 :  15.56\n"
        "80.00 :  26.67\n"
        "100.00 :  37.78\n"
        "120.00 :  48.89\n"
        "140.00 :  60.00\n"
        "160.00 :  71.11\n"
        "180.00 :  82.22\n"
        "200.00 :  93.33\n"
        "220.00 : 104.44\n"
        "240.00 : 115.56\n"
        "260.00 : 126.67\n"
        "280.00 : 137.78\n"
        "300.00 : 148.89\n";

    ASSERT_STR_EQ(expected, actual);
    memset(actual, 0, buf_size);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_TEST(test_base);
    GREATEST_MAIN_END();
}
