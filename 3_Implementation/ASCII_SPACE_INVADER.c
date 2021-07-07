#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

void ClearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}
void delay(unsigned int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
int main()
{
    ShowConsoleCursor(false);
    const int sizey = 23;
    const int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = 'A';
    char playerLaser = '*';
    char enemy = 'E';
    char enemyShielded = 'B';
    char enemyLaser = 'U';
    char explosion = 'X';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

    srand(time(NULL));

    /*welcome screen*/

    printf("\n\n\n");
    textcolor(2);
    printf("\t\t\t\t                _ _   _                     _               \n");
    Sleep(1000);
    textcolor(2);
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    Sleep(1000);
    textcolor(2);
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    Sleep(1000);
    textcolor(2);
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    Sleep(1000);
    textcolor(2);
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");

    printf("\n\n");
    int c = 0;
    char s[] = {'\n', '\n', '\n', '\n', '\n', '\t', '\t', '"', 'C', 'O', 'M', 'M', 'A', 'N', 'D', 'E', 'R', '"', ' ', ':',
                ' ', 'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 'S', 'o', 'l', 'd', 'i', 'e', 'r', '!', '!', '!', ' ',
                '.', '.', '.', '.', '.', '.', '.', ' ',
                'W', 'e', ' ', 'g', 'o', 't', 't', 'a', ' ', 's', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'w', 'o', 'r', 'l', 'd', '!', '!', '!', ' ',
                'S', 'o', ' ', 'L', 'e', 't', 's', ' ', 'd', 'o', ' ', 't', 'h', 'i', 's', '!', '!', '!', ' ',
                '\0'};
    for (c = 0; s[c] != '\0'; c++)
    {
        textcolor(3);
        printf("%c", s[c]);
        delay(250);
    }
    loadingBar(); //loading bar
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
    return 0;
}
