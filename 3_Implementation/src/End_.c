#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

void end(int sizex, int sizey, int i, int score, int totalEnemies, int bonus, int victory, char world[][sizex])
{
    /*system("cls");
    printf("     SCORE:    %d", score);
    printf("\n");
    for (int y = 0; y < sizey; y++)
    {
        printf("|");
        for (int x = 0; x < sizex; x++)
        {
            printf("%c", world[y][x]);
        }
        printf("|");
        printf("\n");
    }
    */
    Sleep(1000);
    system("cls");
    if (victory != 0)
    {
        printf("\n \n \n \n \n \n               CONGRATULATIONS! \n \n \n \n \n");
        Sleep(1000);
        printf("\n \n               Score: %d", score);
        Sleep(1000);
        printf("\n \n               Bonus: %d", bonus);
        Sleep(1000);
        printf("\n \n               Total Score: %d", score + bonus);
        printf("\n \n \n \n               Well done");
        Sleep(1000);
        printf(", Hero.");
        Sleep(1000);
        //getch();
    }
    else
    {
        printf("\n \n \n \n \n \n               You have failed.");
        Sleep(1000);
        printf("\n \n               Game is Over.");
        Sleep(1000);
        printf("\n \n               Final Score: %d", score);
        //getch();
    }
}