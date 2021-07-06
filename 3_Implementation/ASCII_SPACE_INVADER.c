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
    char world[sizey][sizex];
    /*char **world = (char **)malloc(sizey * sizeof(char *));
    for (int r = 0; r < sizey; r++)
        world[r] = (char *)malloc(sizex * sizeof(char));
*/
    char player = 'A';
    system("color 0a");
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

    printf("\n\n\n");
    /*
    printf("\t\t\t\t                _ _   _                     _               \n");
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");
    */
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

    /*welcome screen*/
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
    loadingBar();
    //Sleep(1000);
    printf("\n\n\n\n\t\t Press any key to start.");
    getch();

    /*initialise world*/

    int totalEnemies = 0;
    Initial(sizex, sizey, &totalEnemies, enemy, enemyShielded, world); /*initialising world*/

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

        display(sizex, sizey, score, world); //displaying world

        /**/
        /*laser time*/
        for (x = 0; x < sizex; x++)
        {
            for (y = sizey - 1; y >= 0; y--)
            {
                if (i % 2 == 0 && world[y][x] == enemyLaser && (world[y + 1][x] != enemy & world[y + 1][x] != enemyShielded))
                {
                    world[y + 1][x] = enemyLaser;
                    world[y][x] = ' ';
                }
                else if (i % 2 == 0 && world[y][x] == enemyLaser && (world[y + 1][x] == enemy | world[y + 1][x] == enemyShielded))
                {
                    world[y][x] = ' ';
                }
            }
        }
        for (x = 0; x < sizex; x++)
        {
            for (y = 0; y < sizey; y++)
            {
                if ((i % 5) == 0 && (world[y][x] == enemyShielded | world[y][x] == enemy) && (rand() % 15) > 13 && world[y + 1][x] != playerLaser)
                {
                    for (yi = y + 1; yi < sizey; yi++)
                    {
                        if (world[yi][x] == enemy | world[yi][x] == enemyShielded)
                        {
                            enemyReady = 0;
                            break;
                        }
                        enemyReady = 1;
                    }
                    if (enemyReady)
                    {
                        world[y + 1][x] = enemyLaser;
                    }
                }
                if (world[y][x] == playerLaser && world[y - 1][x] == enemy)
                {
                    world[y][x] = ' ';
                    world[y - 1][x] = explosion;
                    currentEnemies--;
                    score = score + 50;
                }
                else if (world[y][x] == playerLaser && world[y - 1][x] == enemyShielded)
                {
                    world[y][x] = ' ';
                    world[y - 1][x] = enemy;
                    currentEnemies--;
                    score = score + 50;
                }
                else if (world[y][x] == playerLaser && world[y - 1][x] == enemyLaser)
                {
                    world[y][x] = ' ';
                }
                else if (world[y][x] == explosion)
                {
                    world[y][x] = ' ';
                }
                else if ((i + 1) % 2 == 0 && world[y][x] == enemyLaser && world[y + 1][x] == player)
                {
                    world[y + 1][x] = explosion;
                    world[y][x] = ' ';
                    victory = 0;
                }
                else if (world[y][x] == playerLaser && world[y - 1][x] != enemyLaser)
                {
                    world[y][x] = ' ';
                    world[y - 1][x] = playerLaser;
                }
            }
        }

        /*update enemy direction*/
        for (y = 0; y < sizey; y++)
        {
            if (world[y][0] == enemy)
            {
                direction = 'r';
                drop = 1;
                break;
            }
            if (world[y][sizex - 1] == enemy)
            {
                direction = 'l';
                drop = 1;
                break;
            }
        }

        /*update board*/
        if (i % enemySpeed == 0)
        {
            if (direction == 'l')
            {
                for (x = 0; x < sizex - 1; x++)
                {
                    for (y = 0; y < sizey; y++)
                    {
                        if (drop && (world[y - 1][x + 1] == enemy || world[y - 1][x + 1] == enemyShielded))
                        {
                            world[y][x] = world[y - 1][x + 1];
                            world[y - 1][x + 1] = ' ';
                        }
                        else if (!drop && (world[y][x + 1] == enemy || world[y][x + 1] == enemyShielded))
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
                        if (drop && (world[y - 1][x - 1] == enemy || world[y - 1][x - 1] == enemyShielded))
                        {
                            world[y][x] = world[y - 1][x - 1];
                            world[y - 1][x - 1] = ' ';
                        }
                        else if (!drop && (world[y][x - 1] == enemy || world[y][x - 1] == enemyShielded))
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
                    victory = 0;
                }
            }
        }

        //player move and shoot
        control(sizex, sizey, laserReady, playerLaser, player, keyPress, world);
        /////
        i++;
        Sleep(50);
    }
    system("cls");
    printf("     SCORE:    %d", score);
    printf("\n");
    for (y = 0; y < sizey; y++)
    {
        printf("|");
        for (x = 0; x < sizex; x++)
        {
            printf("%c", world[y][x]);
        }
        printf("|");
        printf("\n");
    }
    Sleep(1000);
    system("cls");
    if (victory != 0)
    {
        printf("\n \n \n \n \n \n               CONGRATULATIONS! \n \n \n \n \n");
        Sleep(1000);
        printf("\n \n               Score: %d", score);
        Sleep(1000);
        int bonus = totalEnemies * 20 - i;
        printf("\n \n               Bonus: %d", bonus);
        Sleep(1000);
        printf("\n \n               Total Score: %d", score + bonus);
        printf("\n \n \n \n               Well done");
        Sleep(1000);
        printf(", Hero.");
        Sleep(1000);
        getch();
    }
    else
    {
        printf("\n \n \n \n \n \n               You have failed.");
        Sleep(1000);
        printf("\n \n \n \n \n \n               Windows is doomed.");
        Sleep(1000);
        printf("\n \n               Final Score: %d", score);
        getch();
    }

    /*
    int bonus = totalEnemies * 20 - i;
    end(sizex, sizey, i, score, totalEnemies, bonus, victory, world);
    */
}
