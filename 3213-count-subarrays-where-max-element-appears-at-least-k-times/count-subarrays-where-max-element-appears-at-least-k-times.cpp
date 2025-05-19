class Solution {
private:
    int l=0,r=0;
    long long cnt = 0;
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int seenMaxcnt = 0;
        long long totalSubArrays = (long long)n*(n+1)/2;
        auto max_val = max_element(nums.begin(), nums.end());
        int maxi = *max_val;
        int count_max = count(nums.begin(), nums.end(), maxi);
        if (count_max < k) return 0;

        for(r=0;r<n;r++){
            int num = nums[r];
            if (num == maxi) {
                seenMaxcnt++;
            }
            while (seenMaxcnt >= k) {
                if (nums[l] == maxi)
                    seenMaxcnt--;
                l++;
            }
                cnt += (r-l+1);

        }
        return totalSubArrays - cnt;
    }
};
