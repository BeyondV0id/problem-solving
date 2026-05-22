// @leet imports start
#include <bits/stdc++.h>
#include <climits>
using namespace std;
// @leet imports end

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
      int n  = nums.size();
      unordered_map<int,vector<int>>occurs;
      for(int i = 0;i < n; i++){
        occurs[nums[i]].push_back(i);
      }
      vector<int>res;

      for(int i = 0;i < (int)queries.size(); i++){
        int occurence = queries[i];
        int size = occurs[x].size();
        if(occurs.count(x) && occurence <= size){
          int indx = occurs[x][occurence-1];
          res.push_back(indx);
        }
        else{
          res.push_back(-1);
        }
      }
      return res;
    }
};
