#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomnumber(int from , int to){
    int random = rand() % (to - from + 1) + from;
    return random;
}

void readarray(int arr[100] , int& arrlength){

    cout << "please enter length of array? " << endl;
    cin >> arrlength;


    for (int i = 0; i < arrlength; i++)
    {
        arr[i] = randomnumber(1 , 100);
    }
    
}

void print_array(int arr[100] ,int arrlength){

    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << "  ";
    }
    

}


int main(){

    int arr[100];
    int arrlength;
    readarray(arr , arrlength);
    cout << "array of one element : " << endl;
    print_array(arr , arrlength);

    int numberfound;
    cout << "number of you are looking for is? " << endl;
    cin >> numberfound;
    

    for (int i = 0; i < arrlength; i++)
    {
        if (arr[i] == numberfound)
        {
            cout << "the number found in position: " << i << endl;
            cout << "the number found in order is: " << i + 1 << endl;
        }
        
        
    }
    
}