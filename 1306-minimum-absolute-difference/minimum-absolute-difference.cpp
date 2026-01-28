// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      int minDistance = INT_MAX;
      sort(arr.begin(),arr.end());
      vector<vector<int>>res;
      for(int i = 1; i < (int)arr.size(); i++){
        minDistance = min(minDistance, abs(arr[i] - arr[i-1]));
      }
      for(int i = 1; i < (int)arr.size();i++){
        if(abs(arr[i]-arr[i-1]) == minDistance){
          res.push_back({arr[i-1],arr[i]});
        }
      }
      return res;
    }
};
// @leet end
