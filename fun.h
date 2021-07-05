#ifndef __ASCII_H
#define __ASCII_H

void Initial(int sizex, int sizey, int *totalEnemies, char enemy, char enemyShielded, char **world);
void display(int sizex, int sizey, int score, char **world);
void textcolor(int color);
void loadingBar();

#endif