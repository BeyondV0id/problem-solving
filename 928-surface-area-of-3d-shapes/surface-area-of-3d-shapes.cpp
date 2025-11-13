// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  public:
    int surfaceArea(vector<vector<int>> &grid) {
      int tsa = 0;
      for(int r = 0;r < (int)grid.size();r++){
        for(int c = 0; c < (int)grid.size();c++){
          int height = grid[r][c];
          if(height == 0)continue;
          int hiddenHeight = 2*(height-1);
          tsa += 6*height - hiddenHeight;
          for(auto  &[rr,cc] : dirs){
            int dr = rr + r;
            int dc = cc + c;
            if(dr >=0 && dr < (int)grid.size() && dc >= 0 && dc < (int)grid.size()){
              tsa -= min(height, grid[dr][dc]);
            }
          }
        }
      }
      return tsa;
    }
};
// @leet end

