#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void backvers(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void nextPermutation(vector<int> &nums)
    {
        int idx = -1, length = nums.size();
        for (int i = length - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            backvers(nums, 0, length - 1);
            return;
        }

        backvers(nums, idx + 1, length - 1);
        int newj = -1;
        for (int j = idx + 1; j < length; j++)
        {
            if (nums[idx] < nums[j])
            {
                newj = j;
                break;
            }
        }

        swap(nums[idx], nums[newj]);
    }
};

// string version

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(
        const string &s,
        vector<bool> &used,
        string &current,
        vector<string> &result)
    {
        // Base case: permutation complete
        if (current.size() == s.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            // Skip already used characters
            if (used[i])
                continue;

            // Skip duplicates
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
            {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(s[i]);

            // Explore
            backtrack(s, used, current, result);

            // Un-choose
            current.pop_back();
            used[i] = false;
        }
    }

    vector<string> permuteUnique(string s)
    {
        vector<string> result;
        string current;
        vector<bool> used(s.size(), false);

        sort(s.begin(), s.end()); // required for duplicate handling
        backtrack(s, used, current, result);

        return result;
    }
};
