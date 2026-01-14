#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int movesAlice = 0, movesBob = 0;
        int n = colors.size();

        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                    movesAlice++;
                else
                    movesBob++;
            }
        }
        return movesAlice > movesBob;
    }
};