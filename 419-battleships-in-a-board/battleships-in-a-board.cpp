/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int cnt = 0;
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;
        if (board[r][c] != 'X')
            return;
        board[r][c] = '.';
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        const int rows = board.size();
        const int cols = board[0].size();
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (board[r][c] == 'X') {
                    dfs(board, r, c, rows, cols);
                    cnt++;
                }
        return cnt;
    }
};
// @lc code=end
