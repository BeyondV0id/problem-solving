// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->word = word;
    }
};

class Solution {
private:
    void dfs(string &s, TrieNode* node, int index,
             vector<string>& path, vector<string>& result) {

        if (index == (int)s.size()) {
            string res = "";
            for (int i = 0; i < (int)path.size(); i++) {
                res += path[i];
                if (i != (int)path.size() - 1)
                    res += " ";
            }
            result.push_back(res);
            return;
        }

        TrieNode* curr = node;

        for (int i = index; i < (int)s.size(); i++) {
            int indx = s[i] - 'a';

            if (curr->children[indx] == nullptr)
                break;

            curr = curr->children[indx];

            if (curr->isEnd) {
                path.push_back(curr->word);
                dfs(s, node, i + 1, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> path;

        Trie trie;
        for (auto &word : wordDict)
            trie.insert(word);

        dfs(s, trie.root, 0, path, result);

        return result;
    }
};
// @leet end

