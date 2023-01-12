#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void game(int, char *);
int random(int);
void checkWin(char *, int, int, int *, int *);
int player(char *);
int computer();

// intro / menu
void main()
{
    char playerName[51];
    int len, turn,i=1;

    while (i != 0)
    {
        printf("Enter your name:- ");
        len = strlen(gets(playerName));

        if (len > 50)
        {
            printf("Make sure, the length of your name is under 50 words\n");
        }
        else
        {
            i = 0;
        }
    }
    printf("\nWelcome To Rock, Paper & Scissors\n");
    turn = random(2);
    game(turn, playerName);
}

// the game arena
void game(int turn, char *playerName)
{
    int r1 = 0, r2 = 0, i = 0;

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
            printf("\n%s choose:- %d, computer choose:- %d\n", playerName, playerPoint, compPoint);
            checkWin(playerName, playerPoint, compPoint, &r1, &r2);
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
            printf("\n%s choose:- %d, computer choose:- %d\n", playerName, playerPoint, compPoint);
            checkWin(playerName, playerPoint, compPoint, &r1, &r2);
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

// comparing both turns
void checkWin(char *playerName, int p1, int p2, int *r1, int *r2)
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
        compPoint += 1;
    }

    *r1 += playerPoint;
    *r2 += compPoint;

    printf("\n%s's point:- %d, computer's point:- %d\n", playerName, *r1, *r2);
    printf("------------------------------------------------\n\n");
}

// taking player's input
int player(char *playerName)
{
    int playerInput;
    scanf("%d", &playerInput);

    if (playerInput > 3 || playerInput < 1)
    {
        printf("Invalid input, try again:- ");
        fflush(stdin); // clearing the input buffer
        playerInput = player(playerName);
    }
    return playerInput;
}

// generating computer's input
int computer()
{
    int compInput;
    return random(3) + 1;
}

// generating random numbers
int random(int turn)
{
    srand(time(NULL));
    return rand() % turn;
}
