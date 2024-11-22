#include <iostream>
#include <vector>

using namespace std;

int main(){
    /**syntax
     *      std::vector<data type> vector_name = { content of vector }
     */

    vector <int> Vnumbers = {10 , 20 , 30 , 40 , 50};

    cout << "numbers of vector = " ;

    for (int &numbers : Vnumbers)
    {
        cout << numbers << "::" ;
    }
    
}