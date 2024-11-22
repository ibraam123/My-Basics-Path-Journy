#include <iostream>
using namespace std;

void readmarks(int& mark1 , int& mark2 , int &mark3){


cout << "enter your mark one?  " << endl;
cin >> mark1;

cout << "enter your mark two?  " << endl;
cin >> mark2;

cout << "enter your mark three?  " << endl;
cin >> mark3;

}
double calculate_average(int mark1 , int mark2 , int mark3){
    return (mark1 + mark2 + mark3) / 3;
}

void check_average(int mark1 , int mark2 , int mark3){

    if (calculate_average( mark1 ,  mark2 ,  mark3) >= 50)
    {
        cout << "you passed";
    }
    else
    {
        cout << "you failed";
    }
    
}

int main(){
    int mark1 ,mark2 ,  mark3;

    readmarks( mark1 ,  mark2 , mark3);
    check_average(mark1 ,  mark2 , mark3);

}