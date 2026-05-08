#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxLeft(n, 0);
        vector<int> minRight(n , 0);

        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(nums[i], maxLeft[i-1]);
        }

        for(int i = n -2; i >= 0; i--) {
            minRight[i] = min(nums[i], minRight[i+1]);
        }

        vector<int> ans(n);

        ans[n-1] = maxLeft[n-1];
        for(int i= n-2; i >= 0; i--) {
            if(maxLeft[i] <= minRight[i+1]){
                ans[i] = maxLeft[i];
            } else {
                ans[i] = ans[i+1];
            }
        }

        return ans;
    }
};


/*
### Problem Logic Summary: "The Valley-Peak Strategy"

The goal is to find the maximum reachable value from each index $i$ given two jump rules:

1. **Jump Forward ($j > i$):** Only to a **smaller** value.
2. **Jump Backward ($j < i$):** Only to a **larger** value.

---

### 1. The Core Strategy

To reach the largest possible value (a "Peak" to the left), you must first find a "Valley" (a smaller value to the right).

* **The Chain:** Start at $i \rightarrow$ Jump Right to a value smaller than $nums[i]$ $\rightarrow$ Now that you are further right, the high values at the beginning of the array are to your **left** and are **larger** than your current position $\rightarrow$ Jump Left to the maximum possible value.

### 2. Key Observations

* **Prefix Max is the Ceiling:** Once you can jump to an index $j$, you can reach any "left-peak" value that is greater than $nums[j]$. The best you can do is `maxLeft[j]`.
* **Rightward Reach:** If you can jump from index $i$ to index $i+1$ (directly or indirectly), you inherit the reachability of index $i+1$.
* **The Barrier:** You are trapped in the current prefix if every single element to your right is greater than or equal to the maximum value you can currently reach.

---

### 3. Logic of the Code Implementation

The provided $O(N)$ solution uses a clever backward pass to propagate the maximum reachable values:

1. **`maxLeft[i]`**: Stores the maximum value in the prefix $0 \dots i$. This represents the "potential" best value if you can reach index $i$ or anything to its right.
2. **`minRight[i]`**: Stores the minimum value in the suffix $i \dots n-1$. This helps identify if a "Valley" exists to the right.
3. **The Decision (`maxLeft[i] <= minRight[i+1]`)**:
* **If True:** Every element to the right of $i$ is larger than or equal to any element you can reach in the current prefix. You can never jump right. You are stuck; your maximum is just the current prefix max: `ans[i] = maxLeft[i]`.
* **If False:** There is at least one element to the right smaller than something you can reach in the current prefix. This "unlocks" the right side, allowing you to eventually reach whatever index $i+1$ can reach: `ans[i] = ans[i+1]`.



---
*/