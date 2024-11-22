#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int randomnumber(int from , int to){
    int RN = rand() % (to - from + 1) + from;
    return RN;
}

int number_of_trails(){
    int number;
    cout << "enter number of trails? " << endl;
    cin >> number;
    return number;
}
void generate(){
    // 65 to 90
    int trails = number_of_trails();
    for(int j = 0 ; j < trails ; j ++){
        cout << "Key[" << j << "]: " ; 

    for(int x = 0 ; x < 4 ; x ++){

    for (int i = 0; i < 4; i++)
    {
        cout << char (randomnumber(65, 90));
    }
    if (x == 3)
    {
        break;
    }
    
    cout << "-";

    
    }
        cout << endl;
    }
    

}

int main(){
    generate();
}
