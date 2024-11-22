#include<iostream>
using namespace std;

int readhours(int &hours){
    cout << "please enter number of hours? " << endl;
    cin >> hours;
    return hours;
}
void calculatedaysandweeks(int hours){
    float days , weeks;
    days = hours / 24;
    weeks = days / 7;
    cout << "number of days = " << days << endl << "nummber of weeks = " << weeks << endl;
}
int main(){
    int hours;
    calculatedaysandweeks(readhours(hours));
}