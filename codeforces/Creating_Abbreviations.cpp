#include <bits/stdc++.h>

using namespace std;

void solved() {
    int n, m;
    cin >> n >> m;

    unordered_set<char> available;

    // Read ordinary words and record their first characters in uppercase
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        available.insert(toupper(w[0]));
    }

    vector<string> abbrs(m);
    for (int i = 0; i < m; ++i) {
        cin >> abbrs[i];
    }

    vector<bool> created(m, false);
    int created_count = 0;
    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 0; i < m; ++i) {
            if (!created[i]) {
                bool can_form = true;
                
                // Check if every character in the abbreviation is available
                for (char c : abbrs[i]) {
                    if (available.find(c) == available.end()) {
                        can_form = false;
                        break;
                    }
                }

                if (can_form) {
                    created[i] = true;
                    created_count++;
                    available.insert(abbrs[i][0]); // Add its starting letter
                    changed = true;
                }
            }
        }
    }

    if (created_count == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solved();
    }

    return 0;
}