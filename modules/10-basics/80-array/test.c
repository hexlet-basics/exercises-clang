#include "greatest.h"
#include "main.c"

TEST test_base(void) {
    int arr_positive[5] = { 1, 2, 3, 4, 5 };
    int arr_negative[5] = { -2, -3, -4, -5, 8 };
    int arr_empty[] = {};

    ASSERT_EQ(15, sum(arr_positive, 5));
    ASSERT_EQ(-6, sum(arr_negative, 5));
    ASSERT_EQ(0, sum(arr_empty, 0));
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_TEST(test_base);
    GREATEST_MAIN_END();
}
