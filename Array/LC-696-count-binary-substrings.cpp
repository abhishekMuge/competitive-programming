#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int totalCount = 0;
        int prevBlockLen = 0;
        int currentBlockLen = 1;

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                // We are still in the same block of 0s or 1s
                currentBlockLen++;
            }
            else
            {
                // The character changed!
                // 1. Add the minimum of the two adjacent blocks to our total
                totalCount += std::min(prevBlockLen, currentBlockLen);

                // 2. The current block now becomes the 'previous' block
                prevBlockLen = currentBlockLen;

                // 3. Reset current block length to 1 for the new character
                currentBlockLen = 1;
            }
        }

        // Final calculation for the last two blocks encountered
        return totalCount + std::min(prevBlockLen, currentBlockLen);
    }
};