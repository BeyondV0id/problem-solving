class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            if(i == 0 || nums[i-1] != nums[i]){
                cnt[nums[i]]++;
            }
        }
        int res = 0;

        for(auto it : cnt){
            if(it.second == 1)res++;
        }
        return res;
    }
};