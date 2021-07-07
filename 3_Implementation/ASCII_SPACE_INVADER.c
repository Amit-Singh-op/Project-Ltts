#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    bool a = FALSE;
    ShowConsoleCursor(a);
    const int sizey = 23;
    const int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = '^';
    char playerLaser = '*';
    char enemy = '0';
    char enemyShielded = 'O';
    char enemyLaser = 'o';
    char explosion = 'x';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

    srand(time(NULL));

    /*welcome screen*/
    screen();

    loadingBar(); //loading bar
    printf("\n");

    /*printf("\n\n\n\n\t\t Press any key to start.");
    getch();

    /*initialise world*/

    int totalEnemies = 0;
    Initial(sizex, sizey, &totalEnemies, enemy, enemyShielded, world); /*initialising world*/

    /* */
    world[sizey - 1][sizex / 2] = player;
    int i = 1;
    char direction = 'l';
    char keyPress;
    int currentEnemies = totalEnemies;

    while (currentEnemies > 0 && victory)
    {
        int drop = 0;
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady++;

        /*display world*/

        display(sizex, sizey, score, world);

        /*/

        /*laser time*/

        laser(sizex, sizey, &i, enemyLaser, enemy, enemyShielded, world);

        /* */

        /*Disappearing enemy after shooting*/

        disapper(sizex, sizey, &yi, &i, &currentEnemies, &victory, &score, player, playerLaser, &enemyReady, explosion, enemyLaser, enemy, enemyShielded, world);

        /**/

        /*update enemy direction*/

        e_direction(y, sizex, sizey, enemy, direction, &drop, world);

        /* */

        /*update board*/

        board(sizex, sizey, &enemySpeed, &i, direction, x, y, &drop, enemy, enemyShielded, &victory, world);
        /* */

        /*player move and shoot*/

        control(sizex, sizey, laserReady, playerLaser, player, keyPress, world);
        /* */
        i++;
        Sleep(50);
    }

    /*end Game*/

    int bonus = totalEnemies * 20 - i;
    end(sizex, sizey, i, score, totalEnemies, bonus, victory, world);

    /*  */
    Sleep(500);
    printf("\n");
    return 0;
}
