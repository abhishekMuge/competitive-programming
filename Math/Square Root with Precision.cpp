#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
using namespace std;

class SquareRoot
{
public:
    /**
     * Compute square root of x with k decimal places using binary search + linear increment
     *
     * @param x The number to find square root of (non-negative)
     * @param k Number of decimal places required
     * @return Square root with k decimal places
     * @throws invalid_argument if x is negative
     */
    static double sqrtPrecision(int x, int k)
    {
        // Validate input
        if (x < 0)
        {
            throw invalid_argument("Cannot compute square root of negative number");
        }
        if (x == 0)
            return 0.0;
        if (x == 1)
            return 1.0;

        // Step 1: Binary search to find integer part
        double left = 0.0;
        double right = x;
        if (x > 4)
            right = x / 2.0; // Optimization: √x ≤ x/2 for x > 4

        double ans = 0.0;
        const double EPSILON = 1e-10; // Precision for binary search

        while (right - left > EPSILON)
        {
            double mid = left + (right - left) / 2.0;

            if (mid * mid <= x)
            {
                ans = mid;  // Store current best answer
                left = mid; // Search in right half for potentially larger answer
            }
            else
            {
                right = mid; // Search in left half
            }
        }

        // Step 2: Add decimal places one by one using linear increment
        double increment = 0.1;
        for (int i = 0; i < k; i++)
        {
            // Keep adding increment while ans² ≤ x
            while (ans * ans <= x)
            {
                ans += increment;
            }

            // We overshot by one increment, so backtrack
            ans -= increment;

            // Prepare for next decimal place (more precise)
            increment /= 10.0;
        }

        return ans;
    }
};