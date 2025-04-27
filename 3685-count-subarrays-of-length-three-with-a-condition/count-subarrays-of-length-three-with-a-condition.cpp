class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int size = 3;
        int l = 0, r;
        int cnt = 0;

        for (r = 0; r < nums.size(); r++) {

            int subsize = (r - l + 1);

            if (subsize == size) {
                int mid = l+(r-l)/2;
                if (2*(nums[l] + nums[r])== nums[mid])
                    cnt++;
                l++;
            }
        }
        return cnt;
    }
};