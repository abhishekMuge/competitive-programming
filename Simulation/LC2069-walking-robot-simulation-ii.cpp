#include <bits/stdc++.h>

using namespace std;

class Robot {
private:
    int width;
    int height;
    int x;
    int y;
    int dir;
    long long steps;
    
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->x = 0;
        this->y = 0;
        this->dir = 0;  // East
        this->steps = 0;
    }
    
    void step(int num) {
        steps += num;
        
        // If grid is 1x1, robot can't move
        if (width == 1 && height == 1) {
            x = 0;
            y = 0;
            dir = 0;
            return;
        }
        
        // Calculate effective steps on perimeter
        int perimeter = 2 * (width + height) - 4;
        
        // Reduce steps modulo perimeter
        // But careful: when steps is multiple of perimeter, we're at a corner
        long long effective = steps % perimeter;
        
        if (effective == 0) {
            // At a corner after full laps
            // Determine which corner based on steps/perimeter parity
            long long laps = steps / perimeter;
            if (laps % 2 == 1) {
                // Odd number of laps? Actually let's just simulate the last lap
                effective = perimeter;
            } else {
                effective = perimeter;
            }
        }
        
        // Now simulate at most perimeter steps (which is bounded)
        x = 0;
        y = 0;
        dir = 0;
        
        for (int i = 0; i < effective; i++) {
            int nextX = x + (dir == 0 ? 1 : (dir == 2 ? -1 : 0));
            int nextY = y + (dir == 1 ? 1 : (dir == 3 ? -1 : 0));
            
            if (nextX < 0 || nextX >= width || nextY < 0 || nextY >= height) {
                dir = (dir + 1) % 4;
                nextX = x + (dir == 0 ? 1 : (dir == 2 ? -1 : 0));
                nextY = y + (dir == 1 ? 1 : (dir == 3 ? -1 : 0));
            }
            
            x = nextX;
            y = nextY;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        vector<string> dirs = {"East", "North", "West", "South"};
        return dirs[dir];
    }
};
