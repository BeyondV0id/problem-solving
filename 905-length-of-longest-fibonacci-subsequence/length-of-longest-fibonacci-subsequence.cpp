/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<int,int>getIndx;
    vector<vector<int>>dp;
    int findmax(vector<int>&arr, int prev1,int prev2){

        if(dp[prev1][prev2]!=-1)
            return dp[prev1][prev2];

        int nextval = arr[prev1]+arr[prev2];
        if(!getIndx.count(nextval))
            return dp[prev1][prev2] = 2;

        int nextindx = getIndx[nextval];
        dp[prev1][prev2] = 1+findmax(arr,prev2,nextindx);
        return dp[prev1][prev2];
        
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n,vector<int>(n,-1));
        for(int i = 0;i<n;i++)
            getIndx[arr[i]] = i;

        int maxlen = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                maxlen = max(maxlen,findmax(arr,i,j));

        return maxlen > 2 ? maxlen:0;

        
    }
};
// @lc code=end
