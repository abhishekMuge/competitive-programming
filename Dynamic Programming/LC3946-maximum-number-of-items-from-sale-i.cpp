#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        // Step 1: Count total items from buying the 1st copy of each item
        vector<int> gain(n, 1);
        int min_price = 1e9;
        
        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            int pi = items[i][1];
            min_price = min(min_price, pi);
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % fi == 0) {
                    gain[i]++;
                }
            }
        }
        
        // Step 2: 0/1 Knapsack for choosing which items to unlock (1st copy)
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int pi = items[i][1];
            int g = gain[i];
            for (int c = budget; c >= pi; --c) {
                dp[c] = max(dp[c], dp[c - pi] + g);
            }
        }
        
        // Step 3: Add extra copies using leftover budget and cheapest item
        int ans = 0;
        for (int c = 0; c <= budget; ++c) {
            int extra = (budget - c) / min_price;
            ans = max(ans, dp[c] + extra);
        }
        
        return ans;
    }
};