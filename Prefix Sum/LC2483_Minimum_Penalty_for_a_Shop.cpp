#include <bits/stdc++.h>

using namespace std;

class solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();

        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix_sum[i + 1] = prefix_sum[i] + (customers[i] == 'N' ? 1 : 0);
        }

        vector<int> sufix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            sufix_sum[i] = sufix_sum[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int min_penalty = n + 1;
        int best_hour = 0;

        for (int j = 0; j <= n; j++)
        {
            int current_penalty = prefix_sum[j] + sufix_sum[j];
            if (current_penalty < min_penalty)
            {
                min_penalty = current_penalty;
                best_hour = j;
            }
        }
        return best_hour;
    }
};

/*Optimized Space Approch

Instead of building two separate arrays, we track a running penalty score.
We start by assuming the shop closes at hour 0.
As we move the closing time from hour $i$ to $i+1$:If customers[i] == 'Y',
the penalty decreases (we were closed, but now we are open for a customer).
If customers[i] == 'N', the penalty increases (we were closed and fine, but now we are open with no customer).
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.length();
        int min_penalty = 0;
        int current_penalty = 0;
        int best_hour = 0;

        // We calculate a relative penalty starting from hour 0.
        // If we see 'Y', the penalty improves (-1) if we stay open.
        // If we see 'N', the penalty worsens (+1) if we stay open.
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                current_penalty--;
            }
            else
            {
                current_penalty++;
            }

            // If the current penalty is lower than the best we've seen,
            // the earliest hour to achieve this is i + 1.
            if (current_penalty < min_penalty)
            {
                min_penalty = current_penalty;
                best_hour = i + 1;
            }
        }

        return best_hour;
    }
};