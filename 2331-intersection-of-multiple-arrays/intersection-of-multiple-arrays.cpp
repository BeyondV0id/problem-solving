class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> result;
        int m = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < nums[i].size(); j++)
                seen[nums[i][j]]++;
        for (auto num : seen) {
            if (num.second == m)
                result.push_back(num.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
