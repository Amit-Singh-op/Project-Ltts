#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void success(void)
{
    const char player[10] = "Alive";
    TEST_ASSERT_EQUAL(YOU_WIN, Over(0, player));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(success);
    return UNITY_END();
}
