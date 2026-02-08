#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count = 0;
    int n;
    vector<bool> used;

    void backtrack(int pos)
    {
        // Base case: all positions filled
        if (pos > n)
        {
            count++;
            return;
        }

        // Try all numbers from 1 to n
        for (int num = 1; num <= n; num++)
        {

            // Skip if number already used
            if (used[num])
                continue;

            // Check beautiful arrangement condition
            if (num % pos == 0 || pos % num == 0)
            {

                // -------- CHOOSE --------
                used[num] = true;

                // -------- EXPLORE --------
                backtrack(pos + 1);

                // -------- BACKTRACK --------
                used[num] = false;
            }
        }
    }

    int countArrangement(int N)
    {
        n = N;
        used.assign(n + 1, false); // 1-based indexing
        backtrack(1);
        return count;
    }
};
