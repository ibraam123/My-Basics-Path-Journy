#include <iostream>
#include <ctime>
using namespace std;


int main(){
    int num = 10;
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++)
    {
        (nums[i] == num)? cout << "true" << endl : cout << "false" << endl;  
    }
    
}