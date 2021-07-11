#include "fun.h"

check Over(const int count_enemy, const char *player)
{
    if (count_enemy == 0)
    {
        if (*player == "Alive")
        {
            return YOU_WIN;
        }
        else
        {
            YOU_FAILED;
        }
    }
}