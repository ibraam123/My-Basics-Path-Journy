#include <iostream>
using namespace std;

int readnumber(int &number){
    cout << "enter number? " << endl;
    cin >> number;
    return number;
}

void printnumbers(int number){
    int sum = 0;
    int i = 0;
    /*for (int i = 0;  ; i++)
    {
        if(i%2 != 0){
        sum += i;
        }
    }*/
   while (i <= number)
   {
       if(i%2 != 0){
       sum += i;
        }
    i++;
   }
   
    cout << sum;
    

}

int main(){
    int number;
    printnumbers(readnumber(number));
}