class Solution {
private:
    vector<int> arr;
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        for (auto& row : grid)
            for (auto& val : row)
                arr.push_back(val);
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int target = arr[n / 2];
        int cnt = 0;
        for (auto& row : grid)
            for (auto& val : row) {
                if (abs(target - val) % x == 0)
                    cnt += abs((target - val) / x);
                else
                    return -1;
            }
        return cnt;
    }
};
// @lc code=end
