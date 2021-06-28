#include <stdio.h>
int main()
{
    int *p;
    int t = 20;
    p = &t;
    int **p1 = &p;
    *p = 30;
    printf("%d", **p1);
}