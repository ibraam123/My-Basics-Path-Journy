#include <iostream>
#include <vector>

using namespace std;

/*int main(){

    vector <int> Vnumbers ;

    Vnumbers.push_back(10);
    Vnumbers.push_back(20);
    Vnumbers.push_back(30);
    Vnumbers.push_back(40);
    Vnumbers.push_back(50);
    Vnumbers.push_back(60);
    

    cout << "numbers of vector = " ;

    for (int &numbers : Vnumbers)
    {
        cout << numbers << "::" ;
    }
    
}*/

// homework

void readnumbers(vector <int> &vnumbers)
{
    bool check = true;
    int number = 0;
    while (check == true)
    {
        cout << "enter numbers you want add to vector? " << endl;
        cin >> number;


        vnumbers.push_back(number);


        cout << "want add another element [1]yes , [0]no ? " << endl;
        cin >> check;
    }
    
}

void printnumbers(vector <int> &vnumbers)
{
    for (int &numbers : vnumbers)
    {
        cout << numbers << " " ;  
    }
    
}

int main()
{
    vector <int> vnumbers;

    readnumbers(vnumbers);
    printnumbers(vnumbers);
    
}
/**input
 * 10
 * 20
 * 30
 * 40
 * store in vector
 * {10,20,30,40} by push back
 * then 
 * using for range loop 
 * to store vectore in numbers
 * after that out put 
 * is 10 , 20 , 30 , 40
 */