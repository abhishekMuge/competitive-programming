/*
Problem Statement: Maximum XOR Product
Problem DescriptionA new digital circuit has been designed that takes three integers as
 input: $A$, $B$, and $N$. Your task is to find an integer $X$ such that $0 \le X < 2^N$ which 
 maximizes the product of $(A \oplus X)$ and $(B \oplus X)$, where $\oplus$ represents the bitwise XOR operator.
 Since the maximum product can be very large, return the maximum product modulo $(10^9 + 7)$.
Note: You must maximize the product first before applying the modulo operation.
*/


#include <iostream>

using namespace std;

int maximumXORProdoct(int A, int B, int N) {
    long long x = 0;
    bool first_diff_found = false;
    bool is_a_larger = false;

    long long MOD = 1e9 + 7;

    for(int i = N -1; i >= 0; --i) {
        long long bitA = (A >> i) & 1;
        long long bitB = (B >> i) & 1;

        if(bitA == bitB) {
            if(bitA == 0) {
                x |= (1LL << i);
            }
        } else {
            if(!first_diff_found) {
                first_diff_found = true;
                if(bitA == 0) {
                    x |= (1LL << i);
                }
                is_a_larger = true;
            } else {
                if(bitB == 0) {
                    x |= (1LL << i);
                }
            }
        }
    }

    long long finalA = (A ^ x) % MOD;
    long long finalB = (B ^ x) % MOD;

    return (finalA * finalB) % MOD;
}
