#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class GerrymanderSolver {
    string grid_str;
    vector<string> grid;
    int districts[5][5];
    int district_counts[6]; // 1-indexed for convenience

    bool is_valid_assignment(int r, int c, int d) {
        if (district_counts[d] == 5) return false;
        
        // If it's the first member, any cell is valid
        if (district_counts[d] == 0) return true;
        
        // Check for adjacency to existing member of the same district
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && districts[nr][nc] == d) {
                return true;
            }
        }
        return false;
    }

    bool check_win_condition() {
        int wins = 0;
        int district_os[6] = {0};
        
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (grid[r][c] == 'O') {
                    district_os[districts[r][c]]++;
                }
            }
        }
        
        for (int d = 1; d <= 5; ++d) {
            if (district_os[d] >= 3) wins++;
        }
        return wins >= 3;
    }

    bool solve(int cell_idx) {
        if (cell_idx == 25) {
            return check_win_condition();
        }

        int r = cell_idx / 5;
        int c = cell_idx % 5;

        for (int d = 1; d <= 5; ++d) {
            if (is_valid_assignment(r, c, d)) {
                districts[r][c] = d;
                district_counts[d]++;
                
                if (solve(cell_idx + 1)) return true;
                
                // Backtrack
                district_counts[d]--;
                districts[r][c] = 0;
            }
        }
        return false;
    }

public:
    string gerrymander(string input) {
        // Parse input
        grid.resize(5);
        stringstream ss(input);
        for(int i = 0; i < 5; ++i) ss >> grid[i];

        // Initialize state
        for(int i = 0; i < 5; ++i) 
            for(int j = 0; j < 5; ++j) districts[i][j] = 0;
        for(int i = 0; i < 6; ++i) district_counts[i] = 0;

        if (solve(0)) {
            string result = "";
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) {
                    result += to_string(districts[i][j]);
                    if (j < 4) result += ""; // Compact digits
                }
                if (i < 4) result += "\n";
            }
            return result;
        }
        return ""; // Or null equivalent
    }
};

int main() {
    // 1. Setup the input as defined in the Kata example
    std::string region = 
        "OOXXX\n"
        "OOXXX\n"
        "OOXXX\n"
        "OOXXX\n"
        "OOXXX";

    // 2. Instantiate the solver
    GerrymanderSolver solver;

    // 3. Execute
    std::cout << "Testing Gerrymander Solver..." << std::endl;
    std::string result = solver.gerrymander(region);

    // 4. Debug output
    if (result.empty()) {
        std::cout << "FAILED: No solution found for the given grid." << std::endl;
    } else {
        std::cout << "SUCCESS: Solution found:" << std::endl;
        std::cout << result << std::endl;
    }

    return 0;
}