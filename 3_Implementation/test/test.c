#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void success(void)
{
    char *ouput_string = " ";
    char *test_string = " ";

    TEST_ASSERT_EQUAL(SUCCESS, extract_string(NULL, ouput_string));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(success);
    return UNITY_END();
}
