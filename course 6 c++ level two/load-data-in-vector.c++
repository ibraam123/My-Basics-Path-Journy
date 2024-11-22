#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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



int main()
{

    vector <string> vfilecontent;

    PrintFileContenet("MyFile.txt" , vfilecontent);


    for (string & line : vfilecontent)
    {
        cout << line << endl;
    }

    return 0;
    
}

