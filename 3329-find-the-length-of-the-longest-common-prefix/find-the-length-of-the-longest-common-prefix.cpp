// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end
// @leet start
//

class Solution {
  public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
      unordered_set<int>prefix;

      for(auto x : arr1){
        while(x>0){
          prefix.insert(x);
          x /= 10;
        }
      }
      int res = 0;

      for(int x : arr2){
        while(x>0){
          if(prefix.count(x)){
            res = max(res,(int)to_string(x).size());
          }
          x /= 10;
        }
      }

      return res;
    }
};
