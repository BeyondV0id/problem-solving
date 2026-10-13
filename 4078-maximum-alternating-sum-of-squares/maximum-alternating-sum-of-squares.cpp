class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> arr(nums.size());
        for(int i = 0; i < nums.size(); i++){
            arr[i] = (nums[i] > 0 ? nums[i] : -nums[i]);
        }
        sort(arr.begin(), arr.end());

        int l = 0;
        int r = arr.size() - 1;
        long long sum = 0;

        while (l < r) {
            sum += arr[r] * arr[r];
            sum -= arr[l] * arr[l];
            r--;
            l++;
        }

        if (l == r) {
            sum += arr[l] * arr[l];
        }
        return sum;
    }
};