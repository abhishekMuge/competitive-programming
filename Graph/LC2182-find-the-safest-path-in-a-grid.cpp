#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:

    vector<vector<int>> computeDistance(vector<vector<int>>& grid)
    {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if(dist[nx][ny] != INT_MAX)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }

        return dist;
    }

    bool canReach(vector<vector<int>>& dist, int safe)
    {
        int n = dist.size();

        if(dist[0][0] < safe)
            return false;

        queue<pair<int,int>> q;

        vector<vector<bool>> vis(n, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return true;

            for(int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                if(dist[nx][ny] < safe)
                    continue;

                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n = grid.size();

        auto dist = computeDistance(grid);

        int low = 0;
        int high = 2 * n;
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(canReach(dist, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/*
Run multi-source BFS starting from every thief to compute the distance from each cell to its nearest thief. This produces the safety map.
Binary search on the candidate safeness factor k.
For each k, run a BFS/DFS from (0,0) to (n-1,n-1) while only visiting cells whose safety value is at least k.
If such a path exists, try a larger k; otherwise, try a smaller one.
The largest feasible k is the answer.

*/