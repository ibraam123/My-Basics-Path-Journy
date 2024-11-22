#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "please enter numbers of students? " << endl;
    cin >> num;

    float *ptr;

    ptr = new float[num];

    cout << "student grades " << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "student" << i + 1 <<":" ;
        cin >> *(ptr + i);
        
    }

    cout << "displaying grades of students " << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "student" << i + 1 << ":"  << *(ptr + i) ;
        cout << endl;
    }


    delete[] ptr;

    return 0;
       
}