#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val : stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            } else if (type == 1) {
                ++cnt1;
            } else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};


/*

---

# 📝 Stone Game IX — Logic Cheat Sheet

### 1. The Key Transformation

The exact stone values do not matter — **only their remainders modulo 3 matter**.

* **`cnt0`**: Count of stones divisible by 3 ($0 \bmod 3$).
* **`cnt1`**: Count of stones with remainder 1 ($1 \bmod 3$).
* **`cnt2`**: Count of stones with remainder 2 ($2 \bmod 3$).

---

### 2. Role of Each Stone Type

* **`1` & `2` Stones:** Change the running sum remainder. They force a strict alternating game sequence:
* Start with `1` $\rightarrow$ Forced order: **`1 -> 1 -> 2 -> 1 -> 2 -> ...`**
* Start with `2` $\rightarrow$ Forced order: **`2 -> 2 -> 1 -> 2 -> 1 -> ...`**


* **`0` Stones:** Do not change the sum remainder — they act purely as **"Turn Skips"**.

---

### 3. The Winning Decision Tree

```text
                     Is cnt0 EVEN or ODD?
                    /                    \
            EVEN (cnt0 % 2 == 0)      ODD (cnt0 % 2 != 0)
                   /                              \
       0s cancel in pairs.             Leftover 0 lets Bob trap Alice.
  Alice picks the better start.      Alice needs a huge pile surplus.
                 |                                  |
    cnt1 >= 1 && cnt2 >= 1                 abs(cnt1 - cnt2) > 2

```

---

### 4. Mental Model Summary

1. **When `cnt0` is EVEN (0, 2, 4...):**
* `0`s pair up and cancel out.
* **Alice controls the game.** She can pick whichever pile (`1`s or `2`s) is smaller to start, forcing Bob to run out of moves first.
* **Alice Wins if:** Both non-zero piles have at least one stone (`cnt1 >= 1 && cnt2 >= 1`).


2. **When `cnt0` is ODD (1, 3, 5...):**
* The 1 leftover `0` allows **Bob** to steal the turn advantage and reverse Alice's sequence against her.
* Alice is forced to burn through her starting pile faster.
* **Alice Wins if:** One pile has **at least 3 more stones** than the other (`abs(cnt1 - cnt2) > 2`) to absorb Bob's trap.



---

### 5. C++ One-Liner Core Logic

```cpp
// cnt0 EVEN -> Need both piles available
// cnt0 ODD  -> Need a surplus > 2 in one pile
return (cnt0 % 2 == 0) ? (cnt1 >= 1 && cnt2 >= 1) 
                       : (std::abs(cnt1 - cnt2) > 2);

```


*/