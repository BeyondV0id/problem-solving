class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        unordered_map <int,int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        for (auto& p : freq) {
            if (p.second > nums.size() / k) {
                return false;
            }
        }
        return nums.size() % k == 0;
    }
};