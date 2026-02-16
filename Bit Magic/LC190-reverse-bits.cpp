#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i)
        {
            result = (result << 1) | (n & 1); // take last bit and add to result
            n >>= 1;                          // move to next bit
        }
        return result;
    }
};