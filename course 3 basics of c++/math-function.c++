#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // Absolute value
  double num1 = -10.5;
  double abs_value = abs(num1);
  cout << "Absolute value of " << num1 << " is: " << abs_value << endl;

  // Square root
  double num2 = 25.0;
  double square_root = sqrt(num2);
  cout << "Square root of " << num2 << " is: " << square_root << endl;

  // Power (x raised to the power of y)
  double base = 2.0;
  int exponent = 3;
  double power_result = pow(base, exponent);
  cout << base << " raised to the power of " << exponent << " is: " << power_result << endl;

  // There are many more functions available in <cmath>
  //  * Trigonometric functions (sin, cos, tan, etc.)
  //  * Logarithmic functions (log, log10, log2)
  //  * Exponential function (exp)
  //  * Rounding functions (ceil, floor, round)
  //  * Minimum and Maximum functions (fmin, fmax)

  return 0;
}
