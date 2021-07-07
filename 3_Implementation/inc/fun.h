#ifndef __ASCII_H
#define __ASCII_H
#include <stdbool.h>
void Initial(int sizex, int sizey, int *totalEnemies, char enemy, char enemyShielded, char world[][sizex]);
void display(int sizex, int sizey, int score, char world[][sizex]);
void textcolor(int color);
void loadingBar();
void control(int sizex, int sizey, char laserReady, char playerLaser, char player, char keyPress, char world[][sizex]);
void end(int sizex, int sizey, int i, int score, int totalEnemies, int bonus, int victory, char world[][sizex]);
void laser(int sizex, int sizey, int *i, char enemyLaser, char enemy, char enemyShielded, char world[][sizex]);
void disapper(int sizex, int sizey, int *yi, int *i, int *currentEnemies, int *victory, int *score, char player, char playerLaser, int *enemyReady, char explosion, char enemyLaser, char enemy, char enemyShielded, char world[][sizex]);
void e_direction(int y, int sizex, int sizey, char enemy, char direction, int *drop, char world[][sizex]);
void board(int sizex, int sizey, int *enemySpeed, int *i, char direction, int x, int y, int *drop, char enemy, char enemyShielded, int *victory, char world[][sizex]);
void screen();
void ShowConsoleCursor(bool showFlag);
#endif