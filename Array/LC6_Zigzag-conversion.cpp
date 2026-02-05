#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // Edge case: if rows = 1, the pattern is just the string itself
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currentRow] += c;

            // Reverse direction if we hit the top or bottom
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // Join all rows into one final string
        string result;
        for (string row : rows)
            result += row;
        return result;
    }

    string convert_optimized_space(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string result;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                // Add the main character of the cycle
                result += s[j + i];

                // If not first or last row, check for the middle character
                int midIndex = j + cycleLen - i;
                if (i != 0 && i != numRows - 1 && midIndex < n)
                {
                    result += s[midIndex];
                }
            }
        }
        return result;
    }
};
