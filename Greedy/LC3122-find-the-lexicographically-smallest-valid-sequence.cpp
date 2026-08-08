#include <bits/stdc++.h>

using namespace std;

// Try -1
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        std::vector<int> rightMatch(n+1, 0);

        int j = m - 1;
        for(int i = n -1; i >= 0; --i) {
            rightMatch[i] = rightMatch[i+1];

            if (j >= 0 && word1[i] == word2[j]){
                rightMatch[i]++;
                j--;
            }
        }

        std::vector<int> seq;
        int i = 0;
        int misUsed = 0;

        for(int j = 0; j < m; ++j) {
            int rem = m - 1 - j;
            bool found = false;

            while(i < n) {
                if(word1[i] == word2[j]) {
                    if(misUsed == 1) {
                        if(rightMatch[i+1] >= rem) {
                            seq.push_back(i);
                            i++;
                            found = true;
                            break;
                        }
                    } else {
                        if(rightMatch[i+1] >= rem -1) {
                            seq.push_back(i);
                            i++;
                            found = true;
                            break;
                        }
                    }
                }
                else if(misUsed == 0) {
                    if(rightMatch[i+1] >= rem) {
                        seq.push_back(i);
                        misUsed = 1;
                        i++;
                        found =true;
                        break;
                    }
                }
                i++;
            }
            if(!found) {
                return {};
            }
        }
        return seq;
    }
};


class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> last(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j -= 1;
            }
        }
        vector<int> res;
        int skip = 0;
        j = 0;
        for (int i = 0; i < n; ++i) {
            if (j == m) break;
            if (word1[i] == word2[j] ||
                (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
                skip += (word1[i] != word2[j] ? 1 : 0);
                res.push_back(i);
                j += 1;
            }
        }
        return j == m ? res : vector<int>();
    }
};