#include <stdio.h>
int main()
{
    char *arr = (char *)malloc(1000 * sizeof(char));
    int i = 0;
    char c;
    while (c != '\n')
    {
        c = getchar();
        arr[i++] = c;
    }
    arr[i] = '\0';
    printf("%s", arr);
}