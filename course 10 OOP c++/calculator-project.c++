#include <iostream>
using namespace std; 

class clscalculator {

private:
    int _number;


public: 

    void clear(){
        _number = 0;
        cout << "Result after clearing " << _number << " is: " ;
    }
    void Subtract(int number){
        cout << "Result after substracting " << number << " is: " ;
        _number -= number;
    }

    void Multibly(int number){
        cout << "Result after multiblying " << number << " is: " ;
        _number *= number;
    }

    void Add(int number){
        cout << "Result after adding " << number << " is: " ;
        _number += number;
    }

    void Divided(int number){
        cout << "Result after dividing " << number << " is: " ;
        _number /= number;
    }

    void Printresult(){
        cout << _number << endl;
    }

};

int main(){
    clscalculator calculator1;

    calculator1.clear();
    calculator1.Printresult();

    calculator1.Add(20);
    calculator1.Printresult();

    calculator1.Add(10);
    calculator1.Printresult();

    calculator1.Divided(2);
    calculator1.Printresult();

    calculator1.Subtract(5);
    calculator1.Printresult();

    
    calculator1.Multibly(10);
    calculator1.Printresult();


    return 0;


}