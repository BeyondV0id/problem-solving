class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        if (nums.empty()) return ans;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx - mn + 1, 0);

        for (int num : nums) {
            freq[num - mn] = 1;
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) {
                ans.push_back(i + mn);
            }
        }

        return ans;
    }
};