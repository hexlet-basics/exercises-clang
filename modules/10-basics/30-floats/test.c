#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(void) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    km_to_mi();

    fflush(stdout);
    close(pipefd[1]);
    dup2(stdout_bk, fileno(stdout));
    int buf_size = 10240;
    char actual[buf_size];
    read(pipefd[0], actual, buf_size);

    char* expected =
        "0.00 : 0.00\n"
        "20.00 : 12.42\n"
        "40.00 : 24.84\n"
        "60.00 : 37.26\n"
        "80.00 : 49.68\n"
        "100.00 : 62.10\n"
        "120.00 : 74.52\n"
        "140.00 : 86.94\n"
        "160.00 : 99.36\n"
        "180.00 : 111.78\n"
        "200.00 : 124.20\n"
        "220.00 : 136.62\n"
        "240.00 : 149.04\n"
        "260.00 : 161.46\n"
        "280.00 : 173.88\n"
        "300.00 : 186.30\n";

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
