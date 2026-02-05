class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size());
        for (int i = 0; i < n; i++) {
            int indx = i;
            if (nums[i] > 0) {
                indx = (nums[i] + i) % n;
            } else if (nums[i] < 0) {
                indx = abs((i + nums[i]%n + n) % n);
            } else {
                indx = i;
            }
            cout<<indx<<endl;
            res[i] = nums[indx];
        }
        return res;
    }
};