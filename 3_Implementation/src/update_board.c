#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

void board(int sizex, int sizey, int *enemySpeed, int *i, char direction, int x, int y, int *drop, char enemy, char enemyShielded, int *victory, char world[][sizex])
{
    if (*i % *enemySpeed == 0)
    {
        if (direction == 'l')
        {
            for (x = 0; x < sizex - 1; x++)
            {
                for (y = 0; y < sizey; y++)
                {
                    if (*drop && (world[y - 1][x + 1] == enemy || world[y - 1][x + 1] == enemyShielded))
                    {
                        world[y][x] = world[y - 1][x + 1];
                        world[y - 1][x + 1] = ' ';
                    }
                    else if (!*drop && (world[y][x + 1] == enemy || world[y][x + 1] == enemyShielded))
                    {
                        world[y][x] = world[y][x + 1];
                        world[y][x + 1] = ' ';
                    }
                }
            }
        }
        else
        {
            for (x = sizex; x > 0; x--)
            {
                for (y = 0; y < sizey; y++)
                {
                    if (*drop && (world[y - 1][x - 1] == enemy || world[y - 1][x - 1] == enemyShielded))
                    {
                        world[y][x] = world[y - 1][x - 1];
                        world[y - 1][x - 1] = ' ';
                    }
                    else if (!*drop && (world[y][x - 1] == enemy || world[y][x - 1] == enemyShielded))
                    {
                        world[y][x] = world[y][x - 1];
                        world[y][x - 1] = ' ';
                    }
                }
            }
        }
        for (x = 0; x < sizex; x++)
        {
            if (world[sizey - 1][x] == enemy)
            {
                *victory = 0;
            }
        }
    }
}