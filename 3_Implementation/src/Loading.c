#include <Windows.h>
#include "fun.h"
#include <stdio.h>
void loadingBar()
{
    char a = 177, b = 219;
    textcolor(15);
    printf("\n\n\n\n\t\t\t\t\t"
           "Loading...\n\n");

    printf("\t\t\t\t\t");

    for (int i = 0; i < 42; i++)
        //textcolor(9);
        printf("%c", a);

    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 42; i++)
    {
        //textcolor(9);
        printf("%c", b);
        Sleep(200);
    }
}