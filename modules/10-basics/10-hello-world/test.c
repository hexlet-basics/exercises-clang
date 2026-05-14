#include "greatest.h"
#include <unistd.h>
#include "main.c"

TEST test_base(void) {
    int stdout_bk = dup(fileno(stdout));
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], fileno(stdout));

    hello();

    fflush(stdout);
    close(pipefd[1]);
    dup2(stdout_bk, fileno(stdout));
    int buf_size = 10240;
    char actual[buf_size];
    read(pipefd[0], actual, buf_size);

    ASSERT_STR_EQ("Hello, World!", actual);
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
