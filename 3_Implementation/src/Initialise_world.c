#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

void Initial(int sizex, int sizey, int *totalEnemies, char enemy, char enemyShielded, char world[][sizex])
{
    for (int x = 0; x < sizex; x++)
    {
        for (int y = 0; y < sizey; y++)
        {
            if ((y + 1) % 2 == 0 && y < 7 && x > 4 && x < sizex - 5 && x % 2 == 0)
            {
                world[y][x] = enemy;
                *totalEnemies = *totalEnemies + 1;
            }
            else if ((y + 1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < sizex - 5 && x % 2 == 0)
            {
                world[y][x] = enemyShielded;
                *totalEnemies = *totalEnemies + 2;
            }
            else
            {
                world[y][x] = ' ';
            }
        }
    }
}