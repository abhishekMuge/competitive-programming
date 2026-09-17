#include <bits/stdc++.h>

class IntPart
{
public:
  static void get_products(long long rem, long long max_val, long long current_product, 
                             std::set<long long>& unique_products, 
                             std::map<std::tuple<long long, long long, long long>, bool>& memo) {
      if (rem == 0) {
          unique_products.insert(current_product);
          return;
      }

      auto state = std::make_tuple(rem, max_val, current_product);
      if (memo.find(state) != memo.end()) {
          return;
      }
      memo[state] = true;

      for (long long i = std::min(rem, max_val); i >= 1; --i) {
          get_products(rem - i, i, current_product * i, unique_products, memo);
      }
  }
  static std::string part(long long n) {
      std::set<long long> unique_products;
      std::map<std::tuple<long long, long long, long long>, bool> memo;

      // Step 1 & 2: Generate partitions and collect unique products directly
      get_products(n, n, 1, unique_products, memo);

      // Convert set to vector for index-based access
      std::vector<long long> prods(unique_products.begin(), unique_products.end());
      size_t count = prods.size();

      // Step 3: Compute Range, Average, and Median
      long long rng = prods.back() - prods.front();

      double sum = std::accumulate(prods.begin(), prods.end(), 0.0);
      double avg = sum / count;

      double med;
      size_t mid = count / 2;
      if (count % 2 == 1) {
          med = static_cast<double>(prods[mid]);
      } else {
          med = (prods[mid - 1] + prods[mid]) / 2.0;
      }

      // Step 4: Format string with exact decimal formatting
      std::ostringstream out;
      out << "Range: " << rng 
          << " Average: " << std::fixed << std::setprecision(2) << avg 
          << " Median: " << std::fixed << std::setprecision(2) << med;

      return out.str();
  }
};