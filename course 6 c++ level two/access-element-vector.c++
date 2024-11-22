#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    vector <int> vnumbers = {10 , 20 , 30};

    cout << "by using .at(i) ?" << endl;
    cout << "elemnet at index 0 : " << vnumbers.at(0) << endl;
    cout << "elemnet at index 1 : " << vnumbers.at(1) << endl;
    cout << "elemnet at index 2 : " << vnumbers.at(2) << endl;

    cout << "by using [i] ?" << endl;
    cout << "elemnet at index 0 : " << vnumbers[0] << endl;
    cout << "elemnet at index 1 : " << vnumbers[1] << endl;
    cout << "elemnet at index 2 : " << vnumbers[2] << endl;

    return 0;
}
/**out put 
 * 10
 * 20
 * 30
 * 10
 * 20
 * 30
 */