class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIndx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - lastIndx -1 < k && lastIndx != -1)
                    return false;
                lastIndx = i;
            }
        }
        return true;
    }
};