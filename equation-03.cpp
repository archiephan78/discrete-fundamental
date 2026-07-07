/*
 * Problem: Biquadratic Real Root Checker
 *
 * Given three real numbers a, b, and c. Consider the statement
 * p = "The equation ax^4 + bx^2 + c = 0 has at least one real root."
 *
 * Task: Determine the value of p for the given real numbers a, b, and c.
 *
 * Input: A single line containing three real numbers a, b, and c.
 * Output: The value of p (1 if true, 0 if false).
 *
 * Example:
 * Input:  5.0 -7.5 1.3
 * Output: 1
 * Explanation: The biquadratic equation 5.0*x^4 - 7.5*x^2 + 1.3 = 0
 * has 4 distinct real roots.
 *
 * Idea:
 * Substitute t = x^2 (so t must be >= 0 for x to be real).
 * The equation becomes a*t^2 + b*t + c = 0.
 * The original equation has a real root x if and only if this
 * quadratic-in-t equation has at least one root t with t >= 0
 * (each such t gives x = +-sqrt(t), which is real).
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    const double EPS = 1e-9;
    bool p;

    if (fabs(a) > EPS) {
        // Case a != 0: genuine quadratic in t
        double D = b * b - 4 * a * c; // discriminant

        if (D < -EPS) {
            // No real roots t at all
            p = false;
        } else if (fabs(D) <= EPS) {
            // Exactly one (double) root t
            double t = -b / (2 * a);
            p = (t >= -EPS); // t >= 0 means x is real
        } else {
            // Two distinct real roots t1, t2
            double sqrtD = sqrt(D);
            double t1 = (-b + sqrtD) / (2 * a);
            double t2 = (-b - sqrtD) / (2 * a);
            p = (t1 >= -EPS) || (t2 >= -EPS); // true if either t is non-negative
        }
    } else {
        // Case a == 0: equation degenerates to b*t + c = 0 (i.e. b*x^2 + c = 0)
        if (fabs(b) > EPS) {
            // Linear equation in t: unique root t = -c/b
            double t = -c / b;
            p = (t >= -EPS);
        } else {
            // Case a == 0 and b == 0 -> constant equation c = 0
            if (fabs(c) <= EPS) {
                // 0 = 0 -> infinitely many solutions (every real x works)
                // so there definitely exists a real root
                p = true;
            } else {
                // 0 = c with c != 0 -> no solution at all
                p = false;
            }
        }
    }

    cout << (p ? 1 : 0) << endl;
    return 0;
}