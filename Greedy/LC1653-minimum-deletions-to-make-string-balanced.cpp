#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length();

        // 1. Find total number of 'a' characters
        int total_a = 0;
        for (char c : s)
        {
            if (c == 'a')
                total_a++;
        }

        // If there are no 'a's or no 'b's, it's already balanced
        if (total_a == 0 || total_a == n)
            return 0;

        int min_deletions = n; // Initialize with a large value
        int b_seen = 0;
        int a_seen = 0;

        // 2. Iterate through every possible split point
        // We consider the split happening BEFORE index i
        for (int i = 0; i <= n; ++i)
        {
            // Cost = (b's to the left that must be removed)
            //        + (a's to the right/current that must be removed)
            int a_remaining = total_a - a_seen;
            int current_cost = b_seen + a_remaining;

            min_deletions = min(min_deletions, current_cost);

            // Update counts for the next iteration
            if (i < n)
            {
                if (s[i] == 'a')
                    a_seen++;
                else
                    b_seen++;
            }
        }

        return min_deletions;
    }
};