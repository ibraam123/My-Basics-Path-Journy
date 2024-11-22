#include <iostream>
#include <vector>
using namespace std;


struct stfamily
{
    string brother;
    string sister;
    string father;
    string mother;
    float fsalary; 
    int agebrother;
    int agesister;
    int agefather;
    int agemother;
};

int main()
{
    vector <stfamily> vfamily;

    stfamily tempfamily;

    tempfamily.brother = "marcos";
    tempfamily.sister = "mariem";
    tempfamily.mother = "gezan";
    tempfamily.father = "magdy";
    tempfamily.fsalary = 15000.50;
    tempfamily.agebrother = 24;
    tempfamily.agesister = 10;
    tempfamily.agemother = 48;
    tempfamily.agefather = 55;

    vfamily.push_back(tempfamily);

    tempfamily.brother = "jaiden";
    tempfamily.sister = "toty";
    tempfamily.mother = "koky";
    tempfamily.father = "maichel";
    tempfamily.fsalary = 20000;
    tempfamily.agebrother = 6;
    tempfamily.agesister = 3;
    tempfamily.agemother = 35;
    tempfamily.agefather = 40;

    vfamily.push_back(tempfamily);


    for (stfamily &family : vfamily)
    {
        cout << "brother name: " << family.brother << endl;
        cout << "sister name: " << family.sister << endl;
        cout << "mother name: " << family.mother << endl;
        cout << "father name: " << family.father << endl;
        cout << "salary of family: " << family.fsalary << endl;
        cout << "age of brother: " << family.agebrother << endl;
        cout << "age of sister: " << family.agesister << endl;
        cout << "age of mother: " << family.agemother << endl;
        cout << "age of father: " << family.agefather << endl;

        cout << "\n\n";
    }

    return 0;
    

    

}