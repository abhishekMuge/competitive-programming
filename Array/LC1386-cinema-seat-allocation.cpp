#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved_rows;
        
        // 1. Map seats 2..9 to an 8-bit integer for each reserved row
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved_rows[row] |= (1 << (col - 2));
            }
        }
        
        // Every unreserved row can take up to 2 groups
        int max_groups = n * 2;
        
        // Bitmasks for the 3 placement blocks
        const int LEFT_MASK  = 0b00001111; // Seats 2, 3, 4, 5
        const int RIGHT_MASK = 0b11110000; // Seats 6, 7, 8, 9
        const int MID_MASK   = 0b00111100; // Seats 4, 5, 6, 7
        
        // 2. Adjust counts for rows that have reservations
        for (const auto& [row, mask] : reserved_rows) {
            // Deduct the 2 default groups assumed for this row
            max_groups -= 2;
            
            bool left_free  = (mask & LEFT_MASK) == 0;
            bool right_free = (mask & RIGHT_MASK) == 0;
            bool mid_free   = (mask & MID_MASK) == 0;
            
            if (left_free && right_free) {
                max_groups += 2;
            } else if (left_free || right_free || mid_free) {
                max_groups += 1;
            }
        }
        
        return max_groups;
    }
};