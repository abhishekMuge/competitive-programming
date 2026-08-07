#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
      
        int l = *std::max_element(weights.begin(), weights.end());
        
        
        long long r = std::accumulate(weights.begin(), weights.end(), 0LL);
        
        int res = r;

        while (l <= r) {
            int k = l + (r - l) / 2;
            
            int current_days_needed = 1;
            int current_daily_weight = 0;
            
            for (int w : weights) {
               
                if (current_daily_weight + w > k) {
                    current_days_needed++;
                    current_daily_weight = 0; 
                }
                current_daily_weight += w;
            }
            
            
            if (current_days_needed <= days) {
                res = k;        
                r = k - 1;      
            } else {
                l = k + 1;     
            }
        }
        
        return res;
    }
};