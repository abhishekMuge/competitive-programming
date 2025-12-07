#include <bits/stdc++.h>

using namespace std;
static const long long MOD = 1e9 + 7;

class solution {
    int combinedCout(long long n) {
        if(n < 2) return 0;
        return (n * (n - 1) / 2) % MOD;

    } 
    int numberOfHorizontalTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<int, long long> freq;

        for(auto &p: points) {
            freq[p[1]]++;
        }
        vector<long long> segments;
        segments.reserve(freq.size() + 1);
        for(auto& item: freq) {
            long long cnt = item.second;
            long long seg = combinedCout(cnt);
            if(seg > 0) segments.emplace_back(seg);
        }

        long long total = 0;

        long long prefixSum = 0;
        // Instead of O(k^2) loops, maintain prefix sum to do it in O(k)
        for (long long seg : segments)
        {
            total = (total + (seg * prefixSum) % MOD) % MOD;
            prefixSum = (prefixSum + seg) % MOD;
        }

        return (int)total;
    }
};