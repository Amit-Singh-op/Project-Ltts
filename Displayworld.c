#include "fun.h"
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void display(int sizex, int sizey, int score, char **world)
{
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
}
