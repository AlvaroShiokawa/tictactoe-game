#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class TicTacToe
{
private:
   char gamearea[3][3];
   bool player, end_of_game;
   int free_spaces, wongame,player_made_a_correct_move;
   void Change_Player(); //Método
public:
   TicTacToe(); //Construtor
   ~TicTacToe(); //Destrutor
   void Menu(); //Método
   void Add_X(); //Método
   void Add_O(int i, int j); //Método
   void Game_Status(); //Método
   void Display(); //Método

};
//CONSTRUTOR
TicTacToe::TicTacToe()
{
   wongame = 0;
   free_spaces = 9;
   player_made_a_correct_move=0;
   int i,j;
   for (i=0;i<3;i++)
      for (j=0;j<3;j++)
         gamearea [i][j] = ' '; // Inicializar o gamearea;
   
   player = true; // Jogador começa
   end_of_game = false; // Não acabou o jogo ainda
}
//
//
//DESTRUTOR
TicTacToe::~TicTacToe()
{
   cout << "Killing TIC TAC TOE object...\n";
   system ("PAUSE");
   cout << endl;
}
//
//
//MÉTODO "Change_Player"
void TicTacToe::Change_Player()
{
   if (player_made_a_correct_move==1)
   {
      player = !player;
      player_made_a_correct_move = 0;
   }        
}
//
//
//MÉTODO "Menu"
void TicTacToe::Menu()
{
   char menu;
   menu = 'A';

   string menuR;
  // while ((menu != '0') && (wongame==0))// change somethign here
   do
   {
      system ("cls");
      Display();
      if ((player) && (end_of_game==false) )
      {  
         cin>> menuR;                            
		 menu = menuR[0];

	
		
		 if (menuR[1] != NULL)
		 menu = 99;

         switch (menu)
         {
            case '7':
               Add_O(0,0);
               break;
            case '8':
               Add_O(0,1);
               break;
            case '9':
               Add_O(0,2);
               break;
            case '4':
               Add_O(1,0);
               break;
            case '5':
               Add_O(1,1);
               break;
            case '6':
               Add_O(1,2);
               break;
            case '1':
               Add_O(2,0);
               break;
            case '2':
               Add_O(2,1);
               break;
            case '3':
               Add_O(2,2);
               break;
            case '0':
               break;
            default:
               menu = '0';
               end_of_game=true;
               break;   
         }
      }
      else
      {
         system ("cls");
         Display();
         Add_X();
         system ("cls");
         Display();
         cout << endl;
         system ("PAUSE");
         cout << endl;
      }
      Change_Player();
      Game_Status(); 
	  
	  ////////////// the exit the loop

	  //if (wongame != 0 )
	//	  break; /// or menu = '0';



   } 
   
   while ((menu != '0') && (wongame==0));


       system ("cls");
      Display();
}
//
//
//MÉTODO "Add_X"
void TicTacToe::Add_X()
{
   int subcycle=9999,i=0,j=0;
   if (end_of_game==false)
      if (player == false)
      {
       i = 0;
       j = 0;
       i = rand() % 3;
       j = rand() % 3;
       system ("PAUSE");
       cout<<endl;
       while (subcycle != 0)
       {
          if (gamearea[i][j] == ' ')
          {
             gamearea[i][j] = 'X';
             player_made_a_correct_move = 1;
             free_spaces--;
             subcycle = 0;
          }
          i = rand() % 3;
          j = rand() % 3;    
       }
      }
}
//
//
//MÉTODO "Add_O"
void TicTacToe::Add_O(int i, int j)
{
   if (player == true)
   {  
      if (end_of_game == false)
         if (gamearea[i][j] == ' ')
         {
            gamearea[i][j] = 'O';
            player_made_a_correct_move = 1;
            free_spaces--;
         } 
   }
}
//
//
//MÉTODO "Game Status"
void TicTacToe::Game_Status()
{
   if (end_of_game==false)
   {
   //CHANCES DO PLAYER VENCER (FOI FEITO NA FORÇA BRUTA... -____- SEI QUE PODE SER RESUMIDO ESTE CÓDIGO...
   /*[O][O][O]
     [ ][ ][ ]
     [ ][ ][ ]*/
      if (((gamearea[0][0] == 'O') && (gamearea[0][1] == 'O'))&&(gamearea[0][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[ ][ ][ ]
     [O][O][O]
     [ ][ ][ ]*/
      if (((gamearea[1][0] == 'O') && (gamearea[1][1] == 'O'))&&(gamearea[1][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[ ][ ][ ]
     [ ][ ][ ]
     [O][O][O]*/
      if (((gamearea[2][0] == 'O') && (gamearea[2][1] == 'O'))&&(gamearea[2][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[O][ ][ ]
     [O][ ][ ]
     [O][ ][ ]*/
      if (((gamearea[0][0] == 'O') && (gamearea[1][0] == 'O'))&&(gamearea[2][0] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[ ][O][ ]
     [ ][O][ ]
     [ ][O][ ]*/
      if (((gamearea[0][1] == 'O') && (gamearea[1][1] == 'O'))&&(gamearea[2][1] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[ ][ ][O]
     [ ][ ][O]
     [ ][ ][O]*/
      if (((gamearea[0][2] == 'O') && (gamearea[1][2] == 'O'))&&(gamearea[2][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[O][ ][ ]
     [ ][O][ ]
     [ ][ ][O]*/
      if (((gamearea[0][0] == 'O') && (gamearea[1][1] == 'O'))&&(gamearea[2][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   /*[ ][ ][O]
     [ ][O][ ]
     [O][ ][ ]*/
      if (((gamearea[2][0] == 'O') && (gamearea[1][1] == 'O'))&&(gamearea[0][2] == 'O'))
      {
               end_of_game = true;
               wongame = 1;
      }
   //CHANCES DO CPU VENCER (FOI FEITO NA FORÇA BRUTA... -____- SEI QUE PODE SER RESUMIDO ESTE CÓDIGO...
   /*[X][X][X]
     [ ][ ][ ]
     [ ][ ][ ]*/
      if (((gamearea[0][0] == 'X') && (gamearea[0][1] == 'X'))&&(gamearea[0][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[ ][ ][ ]
     [X][X][X]
     [ ][ ][ ]*/
      if (((gamearea[1][0] == 'X') && (gamearea[1][1] == 'X'))&&(gamearea[1][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[ ][ ][ ]
     [ ][ ][ ]
     [X][X][X]*/
      if (((gamearea[2][0] == 'X') && (gamearea[2][1] == 'X'))&&(gamearea[2][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[X][ ][ ]
     [X][ ][ ]
     [X][ ][ ]*/
      if (((gamearea[0][0] == 'X') && (gamearea[1][0] == 'X'))&&(gamearea[2][0] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[ ][X][ ]
     [ ][X][ ]
     [ ][X][ ]*/
      if (((gamearea[0][1] == 'X') && (gamearea[1][1] == 'X'))&&(gamearea[2][1] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[ ][ ][X]
     [ ][ ][X]
     [ ][ ][X]*/
      if (((gamearea[0][2] == 'X') && (gamearea[1][2] == 'X'))&&(gamearea[2][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[X][ ][ ]
     [ ][X][ ]
     [ ][ ][X]*/
      if (((gamearea[0][0] == 'X') && (gamearea[1][1] == 'X'))&&(gamearea[2][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
   /*[ ][ ][X]
     [ ][X][ ]
     [X][ ][ ]*/
      if (((gamearea[2][0] == 'X') && (gamearea[1][1] == 'X'))&&(gamearea[0][2] == 'X'))
      {
               end_of_game = true;
               wongame = 2;
      }
      if ((end_of_game==false)&&(free_spaces <= 0))
      {
         end_of_game = true;
         wongame = 3;                                          
      }
   }
}
//
//
//MÉTODO "Display"
void TicTacToe::Display()
{
   cout << "MADE BY: ALVARO SHIOKAWA ALVAREZ\n\nTIC TAC TOE... CHOOSE YOUR DESTINY...\n\nNumber of free spaces on game area: "<<free_spaces<<endl<<endl;
   if (end_of_game == false)
   {
      if (player)
         cout << "Player Turn.\n";
      else
         cout << "CPU Turn.\n";
   }
   else
      cout << "No one is playing.\n"; 
   for (int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
         cout << "["<<gamearea[i][j]<<"] ";
      cout << endl;   
   }
   if (end_of_game==true)
      if (wongame == 1)
         cout << "\nYOU WIN!\n\nGAME OVER!\n";
      if (wongame == 2)
         cout << "\nYOU LOSE!\n\nGAME OVER!\n";
      if (wongame == 3)
         cout << "\nDRAW!\n\nGAME OVER!\n";
   else
      if (player)
         cout << "\n->Choose one of the corresponding menu options to fill\nthe game area, type it, then press ENTER.\n\n->To exit type anything else and press ENTER.\n\nMenu Options:\n[7] [8] [9]\n[4] [5] [6]\n[1] [2] [3]\n";        
}
//
//
int main()
{
    TicTacToe Game;
    Game.Menu();
    cout<<endl;
    return 0;
}
