#include <iostream>
#include <string>

using namespace std;


int number_of_trails(){
    int number;
    cout << "enter number of trails? " << endl;
    cin >> number;
    return number;
}

void numbers(){
    int number = number_of_trails();
    int ennumber[number];
    int remainder = 0;
    int times = 0;
    
    for (int i = 1; i <= number; i++)
    {
        cout << "element[" << i << "]: ";
        cin >> ennumber[i];

    }
    int numberoffreq;
    cout << "enter number of you want check? " ;
    cin >> numberoffreq;
     cout << "Original array: " ;


    for (int j = 1; j <= number; j++)
    {
       cout << ennumber[j];
    }
    cout << endl;
    for (int i = 0; i <= number; i++)
    {
        remainder = ennumber[i] % 10 ;
        ennumber[i] = ennumber[i] / 10 ;

            if( numberoffreq == remainder )
           {
              times ++ ;
           }
    }
    cout << numberoffreq << " is repeated " << times << " time(s)"<<endl; 
    
    
   
    

}

int main(){
    numbers();
}
