#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

void delay(unsigned int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}

void screen()
{
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
}