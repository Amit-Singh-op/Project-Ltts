#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void check(void)
{
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(check);
    return UNITY_END();
}
