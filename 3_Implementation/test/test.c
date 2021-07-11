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
    TEST_ASSERT_EQUAL(YOU_HIT_BY_AN_ENEMY, Game_Over(15, player));
}
void Low2(void)
{
    char laser_enemy[10] = "Killed";
    TEST_ASSERT_EQUAL(LASER_ENEMY_CANT_BE_KILLED_BY_PLAYERS_SHOT, Compilation_error(laser_enemy));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(High);
    RUN_TEST(Low1);
    RUN_TEST(Low2);
    return UNITY_END();
}
