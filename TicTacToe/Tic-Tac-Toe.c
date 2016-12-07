#include <stdio.h>

void displayBoard ();
void input ();
void win ();

int player1 = 0, playerSelector = 1; //Player1 decides who wins
char TicTacToe [3][3],character; //TicTacToe boardgame

int main(){

  int x,y,num = 49; //Ascii character for 1
  //Initialize the matrix from 1 to 9
  for(x = 0 ; x < 3 ; x++)
    for(y = 0 ; y < 3 ; y++){
      TicTacToe [x][y] = num;
      num++;
    }
  system ("clear"); //Start with a clean screen
  displayBoard();
  do{
    input();
    displayBoard();
  }while(player1 == 0); // The game ends when player1 gets the value of 1 (See the win function)
  //Displays the winner
  if(player1 == 1 && character == 88)
    printf("Player 1 WINS\n");
  if(player1 == 1 && character == 79) //Actually the character decides who won
    printf("Player 2 WINS\n");

  return 0;
}

void displayBoard (){
    //Displays a nice and clean TicTacToe boardgame

    printf("            Tic Tac Toe\n\n");
    printf("            |          |\n            |          |\n       %c    |     %c    |     %c\n            |          |\n            |          |\n",TicTacToe[0][0], TicTacToe[0][1], TicTacToe[0][2]);
    printf("  --------------------------------\n");
    printf("            |          |\n            |          |\n       %c    |     %c    |     %c\n            |          |\n            |          |\n",TicTacToe[1][0], TicTacToe[1][1], TicTacToe[1][2]);
    printf("  --------------------------------\n");
    printf("            |          |\n            |          |\n       %c    |     %c    |     %c\n            |          |\n            |          |\n",TicTacToe[2][0], TicTacToe[2][1], TicTacToe[2][2]);

}

void input (){
  int iBox;
  //Decides the player's turn
  if(playerSelector % 2 == 1){
    character = 88; //Ascii character X
    printf("Player 1\n\n");
  }
  else{
    character = 79; //Ascii character 0
    printf("Player 2\n\n");
  }
  playerSelector++;


  do{
    printf("Enter a number 1-9: ");
    scanf("%d", &iBox); //Scans the number of the box wich the player wants pick
  }while(iBox > 9 || iBox < 1); //Keep the player turn until a valid input is readed
  //Translate the human pick to a two dimension array location
  switch (iBox) {
    case 1:
      if(TicTacToe[0][0] == 49) //Checks if the box its occupied by the other player
        TicTacToe[0][0] = character;
      else playerSelector--; //If it is player selector is goig to be initialized by the current player value
    break;
    case 2:
      if(TicTacToe[0][1] == 50)
        TicTacToe[0][1] = character;
      else playerSelector--;
    break;
    case 3:
      if(TicTacToe[0][2] == 51)
        TicTacToe[0][2] = character;
      else playerSelector--;
    break;
    case 4:
      if(TicTacToe[1][0] == 52)
        TicTacToe[1][0] = character;
      else playerSelector--;
    break;
    case 5:
      if(TicTacToe[1][1] == 53)
        TicTacToe[1][1] = character;
      else playerSelector--;
    break;
    case 6:
      if(TicTacToe[1][2] == 54)
        TicTacToe[1][2] = character;
      else playerSelector--;
    break;
    case 7:
      if(TicTacToe[2][0] == 55)
        TicTacToe[2][0] = character;
      else playerSelector--;
    break;
    case 8:
      if(TicTacToe[2][1] == 56)
        TicTacToe[2][1] = character;
      else playerSelector--;
    break;
    case 9:
      if(TicTacToe[2][2] == 57)
        TicTacToe[2][2] = character;
      else playerSelector--;
    break;
  }


  win();
  system("clear");
}

void win (){
  if(TicTacToe [0][0] == TicTacToe [0][1] && TicTacToe [0][0] == TicTacToe [0][2])       //
    player1++;                                                                           //
  if(TicTacToe [1][0] == TicTacToe [1][1] && TicTacToe [1][0] == TicTacToe [1][2])       //
    player1++;                                                                           //
  if(TicTacToe [2][0] == TicTacToe [2][1] && TicTacToe [2][0] == TicTacToe [2][2])       // Horizontal Winning
    player1++;


  if(TicTacToe [0][0] == TicTacToe [1][0] && TicTacToe [0][0] == TicTacToe [2][0])       //
    player1++;                                                                           //
  if(TicTacToe [0][1] == TicTacToe [1][1] && TicTacToe [0][1] == TicTacToe [2][1])       //
    player1++;                                                                           //
  if(TicTacToe [0][2] == TicTacToe [1][2] && TicTacToe [0][2] == TicTacToe [2][2])       //
    player1++;                                                                           // Vertical Winning


  if(TicTacToe [0][0] == TicTacToe [1][1] && TicTacToe [0][0] == TicTacToe [2][2])       //
    player1++;                                                                           //
  if(TicTacToe [2][0] == TicTacToe [1][1] && TicTacToe [2][0] == TicTacToe [0][2])       //
    player1++;                                                                           // Diagonal Winning

}
