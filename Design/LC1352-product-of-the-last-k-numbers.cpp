#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
    vector<int> prefix;
public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = static_cast<int>(prefix.size()) - 1;

        if( k > n) {
            return 0;
        }

        return prefix[n] / prefix[n-k];
    }
};
