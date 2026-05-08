#include<bits/stdc++.h>

using namespace std;


//Approach (Using BFS + Sieve)
//T.C : O(maxEL * loglog(maxEl))
//S.C : O(maxEl + n)
class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        //build isPrime vector using Sieve
        buildSieve(maxEl); //O(maxEL * loglog(maxEl));

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        //We visite each node only once - O(n)
        //O(n + maxEL * loglog(maxEl));
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};


/*
### Problem Logic Summary: "The Prime Multiplier BFS"

The goal is to find the **minimum jumps** from index $0$ to $n-1$ using three possible moves: step left, step right, or "teleport" from a prime number to any of its multiples in the array.

---

### 1. The Core Strategy: BFS for Shortest Path

Since every jump (step or teleport) has a **weight of 1**, Breadth-First Search (BFS) is the optimal algorithm to find the shortest path.

* **Nodes:** The indices of the array ($0$ to $n-1$).
* **Edges:** $(i \pm 1)$ and all indices $j$ where $nums[j]$ is a multiple of $nums[i]$ (if $nums[i]$ is prime).

---

### 2. Key Components of the Logic

#### A. Precomputing Primes (Sieve of Eratosthenes)

To quickly check if a teleportation is possible, we use a **Sieve** up to the maximum value in `nums`. This allows $O(1)$ primality testing during the BFS.

#### B. Index Mapping

An `unordered_map<int, vector<int>> mp` stores all indices where a specific value appears.

* **Why?** When at a prime $p$, we need to jump to all $j$ where $nums[j] = p, 2p, 3p, \dots$. The map lets us find these indices instantly without scanning the whole array.

#### C. The "Two-Level" Visited Guard

To maintain $O(N + maxEl \log \log maxEl)$ time complexity and avoid infinite loops or redundant work:

1. **`visited[index]`**: Standard BFS array to ensure we don't process the same index twice.
2. **`seen[prime]`**: A set (or boolean array) to ensure that if we have already triggered teleportations for a specific prime $p$, we **never do it again**.
* *Logic:* The first time we hit prime $p$, we visit all its multiples. Any subsequent encounter with $p$ would only lead to indices already in the queue or already visited.



---

### 3. Step-by-Step Execution

1. **Build Sieve:** Identify all primes up to `max(nums)`.
2. **Map Indices:** Group indices by their values.
3. **BFS Loop:**
* **Standard Moves:** Check $i+1$ and $i-1$. If not visited, push to queue.
* **Teleport Move:** If $nums[i]$ is prime and hasn't been "seen":
* Iterate through all multiples of $nums[i]$ ($p, 2p, 3p, \dots$) up to `maxEl`.
* For each multiple, jump to all its corresponding indices in the array.
* Mark $nums[i]$ as `seen` so we don't repeat this heavy calculation.




4. **Return `steps**` the moment index $n-1$ is popped.

---

### 4. Why this is Efficient

* **Sieve:** $O(M \log \log M)$ where $M$ is the max element.
* **BFS:** Each index is added to the queue at most once.
* **Teleportation:** Because of the `seen` set, the "multiples" loop for a specific prime runs exactly once. This is mathematically similar to the Sieve itself, ensuring the total work across the entire BFS for teleportations remains bounded and efficient.

---

### 💡 Quick Reference Tip

> Treat **Primes** as "Gateways." The first time you land on a prime gateway, you open the doors to all its multiples across the entire array. Once those doors are open, you never need to "open" that specific prime's doors again.

*/