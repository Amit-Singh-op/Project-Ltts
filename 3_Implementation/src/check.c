#include "fun.h"
#include <stdio.h>

check Over(const int count_enemy, char *player)
{
    if (count_enemy == 0)
    {
        char *check = "Alive";
        if (strcmp(player, check) == 0)
        {
            return YOU_WIN;
        }
        else
        {
            YOU_FAILED;
        }
    }
}