class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        long long cnt = 1;

        for (int r = 1; r < n; r++) {
            if (nums[r] == nums[r - 1]) {
                l = r;
            }
            cnt += (r - l + 1);
        }

        return cnt;
    }
};
