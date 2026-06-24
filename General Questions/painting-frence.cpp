#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long solve(vector<long long>& a, int l, int r, long long base) {
        if (l > r)
            return 0;

        // Option 1: Reset every element individually
        long long vertical = r - l + 1;

        // Find minimum value in current segment
        long long mn = LLONG_MAX;
        for (int i = l; i <= r; i++) {
            mn = min(mn, a[i]);
        }

        // Option 2: Remove common layers first
        long long horizontal = mn - base;

        int i = l;
        while (i <= r) {

            if (a[i] == mn) {
                i++;
                continue;
            }

            int j = i;
            while (j <= r && a[j] > mn)
                j++;

            horizontal += solve(a, i, j - 1, mn);

            i = j;
        }

        return min(vertical, horizontal);
    }

public:
    long long minimumOperations(vector<long long>& a) {
        int n = a.size();
        return solve(a, 0, n - 1, 0);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution sol;
        cout << sol.minimumOperations(A) << "\n";
    }

    return 0;
}