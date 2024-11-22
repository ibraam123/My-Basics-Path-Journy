#include <iostream>
#include <string>
using namespace std;

string readrightpassord(string password){
    cout << "enter right password? " << endl;
    cin  >> password ;
    return password;
}
void checkpassword(string password){
    string checknumber;
    int trails = 1;
    do
    {
        cout << "Trial " << "[" << trails << "]" << endl;
        cin >> checknumber;
        trails++;
    } while (checknumber != password);
    cout <<"password is " << password << " founda after " << trails - 1 << " trials " << endl;
    

}
int main (){
    string password;
    checkpassword(readrightpassord(password));
}