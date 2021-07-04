#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
void delay(unsigned int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}

int main()
{
    //started
    int size_of_y = 25;
    int size_of_x = 40;
    int x, y, yi;
    char earth[size_of_y][size_of_x];
    char player = 'A';
    char player_gun = '^';
    char enemy = '*';
    char enemy_with_shield = 'x';
    char enemy_with_laser_power = '.';
    char explosion = '-';

    srand(time(NULL));

    printf("\n\n\n");
    /*
    printf("\t\t\t\t                _ _   _                     _               \n");
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");
    */

    printf("\t\t\t\t                _ _   _                     _               \n");
    sleep(1);
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    sleep(1);
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    sleep(1);
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    sleep(1);
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
    printf("\n\n");
    int c = 0;
    
    char s[] = {'\n','\n','\n','\n','\t','\t','"','C', 'O', 'M', 'M', 'A', 'N', 'D','E','R','"',':', '\n',
                '\t','\t','\t','\t','W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 'S', 'o', 'l', 'd', 'i', 'e', 'r', '!','!','!', ' ',
                '.', '.', '.', '.', '.', '.', '.',' ',
                'W', 'e', ' ', 'g', 'o', 't', 't', 'a', ' ', 's', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'w', 'o', 'r', 'l', 'd','!','!','!',' ',
                'S', 'o', ' ', 'L', 'e', 't','s', ' ', 'd', 'o', ' ', 'i', 't','!','!','!',' ',
                '\0'};
    for (c = 0; s[c] != '\0'; c++)
    {
        printf("%c", s[c]);
        delay(250);
    }
    Sleep(1000);
    printf("\n\n\n\n\n\n\t\t Press any key to start.");
    getch();
    
    
   // system("MODE 45,25");
   //	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
	
	//printf("helllllo");

    /*initialise earth*/
}
