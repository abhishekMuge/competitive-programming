#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {
        if (n == 0)
            return 1.0;

        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        double result = 1.0;

        while (n > 0)
        {
            if (n & 1)
                result *= x;

            x = x * x;
            n >>= 1;
        }

        return result;
    }
};

/*

The Mathematical Rule
The rule for negative exponents is:

text
x^(-n) = 1 / (x^n)
Where:

x is the base

n is a positive integer

^(-n) means negative exponent

Negative Exponent Definition
By definition:

text
x^(-n) = 1 / (x^n)
This comes from the property:

text
x^a * x^b = x^(a+b)
Let's prove it:

text
x^n * x^(-n) = x^(n + (-n)) = x^0 = 1
Therefore, x^(-n) = 1 / (x^n)
*/