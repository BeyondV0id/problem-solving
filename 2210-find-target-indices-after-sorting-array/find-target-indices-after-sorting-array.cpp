class Solution {
private:
    vector<int> findpos(vector<int>& nums, int target) {
        int l = 0;
        vector<int>result;
        int r = nums.size() - 1, indx = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                if (nums[m] == target)
                    indx = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (indx == -1)return {};
        while (indx < nums.size() && nums[indx] == target) {
            result.push_back(indx);
            indx++;
        }
        return result;
        
    }

public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        return findpos(nums,target);
    }
};