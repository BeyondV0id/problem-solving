class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        if (nums[n - 1] != n - 1 || nums[n - 2] != n - 1)
            return false;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        return true;
    }
};