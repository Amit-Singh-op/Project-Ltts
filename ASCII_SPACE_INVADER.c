#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
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
/*
void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}
*/
int main()
{
    ShowConsoleCursor(false);
    //remove_scrollbar();
    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    //char world[sizey][sizex];
    char **world = (char **)malloc(sizey * sizeof(char *));
    for (int r = 0; r < sizey; r++)
        world[r] = (char *)malloc(sizex * sizeof(char));

    char player = '+';
    system("color 0a");
    //getch();
    //printf("\033[33mThis is yellow\033[0m");
    char playerLaser = '^';
    char enemy = 'E';
    char enemyShielded = 'B';
    char enemyLaser = 'U';
    char explosion = 'X';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

    srand(time(NULL));

    printf("\n\n\n\n\n\n");
    /*
    printf("\t\t\t\t                _ _   _                     _               \n");
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");
    */

    printf("\t\t\t\t                _ _   _                     _               \n");
    Sleep(400);
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    Sleep(400);
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    Sleep(400);
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    Sleep(400);
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");

    /*welcome screen*/
    /*
    printf("Mission: ");
    printf("Welcome soldier!");
    Sleep(1000);
    printf("Hero of world is back. \n \n \n \n");
    Sleep(2500);
    printf("  Let's save the world. \n \n \n \n");
    Sleep(2500);
    printf("               Good luck!! Let's Go.");
    Sleep(1000);
    printf("\n \n \n \n Press any key to start.");

    */
    printf("\n\n\n");
    int c = 0;

    char s[] = {'\n', '\n', '\n', '\n', '\n', '\t', '\t', '"', 'C', 'O', 'M', 'M', 'A', 'N', 'D', 'E', 'R', '"', ':',
                '\t', 'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 'S', 'o', 'l', 'd', 'i', 'e', 'r', '!', '!', '!', ' ',
                '.', '.', '.', '.', '.', '.', '.', ' ',
                'W', 'e', ' ', 'g', 'o', 't', 't', 'a', ' ', 's', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'w', 'o', 'r', 'l', 'd', '!', '!', '!', ' ',
                'S', 'o', ' ', 'L', 'e', 't', 's', ' ', 'd', 'o', ' ', 't', 'h', 'i', 's', '!', '!', '!', ' ',
                '\0'};
    for (c = 0; s[c] != '\0'; c++)
    {
        printf("%c", s[c]);
        delay(250);
    }
    Sleep(1000);
    printf("\n\n\n\n\n\n\t\t Press any key to start.");
    getch();

    /*initialise world*/
    int totalEnemies = 0;
    for (x = 0; x < sizex; x++)
    {
        for (y = 0; y < sizey; y++)
        {
            if ((y + 1) % 2 == 0 && y < 7 && x > 4 && x < sizex - 5 && x % 2 == 0)
            {
                world[y][x] = enemy;
                totalEnemies++;
            }
            else if ((y + 1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < sizex - 5 && x % 2 == 0)
            {
                world[y][x] = enemyShielded;
                totalEnemies = totalEnemies + 2;
            }
            else
            {
                world[y][x] = ' ';
            }
        }
    }
    //Initial(sizex, sizey, &totalEnemies, enemy, enemyShielded, world);

    world[sizey - 1][sizex / 2] = player;
    int i = 1;
    char direction = 'l';
    char keyPress;
    int currentEnemies = totalEnemies;
    //int currentEnemies = 1;

    //printf("%d", totalEnemies);

    while (currentEnemies > 0 && victory)
    {
        int drop = 0;
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady++;

        /*display world*/
        //Sleep(2000);
        /*
        system("cls");
        printf("     SCORE:    %d", score);
        printf("\n\n");
        for (int y = 0; y < sizey; y++)
        {
            printf("\t\t\t\t\t|");
            for (int x = 0; x < sizex; x++)
            {
                printf("%c", world[y][x]);
            }

            printf("|");
            printf("\n");
        }
*/
        display(sizex, sizey, score, world);

        /**/
    }
}
