#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
void control(int sizex, int sizey, char laserReady, char playerLaser, char player, char keyPress, char world[][sizex])
{
    if (kbhit())
    {
        keyPress = getch();
    }
    else
    {
        keyPress = ' ';
    }
    if (keyPress == 'a')
    {
        for (int x = 0; x < sizex; x = x + 1)
        {
            if (world[sizey - 1][x + 1] == player)
            {
                world[sizey - 1][x] = player;
                world[sizey - 1][x + 1] = ' ';
            }
        }
    }

    if (keyPress == 'd')
    {
        for (int x = sizex - 1; x > 0; x = x - 1)
        {
            if (world[sizey - 1][x - 1] == player)
            {
                world[sizey - 1][x] = player;
                world[sizey - 1][x - 1] = ' ';
            }
        }
    }
    if (keyPress == 'm' && laserReady > 2)
    {
        for (int x = 0; x < sizex; x = x + 1)
        {
            if (world[sizey - 1][x] == player)
            {
                world[sizey - 2][x] = playerLaser;
                laserReady = 0;
            }
        }
    }
}