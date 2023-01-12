# Rock-Paper-Scissors-in-C
Simple and beginner friendly game created in C.

# Description
Rock-Paper-Scissors is player vs computer game. The total no. of rounds is 3, and the one with max points will win the game.

# How this program works?
For understanding the working mechanism of this program, make sure you are familiar with the functions in C.

### The main() function
* ```C
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
  ```
  
* Above is the code of the **main()** function. The main function is taking input of user's name and then, verifying that the name must be in under 50 words.
And also looping it, until player enters a valid name.
  ```C 
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
  ```
  After that, showing the welcome message and then sending the flow of the program to the **game()** function.
  ```C
  game(turn, playerName); 
    ```

* Before talking about the **game()** function, let's talk about the rest of the functions first, 
  ```C
  void game(int, char *);
  int random(int);
  void checkWin(char *, int, int, int *, int *);
  int player(char *);
  int computer();
  ```
  because they are connected with the game() function.
  
### The random() function
* ```C
  int random(int turn)
  {
      srand(time(NULL));
      return rand() % turn;
  }
  ```
 * As the name saying, the main purpose of this function is to generate the random numbers ranges from 0 to ***turn-1***.
   The line ``` rand() % turn ``` will generate random numbers ranging from 0 to turn-1, but the **rand()** generates random number on the 
   basis of the **seed** given by the **srand()** function. 
   If the seed given to the rand function is same, then the rand() function will generate same value each time.
   And here comes the srand() function ``` srand(time(NULL)) ```. The argument ``` time(NULL) ``` will return ***seconds*** and each new second, there
   is a new seed, and a new random value also.
   
### The checkwin() function

* ```C
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

  ```
  
 * The main work of this function is to compare the player and computer's turn and giving them points according to the result.
   And using **pointers**, updating the points data in the variables, which are created inside the **game()** function.<br>
   And at last printing the result of each round.
   
### The player() and computer() function
* ``` C
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
  ```
* The main purpose of the **player()** and the **computer()** function is to take inputs from player and computer.<br><br>
  Inside the **player()** function, taking the input from user and storing it in **playerInput** variable. And also checking, whether the input is other than 
  the 1, 2 and 3. If it is, then showing the error and clearing the input buffer using ```fflush(stdin)``` and looping the function until the player enters the 
  correct input.<br><br>
  Inside the **computer()** function, calling the **random()** function to generate random values from 0 to 3, but as the **rand()** will only generate 
  value from 0 to 3-1, and at the same time we don't want 0 in the input so adding 1 to the random number which is from (0 to 2) + 1 and will generate the 
  desired computer input.
  
### The game() function

* ```C
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
  ```
* Now the most awaited function, **the game() function**.<br>
  First of all printing the game instructions to the user using ``` printf() ```. After that there is an if-else statement, with condition ***turn == 1***.
  ```C
  printf("\nWelcome To Rock, Paper & Scissors\n");
  turn = random(2);
  game(turn, playerName);
  ```
  Inside the **main()** function and below the welcome line, the turn variable getting a random number from 0 to 1 and sending this as an argument to the
  **game()** function.
  The **turn** will decide, who will play first.<br><br>
  
  If **turn == 1** then player will play first else computer will play first.<br><br>
  
  And inside the if and else block, first calling the player or computer's input function, then taking input from them and then printing their 
  choices. After that calling the **checkwin()** function and looping these statements 3 times.<br><br>
  ```C
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
  ```
  Now below there is one more if-else ladder,
  ```C
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
  ```
  which will compare the points of the 3 rounds and then will print the result of the game on the screen.
  
  So this is the working mechanism of this program, if you have any kind of queries feel free to ask me.