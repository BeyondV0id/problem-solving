
class Solution {
private:
    int l = 0, r = 0;
    int len = 0;
    int zeroes = 0;
    int maxlen = 0;

public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        while (r < n) {
            int num = nums[r];
            if (num == 0)
                zeroes++;
            while (zeroes > k) {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }

            len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};
