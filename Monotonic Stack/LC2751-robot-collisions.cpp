#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Create a vector of robots with (position, health, direction, original_index)
        vector<tuple<int, int, char, int>> robots;
        for (int i = 0; i < n; i++) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        // Sort robots by position
        sort(robots.begin(), robots.end());
        
        // Stack stores (health, original_index) for right-moving robots
        stack<pair<int, int>> st;
        
        // Result array to store final healths
        vector<int> result(n, 0);
        
        for (const auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char direction = get<2>(robot);
            int idx = get<3>(robot);
            
            if (direction == 'R') {
                // Right-moving robot goes into stack
                st.push({health, idx});
            } else {
                // Left-moving robot collides with right-moving robots in stack
                while (!st.empty() && health > 0) {
                    auto [right_health, right_idx] = st.top();
                    
                    if (right_health > health) {
                        // Right robot wins
                        st.top().first = right_health - 1;
                        health = 0;
                    } else if (right_health < health) {
                        // Left robot wins
                        health--;
                        st.pop();
                    } else {
                        // Equal health - both die
                        health = 0;
                        st.pop();
                    }
                }
                
                // If left robot survived all collisions
                if (health > 0) {
                    result[idx] = health;
                }
            }
        }
        
        // Add surviving right-moving robots from stack
        while (!st.empty()) {
            auto [health, idx] = st.top();
            result[idx] = health;
            st.pop();
        }
        
        // Return only surviving robots in original order
        vector<int> survivors;
        for (int health : result) {
            if (health > 0) {
                survivors.push_back(health);
            }
        }
        
        return survivors;
    }
};