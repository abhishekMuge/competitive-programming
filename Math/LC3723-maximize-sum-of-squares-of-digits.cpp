#include <string>
#include <algorithm>

class Solution {
public:
    std::string maximumSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible value (9 * num), it's impossible
        if (sum > num * 9) {
            return "";
        }
        
        std::string result = "";
        for (int i = 0; i < num; ++i) {
            // Try digits from 9 down to 0 to prioritize the largest possible values first
            for (int d = 9; d >= 0; --d) {
                // Check if picking digit 'd' leaves a remaining sum achievable by the rest of the slots
                if (sum - d <= (num - 1 - i) * 9 && sum - d >= 0) {
                    result += std::to_string(d);
                    sum -= d;
                    break;
                }
            }
        }
        return result;
    }
};