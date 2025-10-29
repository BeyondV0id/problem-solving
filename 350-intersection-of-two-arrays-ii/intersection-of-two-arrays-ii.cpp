class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int it : nums1)
            freq[it]++;
        for (int it : nums2) {
            if (freq[it] > 0) {
                res.push_back(it);
                freq[it]--;
            }
        }
        return res;
    }
};