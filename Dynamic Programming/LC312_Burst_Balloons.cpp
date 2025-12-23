#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int maxCoins(std::vector<int> &nums)
    {
        int n = nums.size();

        std::vector<int> A(n + 2);
        A[0] = 1;
        A[n + 1] = 1;
        for (int i = 0; i < n; ++i)
        {
            A[i + 1] = nums[i];
        }

        int n_new = n + 2;

        std::vector<std::vector<int>> DP(n_new, std::vector<int>(n_new, 0));

        for (int L = 1; L <= n; ++L)
        {
            for (int i = 0; i <= n_new - L - 2; ++i)
            {
                int j = i + L + 1;

                for (int k = i + 1; k <= j - 1; ++k)
                {

                    long long current_coins = (long long)A[i] * A[k] * A[j];

                    long long total_coins = DP[i][k] + DP[k][j] + current_coins;

                    DP[i][j] = std::max(DP[i][j], (int)total_coins);
                }
            }
        }

        return DP[0][n + 1];
    }
};