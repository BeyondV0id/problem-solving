// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
  int findMax(vector<vector<int>>& score,int k,int l,int r){
    int maxIndx = -1;
    int maxEl = INT_MIN;
    for(int i = l; i <= r;i++){
      if(score[i][k] > maxEl){
        maxEl = score[i][k];
        maxIndx = i;
      }
    }
    return maxIndx;
  }
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
      int m = score.size();
      int n = score[0].size();
      int indx = 0;
      while(indx < m){
        int maxIndx = findMax(score,k,indx,m-1);
        swap(score[indx], score[maxIndx]);
        indx++;
      }
      return score;
    }
};
// @leet end


