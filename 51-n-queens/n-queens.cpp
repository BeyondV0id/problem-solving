// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<vector<string>> res;
    vector<string> board;
    unordered_set<int> col;
    unordered_set<int> negDiagnol;
    unordered_set<int> posDiagnol;
    void backtrack(int n, int r) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col.count(c) || negDiagnol.count(r - c) ||
                posDiagnol.count(r + c))
                continue;
            col.insert(c);
            negDiagnol.insert(r - c);
            posDiagnol.insert(r + c);
            board[r][c] = 'Q';
            backtrack(n, r + 1);
            board[r][c] = '.';
            col.erase(c);
            negDiagnol.erase(r - c);
            posDiagnol.erase(r + c);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(n, 0);
        return res;
    }
};
// @leet end
