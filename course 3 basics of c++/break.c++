#include<iostream>
using namespace std;

int main(){
    /**for(init ; condition ; update){
     * block of code 
     * if (condiotion){
     * break; (exit from loop)
     * 
     * }
     * code
    } */

   // H.W

   int arr[10] = {10,44,64,98,12,32,56,45,80,90};

   for (int i = 0; i < 11; i++)
   {
    if (arr[i] == 12){
        cout << i ;
        break;
    }
    cout << arr[i] << endl;
   }
   
}