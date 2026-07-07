/*
 * Problem: Root Sign Checker
 *
 * Given two real numbers a and b. Consider the statement
 * p = "The equation ax + b = 0 has at least one negative real root."
 *
 * Task: Determine the value of p for the given real numbers a and b.
 *
 * Input: A single line containing two real numbers a and b.
 * Output: The value of p (1 if true, 0 if false).
 *
 * Example:
 * Input:  5.0 7.5
 * Output: 1
 * Explanation: The equation 5.0*x + 7.5 = 0 has one negative real root (x = -1.5).
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;

    const double EPS = 1e-9;
    bool p;

    if (fabs(a) > EPS) {
        double x = -b / a;
        p = (x < 0); 
    } else {
        // Case a == 0
        if (fabs(b) < EPS) {
            p = true;
        } else {
            p = false;
        }
    }

    cout << (p ? 1 : 0) << endl;
    return 0;
}