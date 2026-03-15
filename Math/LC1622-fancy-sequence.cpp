#include <bits/stdc++.h>

using namespace std;

class Fancy {
    const long long MOD = 1e9 + 7;

    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        long long invMul = modPow(mul, MOD - 2);
        long long stored = ( (val - add + MOD) % MOD ) * invMul % MOD;
        seq.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul + add) % MOD;
    }
};
