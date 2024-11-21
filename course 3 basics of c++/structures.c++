#include <iostream>
using namespace std;

struct nameofownercar {
string name;
};
struct Car
{
    string brand;
    string model;
    int year;
    nameofownercar car1;
};
int main(){

    Car mycar1;

    mycar1.brand = "BMW";
    mycar1.model = "X5";
    mycar1.year = 2000;
    mycar1.car1.name = "ibraam";

    cout << mycar1.brand << " " << mycar1.model << " " << mycar1.year << " " << mycar1.car1.name;
;

}