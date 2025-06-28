
class Solution {
    private:
    static bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
    static bool sortByIndx(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>indxPair;
        for(int i = 0;i<nums.size();i++)
            indxPair.push_back({nums[i],i});

        sort(indxPair.begin(),indxPair.end(),sortByValue);
        indxPair.resize(k);
        sort(indxPair.begin(),indxPair.end(),sortByIndx);
        vector<int>result;
        for(const auto&it:indxPair){
            result.push_back(it.first);
        }
        return result;

        
        

    }
};
// @lc code=end

