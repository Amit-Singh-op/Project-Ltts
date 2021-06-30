#include <stdio.h>
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
    printf("\t\t\t\t                _ _   _                     _               \n");
    printf("\t\t\t\t  __ _ ___  ___(_|_) (_)_ ____   ____ _  __| | ___ _ __ ___ \n");
    printf("\t\t\t\t / _` / __|/ __| | | | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|\n");
    printf("\t\t\t\t| (_| \\__ \\ (__| | | | | | | \\ V / (_| | (_| |  __/ |  \\__ \\\n");
    printf("\t\t\t\t \\__,_|___/\\___|_|_| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/\n");

    /*welcome screen*/
    printf("\n \n     Welcome soldier! \n \n \n \n");
    Sleep(1000);
    printf("  Hero of world is back. \n \n \n \n");
    Sleep(2500);
    printf("  Let's fight. \n \n \n \n");
    Sleep(2500);
    printf("               Good luck!! Let's Go.");
    Sleep(1000);
    printf("\n \n \n \n Press any key to start.");
    getch();
}
