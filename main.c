
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void game(int, char *);
int random(int);
void checkWin(int, int, int *, int *);
int player(char *);
int computer();

void main()
{
    char playerName[51];
    int len, turn;

    printf("Enter your name:- ");
    len = strlen(gets(playerName));

    if (len > 50)
    {
        printf("Make sure length of name is under 50 words");
        exit(0);
    }
    printf("\nWelcome To Rock, Paper & Scissors\n");
    turn = random(2);
    game(turn, playerName);
}

void game(int turn, char *playerName)
{
    int r1 = 0, r2 = 0,i =0;

    printf("Instructions:- \n1.Rock\t2.Paper\t3.Scissors\npress the numbers in front of the options\n\n");

    if (turn == 1)
    {   
        while (i < 3)
        {

            int playerPoint, compPoint;
            printf("%s's turn:- \n", playerName);
            playerPoint = player(playerName);
            printf("computer's turn\n");
            compPoint = computer();
            printf("\nplayer choose:- %d, computer choose:- %d\n", playerPoint, compPoint);
            checkWin(playerPoint, compPoint, &r1, &r2);
            i++;
        }
    }
    else
    {
        while (i < 3)
        {

            int playerPoint, compPoint;
            printf("computer's turn\n");
            compPoint = computer();
            printf("%s's turn:- \n", playerName);
            playerPoint = player(playerName);
            printf("\nplayer choose:- %d, computer choose:- %d\n", playerPoint, compPoint);
            checkWin(playerPoint, compPoint, &r1, &r2);
            i++;
        }
    }

    if (r1 > r2)
    {
        printf("%s wins the game with %d points", playerName, r1 - r2);
    }
    else if (r2 > r1)
    {
        printf("computer wins the game with %d points\nThanks For Playing ", r2 - r1);
    }
    else
    {
        printf("Tie!");
    }
}

void checkWin(int p1, int p2, int *r1, int *r2)
{
    int playerPoint = 0, compPoint = 0;

    if (p1 == p2)
    {
        compPoint += 0;
    }
    // rock vs paper
    else if (p1 == 1 && p2 == 2)
    {
        compPoint += 1;
    }
    // paper vs rock
    else if (p1 == 2 && p2 == 1)
    {
        playerPoint += 1;
    }
    // rock vs scissors
    else if (p1 == 1 && p2 == 3)
    {
        playerPoint += 1;
    }
    // scissors vs rock
    else if (p1 == 3 && p2 == 1)
    {
        compPoint += 1;
    }
    // scissors vs paper
    else if (p1 == 3 && p2 == 2)
    {
        playerPoint += 1;
    }
    // paper vs scissors
    else if (p1 == 2 && p2 == 3)
    {
        playerPoint += 1;
    }

    *r1 += playerPoint;
    *r2 += compPoint;

    printf("\nplayer points:- %d, computer points:- %d\n", *r1, *r2);
    printf("------------------------------------------------\n\n");
}

int random(int turn)
{
    srand(time(NULL));
    return rand() % turn;
}

int player(char *playerName)
{
    int playerInput;
    scanf("%d", &playerInput);

    if(playerInput >3 || playerInput <1)
    {
        printf("Invalid input, try again:- ");
        playerInput = player(playerName);
    }
    return playerInput;
}

int computer()
{
    int compInput;
    return random(2) + 1;
}