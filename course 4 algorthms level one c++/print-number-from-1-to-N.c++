#include <iostream>

using namespace std;

int readnumber(int& number){
    cout << "inter number you want repeated from 1 to number? " << endl;
    cin >> number;
    return number;
}
void printnumberfrom1toN(int number){

    for (int i = 1; number >= i; i++)
    {
        cout << i << endl;
    }
    
}

int main(){
    int number;
    printnumberfrom1toN(readnumber(number));

}