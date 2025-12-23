class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1);
        int maxKeep = 1;

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                bool canFollow = true;

                // Check all rows
                for (int r = 0; r < m; ++r)
                {
                    if (strs[r][i] > strs[r][j])
                    {
                        canFollow = false;
                        break;
                    }
                }

                if (canFollow)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            maxKeep = max(maxKeep, dp[j]);
        }

        return n - maxKeep;
    }
};