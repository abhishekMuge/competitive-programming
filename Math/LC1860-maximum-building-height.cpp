#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions)
    {
        restrictions.push_back({1,0});

        bool found = false;

        for(auto &r : restrictions)
        {
            if(r[0] == n)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            restrictions.push_back({n,(int)1e9});
        }

        sort(restrictions.begin(), restrictions.end());

        // Forward pass
        for(int i = 1; i < restrictions.size(); i++)
        {
            long long d =
                restrictions[i][0] -
                restrictions[i-1][0];

            restrictions[i][1] =
                min((long long)restrictions[i][1],
                    (long long)restrictions[i-1][1] + d);
        }

        // Backward pass
        for(int i = restrictions.size()-2; i >= 0; i--)
        {
            long long d =
                restrictions[i+1][0] -
                restrictions[i][0];

            restrictions[i][1] =
                min((long long)restrictions[i][1],
                    (long long)restrictions[i+1][1] + d);
        }

        long long ans = 0;

        for(int i = 1; i < restrictions.size(); i++)
        {
            long long x1 = restrictions[i-1][0];
            long long h1 = restrictions[i-1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long d = x2 - x1;

            long long peak =
                (h1 + h2 + d) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};


/*

put this auto generated markdown for viwer to see the logic.
# LeetCode 1840 - Maximum Building Height

## Key Observations

We are given:

* `height[1] = 0`
* `|height[i] - height[i-1]| <= 1`
* Some buildings have upper-bound restrictions.

The goal is to find the maximum possible height among all buildings.

---

# Step 1: Convert Restrictions into Checkpoints

Each restriction can be viewed as:

```text
(position, maximum_height)
```

Since building 1 must have height 0, add:

```cpp
(1, 0)
```

If building `n` is not present in restrictions, add:

```cpp
(n, INF)
```

This allows us to process the entire range uniformly.

---

# Step 2: Sort Restrictions

Sort all restriction points by building index.

Example:

```text
Before:
(5,3), (2,1), (10,INF), (1,0)

After:
(1,0), (2,1), (5,3), (10,INF)
```

---

# Step 3: Forward Constraint Propagation

Suppose we have:

```text
(x1, h1)
(x2, h2)
```

Distance:

```text
d = x2 - x1
```

Because adjacent buildings can differ by at most 1:

```text
h2 <= h1 + d
```

Therefore:

```cpp
h2 = min(h2, h1 + d);
```

This propagates constraints from left to right.

---

## Example

```text
(2,1)
(5,10)
```

Distance:

```text
d = 3
```

Maximum reachable height at building 5:

```text
1 + 3 = 4
```

So:

```text
(5,10) → (5,4)
```

---

# Step 4: Backward Constraint Propagation

Similarly:

```text
h1 <= h2 + d
```

Therefore:

```cpp
h1 = min(h1, h2 + d);
```

This propagates constraints from right to left.

---

## Example

```text
(2,10)
(5,3)
```

Distance:

```text
d = 3
```

Maximum possible height at building 2:

```text
3 + 3 = 6
```

So:

```text
(2,10) → (2,6)
```

---

# Why Both Passes?

A restriction affects buildings on both sides.

Forward pass handles:

```text
Left → Right
```

Backward pass handles:

```text
Right → Left
```

After both passes, every restriction becomes globally consistent.

---

# Step 5: Find the Highest Peak Between Two Restrictions

Consider two neighboring restriction points:

```text
(x1, h1)
(x2, h2)
```

Distance:

```text
d = x2 - x1
```

We want the highest possible building between them.

---

## Visual Interpretation

Example:

```text
(2,1)
(4,1)
```

```text
1 → 2 → 1
```

Peak = 2

---

Another example:

```text
(5,3)
(7,4)
```

```text
3 → 4 → 4
```

Peak = 4

---

# Peak Formula

The optimal shape is always a mountain:

```text
Increase by 1 each step
Reach peak
Decrease by 1 each step
```

The peak occurs where the left and right slopes meet.

Formula:

```text
peak = floor((h1 + h2 + d) / 2)
```

or

```cpp
peak = (h1 + h2 + d) / 2;
```

---

## Why This Formula Works

Maximum height reachable from the left:

```text
h1 + k
```

Maximum height reachable from the right:

```text
h2 + (d - k)
```

At the peak:

```text
h1 + k = h2 + (d - k)
```

Solving:

```text
2k = h2 - h1 + d
```

Substituting back:

```text
peak = (h1 + h2 + d) / 2
```

---

# Algorithm

1. Add `(1,0)`
2. Add `(n,INF)` if missing
3. Sort restrictions
4. Forward relaxation
5. Backward relaxation
6. For every adjacent restriction pair:

   * Compute peak using

```cpp
(h1 + h2 + d) / 2
```

7. Return maximum peak

---

# Complexity Analysis

Let:

```text
m = restrictions.size()
```

### Sorting

```text
O(m log m)
```

### Forward Pass

```text
O(m)
```

### Backward Pass

```text
O(m)
```

### Peak Computation

```text
O(m)
```

### Total

```text
O(m log m)
```

### Space

```text
O(1)
```

(excluding input storage)

---

The problem is not about constructing every building.

The key insight is:

1. Treat restrictions as checkpoints.
2. Propagate constraints in both directions.
3. Between two checkpoints, the optimal shape is always a mountain.
4. The mountain's peak is:

```cpp
(h1 + h2 + distance) / 2
```

This reduces a problem with `n ≤ 10^9` buildings to processing only the restriction points (`≤ 10^5`).




*/