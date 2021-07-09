#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void test_null_inputs(void)
{
    char *ouput_string = " ";
    char *test_string = " ";

    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(NULL, ouput_string));
    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(test_string, NULL));
    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(NULL, NULL));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_null_inputs);
    return UNITY_END();
}
