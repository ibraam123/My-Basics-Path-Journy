#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


char randomoperator(){

    char operators[] = {'+', '-', '*', '/'};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    // Seed the random number generator
    srand(time(0));

    // Generate a random index
    int randomIndex = rand() % numOperators;

    // Choose the operator
    char op = operators[randomIndex];

    return op;

}



int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}
  

int no_questions(int& question){
    cout << "How many Questions do you want to answer ? " << endl ;
    cin >> question ;

    return question ;

}

void questions_level( int& level){
    
    cout << "Enter Questions Level [1] Easy , [2] Medium , [3] Hard , [4] Mix ? " << endl;
    cin >> level;
}

int random(int& num1 , int& num2 , int level) {

    num1 = 0 ;
    num2 = 0 ;

    switch (level)
    {
    case 1  :
        
        num1 = RandomNumber(1 , 10);
        num2 = RandomNumber(1 , 10);
        break; 
    case 2 : 
        num1 = RandomNumber(10 , 50);
        num2 = RandomNumber(10 , 50);
        break;
    case 3 : 
        num1 = RandomNumber(50 , 100);
        num2 = RandomNumber(50 , 100);
        break;
    case 4 : 
        num1 = RandomNumber(1 , 100);
        num2 = RandomNumber(1 , 100);
        break;
    }

    return 0;
}


void op(char& OP){
    int choose;
    cout << "Enter Operation  Tybe [1] Add , [2] Sub , [3] Mul , [4] Div , [5] Mix ? " << endl;
    cin >> choose;

    switch (choose)
    {
    case 1 :
         OP = '+';
        break;
    
    case 2 :
        OP = '-';
        break;
        
    case 3 :
        OP = '*';
        break;

    case 4 :
        OP = '/';
        break;

    case 5:
        cout << randomoperator();
        break;
    }


}

void loop_to_result(int &num1 , int& num2 ,int& question , int& level ){

    
    
    
    
    char yesorno = 'y';
    char OP ;
   
    
    


    while (yesorno == 'y')
    {
        int finalresult = 0;
        int trueresult;
        int right_counter = 0;
        int Wrong_counter = 0;
         no_questions(question);
         op(OP);
         questions_level(level);

        for (int i = 1; i <= question; i++)
    {
        random(num1 , num2 , level);
        cout << "Question [" << i << "/" << question << "]" << endl;
        cout << endl;
        cout << num1 << endl << num2 << OP; 
        cout << endl;
        cout << "_______" << endl;
        cin >> finalresult;
            
            
        

        switch (OP)
        {
        case '+':

            trueresult = num1 + num2;

            if (finalresult == trueresult)
            {
                cout << "Right answer" << endl;
                right_counter++;
            }
            else
            {
                cout << "Wrong answer" << endl;
                cout << "The rigth answer is : " << trueresult << endl;
                Wrong_counter++;
            }
            
            break;
        
        case '-' :

                    trueresult = num1 - num2;

            if (finalresult == trueresult)
            {
                cout << "Right answer" << endl;
                right_counter++;
            }
            else
            {
                cout << "Wrong answer" << endl;
                cout << "The rigth answer is : " << trueresult << endl;
                Wrong_counter++;
            }

            break;

        case '*':

                    trueresult = num1 * num2;

            if (finalresult == trueresult)
            {
                cout << "Right answer" << endl;
                right_counter++;
            }
            else
            {
                cout << "Wrong answer" << endl;
                cout << "The rigth answer is : " << trueresult << endl;
                Wrong_counter++;
            }

            break;

            case '/' :

                        trueresult = num1 / num2;

            if (finalresult == trueresult)
            {
                cout << "Right answer" << endl;
                right_counter++;
            }
            else
            {
                cout << "Wrong answer" << endl;
                cout << "The rigth answer is : " << trueresult << endl;
                Wrong_counter++;
            }

            break;

        }
            
            
        }

        if (right_counter > Wrong_counter)
        {
          cout << "_____________________________" << endl << endl;
          cout << "  Final Result is PASS : " << endl << endl;
          cout << "_____________________________" << endl << endl;
        }
        else
        {
          cout << "_____________________________" << endl << endl;
          cout << "  Final Result is FAIL : " << endl << endl;
          cout << "_____________________________" << endl << endl; 
        }
        

        

    cout << "Number of Questions: " << question << endl;
    cout << "Questions Level    : " << level << endl;
    cout << "OpType             : " << OP  << endl;
    cout << "Number of Right answers: " << right_counter << endl;
    cout << "Number of Wrong answers: " << Wrong_counter << endl;

    cout << "Do you want to play again? Y/N? " ;
    cin >> yesorno; 


    }

    }
    

    int main () {
        srand((unsigned)time(NULL));


        int num1;
        int num2;
        int level;
        int question;

        loop_to_result(num1 , num2 , question , level);

        return 0;
        


    }
    