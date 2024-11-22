/**Requirements:
 *  Ask for how many rounds the game will be  .
 *  start each round Player vs Computer  .
 *  Show the result with each round  .
 *  If computer wins the round ring a bill , and screeb red .
 *  If player won the round show green screen  .
 *  After all rounds show game over the print game results , then ask the user if she\he want to play again .
 * 
 */

/**enum enScreenColor { Red=1, Blue=2, Green=3, Yellow=4 };

int main()
{
    cout << "****************************\n";
    cout << "Please Chose the number of your color?\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "****************************\n\n";
    cout << "Your Choice? ";
    
    int c;
    enScreenColor Color;

    cin >> c;
    Color = (enScreenColor) c;

    if (Color == enScreenColor::Red)
    {
        system("color 4F");

    }
    else if (Color == enScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (Color == enScreenColor::Green)
    {
        system("color 2F");
    }
    else if (Color == enScreenColor::Yellow)
    {
        system("color 6F");
    }
    
    else
        
    {
        system("color 4F");
    };

    return 0;
} */

/**
 *   int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}
  srand((unsigned)time(NULL));*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum enScreenColor { Red=1, Blue=2, Green=3, Yellow=4 };
    int c;
    enScreenColor Color;

 int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}


int rounds(int& round){
    cout <<"How many rounds 1 to 10? " << endl;
    cin >> round;
    return round;
}


void start(int round){


    int choise;
    int computerchoise;

    char playagain = 'y';
    round = rounds(round);

    while(playagain == 'y'){
    int draw = 0;
    int player = 0;
    int computer = 0;



    for (int i = 1; i <= round; i++)
    {
        computerchoise = RandomNumber(1,3);
        cout << "round["<< i << "] begins" << endl;
        cout << "Your choise: [1] stone, [2] paper , [3] scissors ? " << endl;
        cin >> choise;

        if (choise == 1 && computerchoise == 3)
        {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[player]" << endl;
        cout << "_________________________________________" << endl;
        player ++;
         // system("color 2F");


        }

        else if ( computerchoise == 1 && choise == 3)
        {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[computer]" << endl;
        cout << "_________________________________________" << endl;

        computer ++;
              //  system("color 4F");

        }
        
        
      else if (choise == computerchoise){

        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player1 choice  : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[Draw]" << endl;
        cout << "_________________________________________" << endl;

       // system("color 6F");
        draw++;


      }
      else if ( choise > computerchoise && choise != 1)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[player]" << endl;
        cout << "_________________________________________" << endl;
        player ++;

         //system("color 2F");

      }
      else if ( computerchoise > choise && computerchoise != 1)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[computer]" << endl;
        cout << "_________________________________________" << endl;

        computer ++;

        //system("color 4F");
        cout << "\b";



      }
      else if (choise == 1 && computerchoise == 3)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[player]" << endl;
        cout << "_________________________________________" << endl;
        player ++;
        //system("color 2F");

      }
      else if (  computerchoise == 1 && choise == 3)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[computer]" << endl;
        cout << "_________________________________________" << endl;

        computer ++;
            //    system("color 4F");



      }
      else if (choise == 1 && computerchoise != 3)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[player]" << endl;
        cout << "_________________________________________" << endl;
        computer ++;
       // system("color 2F");


      }
      else if (  computerchoise == 1 && choise != 3)
      {
        cout << "___________round["<< i << "] ___________" << endl;
        cout << "Player choice   : " << choise << endl;
        cout << "computer choise : " << computerchoise << endl;
        cout << "Round Winner    : " << "[Player]" << endl;
        cout << "_________________________________________" << endl;
        player ++;
       // system("color 2F");


      }

      
      
      
    
    }

    cout << "______________________________________________________" << endl;
    cout << "                 *** G A M E  O V E R ***             " << endl;
    cout << "______________________________________________________" << endl;
    cout << "______________________{Game Result}___________________" << endl;
    cout << "game rounds       :  " << round << endl;
    cout << "player won times  :  " << player << endl;
    cout << "computer won times:  " << computer << endl;
    cout << "Draw times        :  " << draw << endl;
    if (player > computer)
    {
    cout << "Final Winner      :  player" << endl;
    }
    else
    {
    cout << "Final Winner      :  computer" << endl;
    }
    
    

    cout << "______________________________________________________" << endl;


    cout << "Do you want play again? Y/N? " << endl;
    cin >> playagain;


    
}
}
int main (){
    srand((unsigned)time(NULL));
    int round;
    start(round);
    return 0;
}


// chat gbt solution
/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum ScreenColor { Red = 1, Blue, Green, Yellow };

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Function to set the screen color based on choice
void SetScreenColor(ScreenColor color) {
    switch (color) {
        case Red:    system("color 4F"); break;
        case Blue:   system("color 1F"); break;
        case Green:  system("color 2F"); break;
        case Yellow: system("color 6F"); break;
        default:     system("color 4F"); break;
    }
}

// Function to handle the game logic
void PlayGame() {
    int rounds, playerWins = 0, computerWins = 0, draws = 0;
    char playAgain = 'y';

    while (playAgain == 'y') {
        cout << "How many rounds (1 to 10)? ";
        cin >> rounds;

        for (int i = 1; i <= rounds; ++i) {
            int playerChoice, computerChoice = RandomNumber(1, 3);

            cout << "Round [" << i << "] - Your choice: [1] stone, [2] paper, [3] scissors? ";
            cin >> playerChoice;

            cout << "Round [" << i << "] - Player choice: " << playerChoice
                 << ", Computer choice: " << computerChoice << endl;

            if (playerChoice == computerChoice) {
                cout << "Draw!" << endl;
                ++draws;
                SetScreenColor(Green);
            } else if ((playerChoice == 1 && computerChoice == 3) ||
                       (playerChoice == 2 && computerChoice == 1) ||
                       (playerChoice == 3 && computerChoice == 2)) {
                cout << "Player wins!" << endl;
                ++playerWins;
                SetScreenColor(Green);
            } else {
                cout << "Computer wins!" << endl;
                ++computerWins;
                SetScreenColor(Red);
            }

            cout << "--------------------------------" << endl;
        }

        cout << "Game Over!" << endl;
        cout << "Rounds played: " << rounds << endl;
        cout << "Player wins: " << playerWins << endl;
        cout << "Computer wins: " << computerWins << endl;
        cout << "Draws: " << draws << endl;
        cout << "Final Winner: " << (playerWins > computerWins ? "Player" : "Computer") << endl;

        cout << "Play again? (y/n) ";
        cin >> playAgain;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    PlayGame();
    return 0;
}*/
