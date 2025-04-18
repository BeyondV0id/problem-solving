// Last updated: 4/18/2025, 8:15:05 AM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return abs(nums[0]);
        int maxsum = nums[0];
        int newmax = nums[0];
        int minsum = nums[0];
        int newmin = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < n; i++) {

            newmax = max(nums[i], nums[i] + newmax);
            maxsum = max(newmax, maxsum);

            newmin = min(nums[i], nums[i] + newmin);
            minsum = min(newmin, minsum);

            globalMax = max(abs(minsum), maxsum);
        }
        return globalMax;
    }
};