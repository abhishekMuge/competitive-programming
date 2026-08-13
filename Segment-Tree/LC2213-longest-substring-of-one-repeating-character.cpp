#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int maxLength = 1;
    int prefLength = 1;
    int suffLength = 1;
    char leftChar;
    char rightChar;
};

class SegmentTree
{
private:
    int n;
    vector<Node> tree;
    string s;

    Node merge(const Node &left, const Node &right, int leftLen, int rightLen)
    {
        Node parent;
        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;

        // 1. Combine boundary-spanning run if characters match
        int bridge = 0;
        if (left.rightChar == right.leftChar)
        {
            bridge = left.suffLength + right.prefLength;
        }

        parent.maxLength = max({left.maxLength, right.maxLength, bridge});

        // 2. Prefix length calculation
        if (left.prefLength == leftLen && left.rightChar == right.leftChar)
        {
            parent.prefLength = left.prefLength + right.prefLength;
        }
        else
        {
            parent.prefLength = left.prefLength;
        }

        // 3. Suffix length calculation
        if (right.suffLength == rightLen && left.rightChar == right.leftChar)
        {
            parent.suffLength = right.suffLength + left.suffLength;
        }
        else
        {
            parent.suffLength = right.suffLength;
        }

        return parent;
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        int leftLen = mid - start + 1;
        int rightLen = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], leftLen, rightLen);
    }

    void update(int node, int start, int end, int idx, char val)
    {
        if (start == end)
        {
            s[idx] = val;
            tree[node] = {1, 1, 1, val, val};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        int leftLen = mid - start + 1;
        int rightLen = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], leftLen, rightLen);
    }

public:
    SegmentTree(const string &str)
    {
        s = str;
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void updateChar(int idx, char val)
    {
        update(1, 0, n - 1, idx, val);
    }

    int getMaxRepeatingLength()
    {
        return tree[1].maxLength;
    }
};

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        SegmentTree st(s);
        vector<int> result;
        int k = queryCharacters.length();

        for (int i = 0; i < k; ++i)
        {
            st.updateChar(queryIndices[i], queryCharacters[i]);
            result.push_back(st.getMaxRepeatingLength());
        }

        return result;
    }
};