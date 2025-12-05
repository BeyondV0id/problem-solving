// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  private:
    int cnt = 0;
    unordered_set<int>col;
    unordered_set<int>posDiag;//(r+c)
    unordered_set<int>negDiag;//(r-c)
    void backtrack(int n, int r){
      if(r == n){
        cnt++;
        return;
      }
      for(int c = 0; c < n; c++){
        if(col.count(c) || posDiag.count(r+c) 
            || negDiag.count(r-c))
          continue;
        col.insert(c);
        posDiag.insert(r+c);
        negDiag.insert(r-c);
        backtrack(n,r+1);
        col.erase(c);
        posDiag.erase(r+c);
        negDiag.erase(r-c);
      }
    }
  public:
    int totalNQueens(int n) {
      backtrack(n,0);
      return cnt;
    }
};
// @leet end

