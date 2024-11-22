#include <iostream>
#include <string>
using namespace std;

    char read_char(){
        char letter;
        cout << "\nplease enter a charcter? " << endl;
        cin >> letter;
        return letter;
    }
    char inverting_char(char letter){

        if (letter == toupper(letter))
        {
            return tolower(letter);
        }
        else
        {
            return toupper(letter);
        }
    }

int main(){
        char input = read_char();
        cout << "char after inverting case: " << endl;
        cout << inverting_char(input);
  
    system("pause>0");
}