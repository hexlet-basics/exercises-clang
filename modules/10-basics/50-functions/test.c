#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "main.c"

void test_base(void)
{
    CU_ASSERT(kelvin_to_celcius(3200) == 2927);
    CU_ASSERT(kelvin_to_celcius(-273) == -546);
    CU_ASSERT(kelvin_to_celcius(0) == -273);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("kelvin_to_celcius", 0, 0);
    CU_add_test(suite, "test_base", test_base);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    int exit_code = (CU_get_number_of_failure_records() == 0) ? 0 : 1;
    CU_cleanup_registry();

    return exit_code;
}
