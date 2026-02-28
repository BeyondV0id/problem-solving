// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
struct Trie {
    Trie* child[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
private:
    Trie* root;

    void insert(string word) {
        Trie* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->child[idx] == NULL) {
                curr->child[idx] = new Trie();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    Trie* startsWith(string prefix) {
        Trie* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->child[idx] == NULL)
                return NULL;
            curr = curr->child[idx];
        }
        return curr;
    }

    void dfs(Trie* node, string prefix, vector<string>& result) {
        if (result.size() == 3)
            return;

        if (node->isEnd)
            result.push_back(prefix);

        for (int i = 0; i < 26; i++) {
            if (node->child[i] != NULL) {
                char nextChar = 'a' + i;
                dfs(node->child[i], prefix + nextChar, result);
            }
        }
    }

public:
    Solution() { root = new Trie(); }

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        sort(products.begin(), products.end());

        for (string word : products) {
            insert(word);
        }

        vector<vector<string>> res;

        for (int i = 0; i < searchWord.size(); i++) {

            string prefix = searchWord.substr(0, i + 1);
            Trie* node = startsWith(prefix);

            vector<string> suggestions;

            if (node != NULL) {
                dfs(node, prefix, suggestions);
            }

            res.push_back(suggestions);
        }

        return res;
    }
};
// @leet end