#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void check(char, char);
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void gamename()
{
    printf("\n\t\t\t TIC TAC TOE GAME : \n");
}
void show()
{
    printf("\n\n\t\t\t---|---|--- \n");
    printf("\t\t\t %c | %c | %c\n", a[0], a[1], a[2]);
    printf("\t\t\t---|---|--- \n");
    printf("\t\t\t %c | %c | %c\n", a[3], a[4], a[5]);
    printf("\t\t\t---|---|--- \n");
    printf("\t\t\t %c | %c | %c\n", a[6], a[7], a[8]);
    printf("\t\t\t---|---|--- \n");
}
void inputsymbol()
{
    printf("\nPlayer 1 symbol : X : ");
    printf("\nPlayer 2 symbol : O : ");
}
void start()
{
    char pa;
    printf("\nEnter Who will start the Game : Player1 or Player 2 \n");
    scanf("%c", &pa);
}
int count = 0;
void play()
{
    char p, s;
    printf("Enter the postion and the symbol for the player: \n");
    fflush(stdin);
    scanf("%c", &p);
    fflush(stdin);
    scanf("%c", &s);
    count++;
    check(p, s);
}
void check(char p, char s)
{
    int i;
    for (i = 0; i <= 8; i++)
    {
        if (a[i] == p)
        {
            a[i] = s;
        }
    }
}
void message()
{
    printf("Next move :: \n");
}
int end()
{
    if ((a[0] == 'X' && a[1] == 'X' && a[2] == 'X') || (a[0] == 'X' && a[3] == 'X' && a[6] == 'X'))
        return 100;
    else if ((a[0] == 'O' && a[1] == 'O' && a[2] == 'O') || (a[0] == 'O' && a[3] == 'O' && a[6] == 'O'))
        return 200;
    else if (a[1] == 'X' && a[4] == 'X' && a[7] == 'X') return 100;
    else if (a[1] == 'O' && a[4] == 'O' && a[7] == 'O') return 200;
    else if (a[2] == 'X' && a[5] == 'X' && a[8] == 'X') return 100;
    else if (a[2] == 'O' && a[5] == 'O' && a[8] == 'O') return 200;
    else if (a[3] == 'X' && a[4] == 'X' && a[5] == 'X') return 100;
    else if (a[3] == 'O' && a[4] == 'O' && a[5] == 'O') return 200;
    else if (a[2] == 'X' && a[4] == 'X' && a[6] == 'X') return 100;
    else if (a[2] == 'O' && a[4] == 'O' && a[6] == 'O') return 200;
    else if (a[6] == 'X' && a[7] == 'X' && a[8] == 'X') return 100;
    else if (a[6] == 'O' && a[7] == 'O' && a[8] == 'O') return 200;
    else if (a[0] == 'X' && a[4] == 'X' && a[8] == 'X') return 100;
    else if (a[0] == 'O' && a[4] == 'O' && a[8] == 'O') return 200;
    else return 300;
}
void main()
{
    int k;
    char ch;
labell:
    system("cls");
    gamename();
    show();
    inputsymbol();
    start();
    play();
label:
    system("cls");
    show();
    message();
    play();
    k=end();
    system("cls");
    show();
    if (count < 9)
    {
        if (k == 100)
        {
            printf(" :: Player 1 wins ::\n");
            count = 0;
        }
        else if (k == 200)
        {
            printf(" :: Player 1 wins ::\n");
            count = 0;
        }
        else
            goto label;
    }
    else
    {
        printf("\n -_- Game DRAW -_- \n");
        count = 0;
    }
    printf("\n Do You Want To Play Again : Enter Y to yes and N to no : \n");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        goto labell;
    }
    getch();
}