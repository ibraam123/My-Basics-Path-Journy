#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        
        if (i == 2)
        {
            continue; // skip 2 and keep going
        }
        sum += i;
       
    }
    cout << sum << endl;
    
}
