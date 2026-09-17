#include <bits/stdc++.h>

using namespace std;


int largest_visible_area(int k, std::vector<std::pair<int, int>> cylinders) {
    int n = cylinders.size();
    
    sort(cylinders.begin(), cylinders.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    long long max_area = 0;

    for(int i = 0; i <= n-k; i++) {
        long long r_bottom = cylinders[i].first;
        long long m_bottom = cylinders[i].second;

        long long current_base = r_bottom * r_bottom;
        long long current_mantel_sum = m_bottom;

        std::vector<int> mental_above;
        for(int j = i+1; j < n; j++) {
            if(cylinders[j].first < r_bottom) {
                mental_above.push_back(cylinders[j].second);
            }
        }

        if(mental_above.size() < static_cast<size_t>(k - 1)) {
            continue;;
        }

        if(k > 1) {
            std::sort(mental_above.rbegin(), mental_above.rend()) ;
            for(int idx = 0; idx < k-1; idx++) {
                current_mantel_sum += mental_above[idx];
            }
        }

        long long total_area = current_base + current_mantel_sum;
        max_area = std::max(max_area, total_area);
    }
    return  static_cast<int>(max_area);
};