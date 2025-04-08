/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

#include <algorithm> // For std::lower_bound

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())return{};
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        vector<pair<int,int>>ranks;
        int rank = 1;
        ranks.push_back({temp[0],rank});
        for(int i=1;i<arr.size();i++){
            if(temp[i]!=temp[i-1]){
                rank++;
                ranks.push_back({temp[i],rank});
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            auto it = lower_bound(ranks.begin(), ranks.end(), make_pair(arr[i], 0));
            if (it != ranks.end() && it->first == arr[i]) {
                arr[i] = it->second;
            }
        }
        return arr;
        
    }
};
// @lc code=end

