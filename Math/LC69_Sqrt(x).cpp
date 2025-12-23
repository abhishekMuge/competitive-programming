class Solution {
public:
    int mySqrt(int x) {
        // Base cases
        if (x == 0) return 0;  // √0 = 0
        if (x < 4) return 1;   // √1 = 1, √2 = 1, √3 = 1
        
        // We know sqrt(x) is between 1 and x/2 (for x > 1)
        int left = 1;
        int right = x / 2;  // Optimization: sqrt(x) ≤ x/2 for x > 2
        int result = 0;
        
        // Binary search loop
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Avoid overflow
            
            // Instead of mid * mid <= x, we use mid <= x / mid
            // This prevents integer overflow
            if (mid <= x / mid) {
                // mid could be our answer, but maybe there's a larger valid number
                result = mid;        // Store this as potential answer
                left = mid + 1;      // Search in the right half
            } else {
                // mid² > x, so answer must be in left half
                right = mid - 1;     // Search in the left half
            }
        }
        
        return result;
    }
};