#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout << "-----------|---------------------------------|----------|" << endl;
    cout << "      Code |                    name         |   mark   |" << endl;
    cout << "-----------|---------------------------------|----------|" << endl;

    cout << setw(11) <<"C101" << "|" << setw(33) <<"  introduction to programming" << "|" << setw(10) << "58" <<"|" << endl;
    cout << setw(11) <<"C102" << "|" << setw(33) <<"  computer hardware"  << "|" << setw(10) << "58" <<"|" << endl;
    cout << setw(11) <<"C1244602" << "|" << setw(33) <<"   network"  << "|" << setw(10) << "58" <<"|" << endl;
    cout << "-----------|---------------------------------|----------|" << endl;
    


    return 0;
}