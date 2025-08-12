
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int r, int c, int R, int C,
             bool& isSafe, vector<pair<int, int>> &cells) {
        if (r < 0 || c < 0 || r >= R || c >= C || board[r][c] != 'O')
            return;
        if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
            isSafe = true;
        board[r][c] = '#';
        cells.push_back({r, c});

        for (auto [rr, cc] : dr) {
            dfs(board, r + rr, c + cc, R, C, isSafe, cells);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                vector<pair<int, int>> cells;
                bool isSafe = false;
                if (board[r][c] == 'O')
                    dfs(board, r, c, R, C, isSafe, cells);
                char change = isSafe ? 'O' : 'X';
                for (auto [i, j] : cells)
                    board[i][j] = change;
            }
    }
};
// @leet end
