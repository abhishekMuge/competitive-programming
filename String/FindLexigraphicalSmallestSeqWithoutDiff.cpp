#include <bits/stdc++.h>

using namespace std;

std::vector<int> findExactSubsequence(std::string word1, std::string word2) {
    std::vector<int> seq;

    int i = 0;

    for(int j = 0; j < word2.length(); j++) {
        while(i < word1.length() && word1[i] != word2[j]) {
            i++;
        }
        if(i == word1.length()) return {};
        seq.push_back(i);
        i++;
    }
    return seq;
}

int main() {
    std::string word1 = "abacaba";
    std::string word2 = "aca";
    
    std::vector<int> result = findExactSubsequence(word1, word2);
    
    // Output the resulting indices
    for (int idx : result) {
        std::cout << idx << " ";
    }
    // Output for this example: 0 3 4 (forms "a", "c", "a")
    return 0;
}