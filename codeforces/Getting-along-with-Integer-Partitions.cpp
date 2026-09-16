#include <bits/stdc++.h>

using namespace std;

class IntPart
{
public:
  static std::string part(long long n);
};


// Helper function with memoization to generate unique products directly
void get_products(int rem, int max_val, int current_product, std::set<int>& unique_products, std::map<std::tuple<int, int, int>, bool>& memo) {
    if (rem == 0) {
        unique_products.insert(current_product);
        return;
    }

    auto state = std::make_tuple(rem, max_val, current_product);
    if (memo.find(state) != memo.end()) {
        return;
    }
    memo[state] = true;

    for (int i = std::min(rem, max_val); i >= 1; --i) {
        get_products(rem - i, i, current_product * i, unique_products, memo);
    }
}

std::string part(int n) {
    std::set<int> unique_products;
    std::map<std::tuple<int, int, int>, bool> memo;

    // Step 1 & 2: Generate partitions and collect unique products directly
    get_products(n, n, 1, unique_products, memo);

    // Convert set to vector for index-based access
    std::vector<int> prods(unique_products.begin(), unique_products.end());
    int count = prods.size();

    // Step 3: Compute Range, Average, and Median
    int rng = prods.back() - prods.front();

    double sum = std::accumulate(prods.begin(), prods.end(), 0.0);
    double avg = sum / count;

    double med;
    int mid = count / 2;
    if (count % 2 == 1) {
        med = prods[mid];
    } else {
        med = (prods[mid - 1] + prods[mid]) / 2.0;
    }

    // Step 4: Format string with 2 decimal places
    std::ostringstream out;
    out << "Range: " << rng 
        << " Average: " << std::fixed << std::setprecision(2) << avg 
        << " Median: " << std::fixed << std::setprecision(2) << med;

    return out.str();
}

int main() {
    std::cout << part(5) << std::endl; 
    // Output: Range: 5 Average: 3.50 Median: 3.50

    std::cout << part(8) << std::endl; 
    // Output: Range: 17 Average: 8.29 Median: 7.50

    return 0;
}