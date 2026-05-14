#include "greatest.h"
#include "main.c"

TEST test_base(void) {
    char *format = "%d";
    ASSERT_EQ_FMT(2927, kelvin_to_celcius(3200), format);
    ASSERT_EQ_FMT(-546, kelvin_to_celcius(-273), format);
    ASSERT_EQ_FMT(-273, kelvin_to_celcius(0), format);
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
