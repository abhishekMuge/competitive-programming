#include<string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.length(); m++) {
            string ans = "";
            for (int i = m; i <= s.length(); i++) {
                string t = s.substr(i - m, m);
                if ((ans.empty() || t < ans) && ranges::count(t, '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
        return "";
    };
    }

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }
        string ans = s;
        int cnt = 0;
        for (int left = 0, right = 0; right < s.length(); right++) {
            cnt += s[right] - '0';
            while (cnt > k || s[left] == '0') {
                cnt -= s[left] - '0';
                left++;
            }
            if (cnt == k) {
                string t = s.substr(left, right - left + 1);
                if (t.length() < ans.length() ||
                    t.length() == ans.length() && t < ans) {
                    ans = move(t);
                }
            }
        }
        return ans;
    }
};
