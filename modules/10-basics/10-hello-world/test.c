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
    int buf_size = 1024;
    char actual[1024];
    read(pipefd[0], actual, 1024);

    ASSERT_STR_EQ("Hello, World!", actual);
    memset(actual, 0, buf_size);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_TEST(test_base);
    GREATEST_MAIN_END();
}
