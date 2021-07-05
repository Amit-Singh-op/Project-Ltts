#include "fun.h"
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
void display(int sizex, int sizey, int score, char **world)
{
    system("cls");
    textcolor(4);
    printf("     SCORE:    %d", score);
    printf("\n\n");
    for (int y = 0; y < sizey; y++)
    {
        textcolor(6);
        printf("\t\t\t\t\t|");
        for (int x = 0; x < sizex; x++)
        {
            textcolor(5);
            printf("%c", world[y][x]);
        }
        textcolor(6);
        printf("|");
        printf("\n");
    }
}
