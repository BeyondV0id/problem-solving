// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& image, int r, int c, int oldcolor, int color,
             int R, int C) {
        if (r >= R || c >= C || r < 0 || c < 0)
            return;
        if (image[r][c] != oldcolor)
            return;
        image[r][c] = color;
        for (auto& [dr, dc] : dir) {
            int rr = r + dr;
            int cc = c + dc;
            dfs(image, rr, cc, oldcolor, color, R, C);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int R = image.size();
        int C = image[0].size();
        int oldcolor = image[sr][sc];
        if (oldcolor == color)
            return image;
        dfs(image, sr, sc, oldcolor, color, R, C);
        return image;
    }
};
// @leet end


