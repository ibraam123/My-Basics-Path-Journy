#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


void PrintFileContenet(string FileName , vector <string>& vfilename)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in ); // Read Mode
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vfilename.push_back(Line);
        }


        MyFile.close();
    }


}