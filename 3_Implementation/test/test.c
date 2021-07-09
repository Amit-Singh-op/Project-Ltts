#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void i_run()
{
    TEST_ASSERT_EQUAL(2, i_value(1));
    TEST_ASSERT_EQUAL(3, i_value(2));
    TEST_ASSERT_EQUAL(4, i_value(3));
    TEST_ASSERT_EQUAL(3, i_value(4));
    TEST_ASSERT_EQUAL(3, i_value(5));
    TEST_ASSERT_EQUAL(5, i_value(6));
    TEST_ASSERT_EQUAL(5, i_value(7));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(i_run);
    return UNITY_END();
}
