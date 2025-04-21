class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for (int c = 2; c < n - 1; c++) {
        unordered_map<int, int> sumcnt;
        for (int a = 0; a < c; a++) {
            for (int b = a + 1; b < c; b++) {
                int sum = nums[a] + nums[b];
                sumcnt[sum]++;
            }
        }
        for (int d = c + 1; d < n; d++) {
            int diff = nums[d] - nums[c];
            if (sumcnt.count(diff)) {
                cnt += sumcnt[diff];
            }
        }
    }

    return cnt;
}

};