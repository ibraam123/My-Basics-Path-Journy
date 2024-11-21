#include <iostream>

using namespace std;

void read_array(int x[3]) {
  // Prompt the user to enter three integers
  cout << "enter number: " << endl;
  cin >> x[0];

  cout << "enter number: " << endl;
  cin >> x[1];

  cout << "enter number: " << endl;
  cin >> x[2];
}

void print_array(int x[3]) {
  // Print the elements of the array
  cout << x[0] << endl;
  cout << x[1] << endl;
  cout << x[2] << endl;
}

int main() {
  int x[3];  // Declare an array of size 3 to store the integers

  read_array(x);  // Pass the array to the read_array function
  print_array(x);  // Pass the array to the print_array function

  return 0;
}

// H.W
/*#include <iostream>
#include <string>
using namespace std;

void read_grade(int grade[3]){


    cout << "enter grade one: " << endl;
    cin >> grade[0];


    cout << "enter grade two: " << endl;
    cin >> grade[1];


    cout << "enter grade three: " << endl;
    cin >> grade[2];


}

void calculate_average(int grade[3]){

    int result = (grade[0] + grade[1] + grade[2]) / 2;

    cout << "the average of grades is: " << result;


}

int main(){
    int grade[3];
    read_grade(grade);
    calculate_average(grade);
}

*/