#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

void High(void)
{
    char player[10] = "Alive";
    TEST_ASSERT_EQUAL(YOU_WIN, Game_Over(0, player));
}
void Low1(void)
{
    char player[10] = "Dead";
    char hit[5] = "yes";
    TEST_ASSERT_EQUAL(YOU_HIT_BY_AN_ENEMY, hit_by_enemy(, player));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(High);
    return UNITY_END();
}
