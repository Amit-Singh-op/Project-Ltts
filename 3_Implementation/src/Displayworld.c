#include "fun.h"
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
void display(int sizex, int sizey, int score, char world[][sizex])
{
    system("cls");
    textcolor(11);
    printf("     SCORE:    %d", score);
    printf("\n\n");
    for (int y = 0; y < sizey; y++)
    {
        textcolor(8);
        printf("\t\t\t\t\t|");
        for (int x = 0; x < sizex; x++)
        {
            if (world[y][x] == '0')
            {
                textcolor(7);
                printf("%c", world[y][x]);
            }
            else if (world[y][x] == 'O')
            {
                textcolor(11);
                printf("%c", world[y][x]);
            }
            else if (world[y][x] == '^')
            {
                textcolor(14);
                printf("%c", world[y][x]);
            }
            else if (world[y][x] == '*')
            {
                textcolor(12);
                printf("%c", world[y][x]);
            }
            else if (world[y][x] == 'o')
            {
                textcolor(8);
                printf("%c", world[y][x]);
            }
            else
            {
                textcolor(12);
                printf("%c", world[y][x]);
            }
        }
        textcolor(8);
        printf("|");
        printf("\n");
    }
}
