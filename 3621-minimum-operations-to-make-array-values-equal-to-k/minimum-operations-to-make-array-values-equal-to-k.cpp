class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k)
                return -1;
            if (nums[i] > k)
                freq[nums[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < 101; i++) {
            if (freq[i] > 0)
                cnt++;
        }
        return cnt;
    }
};