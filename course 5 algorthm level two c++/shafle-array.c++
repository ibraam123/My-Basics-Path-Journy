#include <iostream>
#include <cstdlib>
#include <ctime> // Include for better random seed

using namespace std;

void swap(int& a, int& b) {
    // Swaps the values of two integers using a temporary variable
    int temp = a;
    a = b;
    b = temp;
}

void read_array(int arr[100], int& arrlength) {
    // Reads the number of elements and initializes the array with consecutive numbers
    cout << "Enter number of elements: ";
    cin >> arrlength;

    for (int i = 0; i < arrlength; ++i) { // Array indices start from 0
        arr[i] = i + 1; // Initialize elements with values from 1 to arrlength
    }
}

int RandomNumber(int From, int To) {
    // Generates a random number between From and To (inclusive)
    return rand() % (To - From + 1) + From;
}

void shuffle_array(int arr[100], int arrlength) {
    // Shuffles the array elements using the swap function
    for (int i = 0; i < arrlength; ++i) {
        swap(arr[i], arr[RandomNumber(0, arrlength - 1)]); // Swap with a random element
    }
}

void print_array(int arr[100], int arrlength) {
    // Prints the array elements
    for (int i = 0; i < arrlength; ++i) { // Array indices start from 0
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int arr[100], arrlength;
    read_array(arr, arrlength);

    cout << "Array elements before shuffle:" << endl;
    print_array(arr, arrlength);

    shuffle_array(arr, arrlength);

    cout << "Array elements after shuffle:" << endl;
    print_array(arr, arrlength);

    return 0;
}
