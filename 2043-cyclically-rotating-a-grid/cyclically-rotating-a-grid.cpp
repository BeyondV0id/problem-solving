// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

class Solution {
  public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {

      int m = grid.size();
      int n = grid[0].size();

      int totalLayers = min(m,n)/2;

      int layer = 0;

      while(layer < totalLayers){

        int top = layer;
        int bottom = grid.size()-1-layer;
        int left = layer;
        int right = grid[0].size()-1-layer;

        vector<int>arr;

        //topRow(left)
        for(int i = left;i <= right; i++){
          arr.push_back(grid[top][i]);
        }

        //rightCol(down)
        for(int i = top + 1; i <= bottom - 1;i++){
          arr.push_back(grid[i][right]);
        }

        //bottomRow
        for(int i = right;i >= left; i--){
          arr.push_back(grid[bottom][i]);
        }

        //leftCol
        for(int i = bottom - 1; i >= top + 1;i--){
          arr.push_back(grid[i][left]);
        }

        int len = arr.size();

        int rot = k % len;

        vector<int>rotated(len);

        for(int i = 0; i < len; i++){
          rotated[i] = arr[(i + rot) % len];
        }

        int idx = 0;

        //topRow(left)
        for(int i = left;i <= right; i++){
          grid[top][i] = rotated[idx++];
        }

        //rightCol(down)
        for(int i = top + 1; i <= bottom - 1;i++){
          grid[i][right] = rotated[idx++];
        }

        //bottomRow
        for(int i = right;i >= left; i--){
          grid[bottom][i] = rotated[idx++];
        }

        //leftCol
        for(int i = bottom - 1; i >= top + 1;i--){
          grid[i][left] = rotated[idx++];
        }

        layer++;
      }

      return grid;
    }
};