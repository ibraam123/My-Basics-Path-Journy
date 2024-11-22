#include <iostream>
using namespace std;

void printheaderline(){
    cout << "multiblaction table from 1 to 10" << endl;
    cout << "     1       2       3       4       5       6       7       8       9       10" << endl;
}
void loops(){
    cout << "________________________________________________________________________________" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "  |" ;
        for (int j = 1; j <= 10; j++)
        {
            cout  <<" " << i * j  << "  "<< "\t";
        }
        cout << endl;
    }
    
}

int main (){
    printheaderline();
    loops();
}