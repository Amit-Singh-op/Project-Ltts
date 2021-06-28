#include <stdio.h>
int main()
{
    int *p;
    int t = 20;
    p = &t;
    int **p1 = &p;
    printf("%d", **p1);
}