#include <CUnit/CUnit.h>
#include "main.c"

int main(void)
{
// BEGIN
    /* printf("Hello, World!"); */
// END
    /* return 1; */
    CU_ASSERT(f() == 0);
    /* printf("%d", f()); */
}


    int maxi(int i1, int i2)
    {
      return (i1 > i2) ? i1 : i2;
    }

    void test_maxi(void)
    {
      CU_ASSERT(maxi(0,2) == 2);
      CU_ASSERT(maxi(0,-2) == 0);
      CU_ASSERT(maxi(2,2) == 2);
    }
