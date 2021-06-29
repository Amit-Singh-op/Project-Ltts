#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char tic[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char sign, place;
int check()
{
    int end = 1;
    if ((tic[0] == 'x' && tic[1] == 'x' && tic[2] == 'x') || (tic[0] == '0' && tic[1] == '0' && tic[2] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[3] == 'x' && tic[4] == 'x' && tic[5] == 'x') || (tic[3] == '0' && tic[4] == '0' && tic[5] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[6] == 'x' && tic[7] == 'x' && tic[8] == 'x') || (tic[6] == '0' && tic[7] == '0' && tic[8] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[0] == 'x' && tic[4] == 'x' && tic[8] == 'x') || (tic[0] == '0' && tic[4] == '0' && tic[8] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[2] == 'x' && tic[4] == 'x' && tic[6] == 'x') || (tic[2] == '0' && tic[4] == '0' && tic[6] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[0] == 'x' && tic[3] == 'x' && tic[6] == 'x') || (tic[0] == '0' && tic[3] == '0' && tic[6] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[1] == 'x' && tic[4] == 'x' && tic[7] == 'x') || (tic[1] == '0' && tic[4] == '0' && tic[7] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user is win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
    else if ((tic[2] == 'x' && tic[5] == 'x' && tic[8] == 'x') || (tic[2] == '0' && tic[5] == '0' && tic[8] == '0'))
    {
        if (sign == 'x')
        {
            printf("\nCongrats! ");
            printf("1 user win the game\n");
        }
        else
        {
            printf("\nCongrats! ");
            printf("2 user win the game\n");
        }
        return (end);
    }
}
void replace()
{
    char temp;
    for (int i = 0; i < 9; i++)
    {
        if (place == tic[i])
        {
            temp = tic[i];
            tic[i] = sign;
            break;
        }
    }
}
void turn()
{
    int turn;
    printf("Which player start the game 1 player or 2 player:");
    scanf("%d", &turn);
    if (turn == 1)
    {
    repeate1:
        printf("1 user turn your symbol is:x\n");
        fflush(stdin);
        printf("choose place:");
        scanf("%c", &place);
        fflush(stdin);
        printf("Enter your symbol:");
        scanf("%c", &sign);
        if (sign != 'x')
        {
            printf("Sorry you enter invalid sign.");
            printf("Your game is ended\n");
            goto repeate1;
        }
    }
    else if (turn == 2)
    {
    repeate:
        printf("2 user turn your symbol is:0\n");
        fflush(stdin);
        printf("choose place:");
        scanf("%c", &place);
        fflush(stdin);
        printf("Enter your symbol:");
        scanf("%c", &sign);
        if (sign != '0')
        {
            printf("Sorry you enter invalid sign.");
            printf("Try again\n");
            goto repeate;
        }
    }
    else
    {
        printf("Sorry incorrect player number");
        printf("Start game again\n");
        exit(0);
    }
}
void view()
{
    printf("\n        *********WELCOME TO TICTOE GAME********\n\n");
    printf("                  |*****|*****|*****|\n");
    printf("                  |  %c  |  %c  |  %c  |\n", tic[0], tic[1], tic[2]);
    printf("                  |*****|*****|*****|\n");
    printf("                  |  %c  |  %c  |  %c  |\n", tic[3], tic[4], tic[5]);
    printf("                  |*****|*****|*****|\n");
    printf("                  |  %c  |  %c  |  %c  |\n", tic[6], tic[7], tic[8]);
    printf("                  |*****|*****|*****|\n\n");
}
void reInitialise()
{
    tic[0] = '1';
    tic[1] = '2';
    tic[2] = '3';
    tic[3] = '4';
    tic[4] = '5';
    tic[5] = '6';
    tic[6] = '7';
    tic[7] = '8';
    tic[8] = '9';
}
void main()
{
    int end = 0;
    char startAgain;
    for (int i = 0; i < 9; i++)
    {
        view();
        if (end == 1)
        {
        Again:
            printf("If you want to play again then");
            fflush(stdin);
            printf(" press 'Y' utherwise press 'N':");
            scanf("%c", &startAgain);
            if (startAgain == 'n' || startAgain == 'N')
            {
                exit(0);
            }
            else if (startAgain == 'y' || startAgain == 'Y')
            {
                reInitialise();
                i = 0;
            }
            else
            {
                printf("Sorry! you press invalid character");
                printf(" Try again\n");
                goto Again;
            }
        }
        turn();
        replace();
        end = check();
        if (i == 9)
        {
            printf("Match is draw\n");
        }
    }
}