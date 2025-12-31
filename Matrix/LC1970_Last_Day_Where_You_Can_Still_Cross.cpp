#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Helper function to check if a path exists on a given day
    bool canWalk(int day, int row, int col, vector<vector<int>> &cells)
    {
        // Create a grid for the current state (0 = land, 1 = water)
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Fill the grid with water based on the cells flooded up to 'day'
        for (int i = 0; i < day; ++i)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        // Start BFS from all land cells in the first row
        for (int c = 0; c < col; ++c)
        {
            if (grid[0][c] == 0)
            {
                q.push({0, c});
                grid[0][c] = 1; // Mark as visited by flipping to water
            }
        }

        // Directions for Up, Down, Left, Right
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            // If we reached the last row, a path exists
            if (r == row - 1)
                return true;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundaries and if the cell is land
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0)
                {
                    grid[nr][nc] = 1; // Mark as visited
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1, right = cells.size();
        int ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canWalk(mid, row, col, cells))
            {
                ans = mid; // Try for a later day
                left = mid + 1;
            }
            else
            {
                right = mid - 1; // Too much water, try an earlier day
            }
        }
        return ans;
    }
};

//----------------------------------------------------------------------------------------
// DSU Approach

#include <vector>
#include <numeric>

using namespace std;

class DSU
{
public:
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_i] = root_j;
        }
    }
};

class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int n = row * col;
        DSU dsu(n + 2); // n is Top Virtual Node, n+1 is Bottom Virtual Node
        int topNode = n;
        int bottomNode = n + 1;

        // grid[r][c] == 1 means it is currently water
        vector<vector<int>> grid(row, vector<int>(col, 1));

        // Directions: Right, Left, Down, Up
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        // Work backwards from the last day to the first
        for (int i = cells.size() - 1; i >= 0; --i)
        {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 0; // Turn water back into land

            int currentIndex = r * col + c;

            // Check neighbors
            for (int j = 0; j < 4; ++j)
            {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0)
                {
                    dsu.unite(currentIndex, nr * col + nc);
                }
            }

            // Connect to top virtual node if in first row
            if (r == 0)
                dsu.unite(currentIndex, topNode);

            // Connect to bottom virtual node if in last row
            if (r == row - 1)
                dsu.unite(currentIndex, bottomNode);

            // Check if top and bottom are now connected
            if (dsu.find(topNode) == dsu.find(bottomNode))
            {
                return i; // This is the last day (0-indexed) a path exists
            }
        }

        return 0;
    }
};