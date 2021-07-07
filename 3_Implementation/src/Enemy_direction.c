#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

void e_direction(int y, int sizex, int sizey, char enemy, char direction, int *drop, char world[][sizex])
{
    for (y = 0; y < sizey; y++)
    {
        if (world[y][0] == enemy)
        {
            direction = 'r';
            *drop = 1;
            break;
        }
        if (world[y][sizex - 1] == enemy)
        {
            direction = 'l';
            *drop = 1;
            break;
        }
    }
}