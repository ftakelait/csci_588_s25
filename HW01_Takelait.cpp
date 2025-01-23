#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 1. Is the value 62.6738 rational or irrational? Why or why not?
    cout << "1. The value 62.6738 is rational because it can be expressed as a fraction (626738 / 10000) where both numerator and denominator are integers." << endl;

    // 2. Evaluate the expression: 10^7 * 10^-5
    double result2 = pow(10, 7) * pow(10, -5);
    cout << "2. 10^7 * 10^-5 = " << result2 << endl;

    // 3. Evaluate the expression: 81^(1/2)
    double result3 = pow(81, 1.0 / 2);
    cout << "3. 81^(1/2) = " << result3 << endl;

    // 4. Evaluate the expression: 25^(3/2)
    double result4 = pow(25, 3.0 / 2);
    cout << "4. 25^(3/2) = " << result4 << endl;

    // 5. For the function f(x) = 3x^2 + 1, what is the slope at x = 3?
    double slope5 = 6 * 3; // Derivative of f(x) = 3x^2 + 1 is f'(x) = 6x
    cout << "5. The slope of f(x) = 3x^2 + 1 at x = 3 is " << slope5 << endl;

    // 6. For the function f(x) = 3x^2 + 1, what is the area under the curve for x between 0 and 2?
    // The integral of f(x) = 3x^2 + 1 is F(x) = x^3 + x
    double area6 = pow(2, 3) + 2 - (pow(0, 3) + 0); // F(2) - F(0)
    cout << "6. The area under the curve f(x) = 3x^2 + 1 for x in [0, 2] is " << area6 << endl;

    return 0;
}
