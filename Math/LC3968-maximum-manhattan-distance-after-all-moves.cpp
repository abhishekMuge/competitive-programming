#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int underscore = 0;

        for(auto move : moves) {
            switch(move) {
                case 'L': x--; break;
                case 'R': x++; break;
                case 'U': y++; break;
                case 'D': y--; break;
                case '_': underscore++; break;
            }
        }
        return abs(x) + abs(y) + abs(underscore);
    }
};

/*
Every step along the $x$-axis or $y$-axis has identical weight. 
Moving $+1$ in $x$ increases total distance by $1$ exactly the same as moving $+1$ in $y$.


Order Independence: The final distance depends only on the net coordinates, not the order of steps.
Post-Processing Model: Imagine executing all fixed moves first to land at a base coordinate $(x, y)$.
The Wildcard Invariant: No matter where $(x, y)$ is, each wildcard (_) can always be chosen
                        to match the sign of $x$ or $y$. This guarantees that every single wildcard increases 
                        the total absolute displacement by exactly $1$.
*/