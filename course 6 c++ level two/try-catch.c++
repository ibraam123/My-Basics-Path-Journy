#include <iostream> 
#include <vector>
using namespace std;


int main()
{


    vector <int> vnumbers = {1,2,3,4,5};

    int num = 6;

    try // trying first if not runing then to catch
    {
        cout << vnumbers.at(num);
    }
    catch(...)
    {
        cout << num << " not allowed" << endl;
    }
    

    return 0;
}