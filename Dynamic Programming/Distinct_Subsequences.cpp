/*
The Next Variation: Distinct Subsequences
Problem: Given two strings s and t, return the number of distinct subsequences of s which equal t.

Example: s = "rabbbit", t = "rabbit"

Output: 3

Since you've mastered the relationship between subsequences and palindromes, let's tackle a variation that shifts from "matching" to **"counting paths"**. This is a favorite in technical interviews because it tests if you truly understand the state transitions.

### The Next Variation: Distinct Subsequences
**Problem:** Given two strings `s` and `t`, return the number of **distinct subsequences** of `s` which equal `t`.

* **Example:** `s = "rabbbit"`, `t = "rabbit"`
* **Output:** **3**
* **Why?** There are three different ways to pick the 'b's from "rabbbit" to form "rabbit".

---

## 1. The Intuition: "Stay or Go"
In previous problems, we just wanted the *maximum length*. Here, we want the **total count**. 

When we encounter a character in `s` that matches our current target character in `t`, we have a choice:
1.  **Use it:** Match this character and move forward in both strings.
2.  **Ignore it:** Even though it matches, skip it and see if we can form the same subsequence using characters later in `s`.

---

## 2. Setting up the DP Table
We create a table `dp[i][j]` where:
* `i` is the index in string `t` (the target).
* `j` is the index in string `s` (the source).
* `dp[i][j]` = Number of ways to form the prefix `t[0...i-1]` using the prefix `s[0...j-1]`.

### The Base Case
* If `t` is an empty string, there is exactly **1** way to form it (by deleting all characters of `s`). 
    * `dp[0][j] = 1` for all `j`.
* If `s` is empty but `t` is not, there are **0** ways.
    * `dp[i][0] = 0` for all `i > 0`.

---

## 3. The Transitions
When comparing `t[i-1]` and `s[j-1]`:

**Case 1: The characters match (`t[i-1] == s[j-1]`)**
The total ways is the sum of:
* Ways where we **use** `s[j-1]`: This is `dp[i-1][j-1]`.
* Ways where we **don't use** `s[j-1]`: This is `dp[i][j-1]`.
> $$dp[i][j] = dp[i-1][j-1] + dp[i][j-1]$$

**Case 2: The characters DON'T match**
We have no choice but to ignore `s[j-1]` and see how many ways we could form the target using the previous characters of `s`.
> $$dp[i][j] = dp[i][j-1]$$


*/


#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // dp[i][j] -> target t of length i, source s of length j
        // Use double or unsigned long long to prevent overflow during intermediate steps
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Base case: Empty target can be formed by any source prefix in 1 way
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i-1] == s[j-1]) {
                    // Sum of (using current char) + (skipping current char)
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    // Must skip current char
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return (int)dp[m][n];
    }
};