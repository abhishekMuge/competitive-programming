#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        // Base case
        if (n == 0)
            return 1;

        int result = 10;         // count for n = 1
        int uniqueDigits = 9;    // choices for first digit (1–9)
        int availableDigits = 9; // remaining digits

        for (int i = 2; i <= n && availableDigits > 0; i++)
        {
            uniqueDigits *= availableDigits;
            result += uniqueDigits;
            availableDigits--;
        }

        return result;
    }
};