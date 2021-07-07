#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

void disapper(int sizex, int sizey, int *yi, int *i, int *currentEnemies, int *victory, int *score, char player, char playerLaser, int *enemyReady, char explosion, char enemyLaser, char enemy, char enemyShielded, char world[][sizex])
{
    for (int x = 0; x < sizex; x++)
    {
        for (int y = 0; y < sizey; y++)
        {
            if ((*i % 5) == 0 && (world[y][x] == enemyShielded | world[y][x] == enemy) && (rand() % 15) > 13 && world[y + 1][x] != playerLaser)
            {
                for (*yi = y + 1; *yi < sizey; *yi = *yi + 1)
                {
                    if (world[*yi][x] == enemy | world[*yi][x] == enemyShielded)
                    {
                        *enemyReady = 0;
                        break;
                    }
                    *enemyReady = 1;
                }
                if (*enemyReady)
                {
                    world[y + 1][x] = enemyLaser;
                }
            }
            if (world[y][x] == playerLaser && world[y - 1][x] == enemy)
            {
                world[y][x] = ' ';
                world[y - 1][x] = explosion;
                *currentEnemies = *currentEnemies - 1;
                *score = *score + 50;
            }
            else if (world[y][x] == playerLaser && world[y - 1][x] == enemyShielded)
            {
                world[y][x] = ' ';
                world[y - 1][x] = enemy;
                *currentEnemies = *currentEnemies - 1;
                *score = *score + 50;
            }
            else if (world[y][x] == playerLaser && world[y - 1][x] == enemyLaser)
            {
                world[y][x] = ' ';
            }
            else if (world[y][x] == explosion)
            {
                world[y][x] = ' ';
            }
            else if ((*i + 1) % 2 == 0 && world[y][x] == enemyLaser && world[y + 1][x] == player)
            {
                world[y + 1][x] = explosion;
                world[y][x] = ' ';
                *victory = 0;
            }
            else if (world[y][x] == playerLaser && world[y - 1][x] != enemyLaser)
            {
                world[y][x] = ' ';
                world[y - 1][x] = playerLaser;
            }
        }
    }
}