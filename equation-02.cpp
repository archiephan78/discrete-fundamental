/*
 * Problem: Quadratic Positive Root Checker
 *
 * Given three real numbers a, b, and c. Consider the statement
 * p = "The equation ax^2 + bx + c = 0 has at least one positive real root."
 *
 * Task: Determine the value of p for the given real numbers a, b, and c.
 *
 * Input: A single line containing three real numbers a, b, and c.
 * Output: The value of p (1 if true, 0 if false).
 *
 * Example:
 * Input:  5.0 7.5 1.3
 * Output: 0
 * Explanation: The quadratic equation 5.0*x^2 + 7.5*x + 1.3 = 0
 * has two negative real roots (x = -0.2 and x = -1.3).
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    const double EPS = 1e-9;
    bool p;

    if (fabs(a) > EPS) {
        double D = b * b - 4 * a * c; // discriminant

        if (D < -EPS) {
            // No real roots at all
            p = false;
        } else if (fabs(D) <= EPS) {
            // Exactly one (double) real root
            double x = -b / (2 * a);
            p = (x > EPS); // check if that root is positive
        } else {
            // Two distinct real roots
            double sqrtD = sqrt(D);
            double x1 = (-b + sqrtD) / (2 * a);
            double x2 = (-b - sqrtD) / (2 * a);
            p = (x1 > EPS) || (x2 > EPS); // true if either root is positive
        }
    } else {
        if (fabs(b) > EPS) {
            // Linear equation with unique root x = -c/b
            double x = -c / b;
            p = (x > EPS);
        } else {
            if (fabs(c) <= EPS) {
                p = true;
            } else {
                p = false;
            }
        }
    }

    cout << (p ? 1 : 0) << endl;
    return 0;
}