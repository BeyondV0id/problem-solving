#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    queue<int> rq, cq, cntq;

    void explore_neighbours(int r, int c, int cnt, vector<vector<int>>& grid, int n) {
        for (int d = 0; d < 8; d++) {
            int rr = r + dr[d];
            int cc = c + dc[d];
            if (rr >= 0 && rr < n && cc >= 0 && cc < n && grid[rr][cc] == 0) {
                rq.push(rr);
                cq.push(cc);
                cntq.push(cnt + 1);
                grid[rr][cc] = 1;
            }
        }
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        grid[0][0] = 1; // mark visited
        rq.push(0);
        cq.push(0);
        cntq.push(1);

        while (!rq.empty()) {
            int r = rq.front(); rq.pop();
            int c = cq.front(); cq.pop();
            int cnt = cntq.front(); cntq.pop();

            if (r == n - 1 && c == n - 1)
                return cnt;

            explore_neighbours(r, c, cnt, grid, n);
        }
        return -1;
    }
};
