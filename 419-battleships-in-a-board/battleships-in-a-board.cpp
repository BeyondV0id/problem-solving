#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
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
