#include <iostream> 
#include <fstream> // library to files
using namespace std;

int main()
{
    fstream myfile;

    myfile.open("myfile.txt" , ios::out | ios::app); //  write mode

    if (myfile.is_open()) // chaeck if is open or no
    {
        for (int i = 0; i < 50; i++)
        {
            myfile << i <<" - " << "line." << endl;
        }


        myfile.close();
        
    }
    

    return 0;
}