#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    vector<int> arr1;
    vector<int> arr2;
    vector<int> temp;

    // Find divisors of num1 and store in arr1
    for (int i = 1; i <= num1; i++) {
        if (num1 % i == 0) {
            arr1.push_back(i);
        }
    }

    // Find divisors of num2 and store in arr2
    for (int i = 1; i <= num2; i++) {
        if (num2 % i == 0) {
            arr2.push_back(i);
        }
    }

    // Find common elements in arr1 and arr2
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

	int max = 0;


    // Print common divisors

    for (int k = 0; k < temp.size(); k++) {
		if (max < temp[k])
		{
			max = temp[k];
		}
		
    }

	
	cout << max;
	 

    return 0;
}
