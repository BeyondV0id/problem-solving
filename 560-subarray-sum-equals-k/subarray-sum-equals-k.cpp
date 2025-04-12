class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        long long sum = 0;
        unordered_map<long long, int> preSumMap;
        preSumMap[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            long long rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                cnt += preSumMap[rem];
            }
            preSumMap[sum]++;
        }
        return cnt;
    }
};