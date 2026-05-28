class TrieNode {
public:
    TrieNode* children[26];
    int best_index;

    TrieNode() {
        // Initialize all child pointers to nullptr
        std::fill(std::begin(children), std::end(children), nullptr);
        best_index = -1;
    }
};

class Solution {
public:
    std::vector<int> stringIndices(std::vector<std::string>& wordsContainer, std::vector<std::string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        
        // 1. Find the global fallback index (shortest length, earliest index)
        int global_best_idx = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }
        root->best_index = global_best_idx;
        
        // 2. Build the Trie by inserting words backwards
        for (int i = 0; i < wordsContainer.size(); ++i) {
            TrieNode* curr = root;
            const std::string& word = wordsContainer[i];
            
            // Loop from the last character to the first character
            for (auto it = word.rbegin(); it != word.rend(); ++it) {
                int idx = *it - 'a';
                if (curr->children[idx] == nullptr) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
                
                // Update best_index if this node doesn't have one, or if current word is shorter
                if (curr->best_index == -1) {
                    curr->best_index = i;
                } else {
                    int curr_best_len = wordsContainer[curr->best_index].length();
                    if (word.length() < curr_best_len) {
                        curr->best_index = i;
                    }
                    // Sequential loops (0 to N-1) naturally prioritize the earlier index on length ties
                }
            }
        }
        
        // 3. Process Queries
        std::vector<int> ans;
        ans.reserve(wordsQuery.size()); // Optimize memory allocation
        
        for (const std::string& query : wordsQuery) {
            TrieNode* curr = root;
            
            // Search backwards through the query string
            for (auto it = query.rbegin(); it != query.rend(); ++it) {
                int idx = *it - 'a';
                if (curr->children[idx] != nullptr) {
                    curr = curr->children[idx];
                } else {
                    // Match broken: stop searching deeper
                    break;
                }
            }
            // Whatever node we ended up at holds the index of the best match
            ans.push_back(curr->best_index);
        }
        
        return ans;
    }
};

