#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
//bfs
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int count = 0;

        int dr[2] = {1, 0};
        int dc[2] = {0, 1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'X') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    board[r][c] = '.';

                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        for (int d = 0; d < 2; d++) {
                            int newR = currR + dr[d];
                            int newC = currC + dc[d];

                            if (newR >= 0 && newR < rows && newC >= 0 &&
                                newC < cols && board[newR][newC] == 'X') {
                                board[newR][newC] = '.';
                                q.push({newR, newC});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

/*dfs
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
*/

