#include <iostream>
using namespace std;
void printtribleletter(){
    for (int i = 65; i < 91 ; i++)
    {
        for (int j = 65; j < 91 ; j++)
        {
            for (int k = 65; k < 91 ; k++)
            {
               cout << char(i);
               cout << char(j);
               cout << char(k);
               cout << endl;
            }
            
           
        }
        cout << endl;
        
    }
    
}
int main (){
    int number;
    printtribleletter();
}