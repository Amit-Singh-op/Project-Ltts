#ifndef __ASCII_H
#define __ASCII_H

void Initial(int sizex, int sizey, int *totalEnemies, char enemy, char enemyShielded, char (*world)[sizex]);
void display(int sizex, int sizey, int score, char (*world)[sizex]);
void textcolor(int color);
void loadingBar();
void control(int sizex, int sizey, char laserReady, char playerLaser, char player, char keyPress, char (*world)[sizex]);
void end(int sizex, int sizey, int i, int score, int totalEnemies, int bonus, int victory, char (*world)[sizex]);
#endif