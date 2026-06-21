#include<bits/stdc++.h>

using namespace std;

string BWTEncode(const string& s) {
    int n = s.size();

    vector<string> rotations;
    for(int i = 0; i < n; i++) {
        string rotation = s.substr(i) + s.substr(0, i);
        rotations.push_back(rotation);
    }

    sort(rotations.begin(), rotations.end());

    string result;
    for(const auto& row: rotations) {
        result += row.back();
    }
    return result;
}

string BWTDecoding(const string& s) {
    int n = s.size();

    vector<string> table(n, "");

    for (int step = 0; step < n; step++)
    {
        for (int i = 0; i < n; i++)
        {
            table[i] = s[i] + table[i];
        }

        sort(table.begin(), table.end());
    }

    for (const string& row : table)
    {
        if (!row.empty() && row.back() == '$')
            return row;
    }

    return "";
}


int main()
{
    string s = "BANANA$";

    cout << BWTEncode(s) << endl;

    return 0;
}