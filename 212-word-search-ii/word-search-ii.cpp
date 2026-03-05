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
    void dfs(vector<vector<char>>& board, TrieNode* node, int r, int c,
             vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a'])
            return;

        node = node->children[ch - 'a'];

        if (node->isEnd) {
            res.push_back(node->word);
            node->isEnd = false;
        }

        board[r][c] = '#';

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size())
                dfs(board, node, nr, nc, res);
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie trie;

        for (string& w : words)
            trie.insert(w);

        vector<string> res;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, trie.root, i, j, res);
            }
        }

        return res;
    }
};
// @leet end
