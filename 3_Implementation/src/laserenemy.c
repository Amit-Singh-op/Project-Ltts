#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

void laser(int sizex, int sizey, int *i, char enemyLaser, char enemy, char enemyShielded, char world[][sizex])
{
    for (int x = 0; x < sizex; x++)
    {
        for (int y = sizey - 1; y >= 0; y--)
        {
            if (*i % 2 == 0 && world[y][x] == enemyLaser && (world[y + 1][x] != enemy & world[y + 1][x] != enemyShielded))
            {
                world[y + 1][x] = enemyLaser;
                world[y][x] = ' ';
            }
            else if (*i % 2 == 0 && world[y][x] == enemyLaser && (world[y + 1][x] == enemy | world[y + 1][x] == enemyShielded))
            {
                world[y][x] = ' ';
            }
        }
    }
}