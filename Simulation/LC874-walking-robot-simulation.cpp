#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: North, East, South, West
        // index 0: North (dx=0, dy=1)
        // index 1: East  (dx=1, dy=0)
        // index 2: South (dx=0, dy=-1)
        // index 3: West  (dx=-1, dy=0)
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Store obstacles in a set for O(1) lookup
        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0;           // Current position
        int dir = 0;                // 0: North, 1: East, 2: South, 3: West
        int maxDistSq = 0;
        
        // Process each command
        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left (counter-clockwise)
                dir = (dir + 3) % 4;
            } 
            else if (cmd == -1) {
                // Turn right (clockwise)
                dir = (dir + 1) % 4;
            } 
            else {
                // Move forward k steps, one step at a time
                for (int step = 0; step < cmd; step++) {
                    int nextX = x + dirs[dir].first;
                    int nextY = y + dirs[dir].second;
                    
                    // Check if next position is an obstacle
                    if (obstacleSet.count({nextX, nextY})) {
                        break;  // Stop moving for this command
                    }
                    
                    // Move to next position
                    x = nextX;
                    y = nextY;
                    
                    // Update maximum squared distance
                    maxDistSq = max(maxDistSq, x*x + y*y);
                }
            }
        }
        
        return maxDistSq;
    }
};