// Last updated: 4/8/2025, 4:50:15 PM
class Solution {
private:
    void removeElements(vector <int>& nums) {
        int size = nums.size();
        int limit = min(3,size);
        for (int i = 0; i < limit; i++) {
            nums.erase(nums.begin());
        }
    }

    bool isUnique(vector<int>& nums) {
        unordered_set<int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i]))
                return false;
            freq.insert(nums[i]);
        }
        return true;
    }

public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (!isUnique(nums)) {
            removeElements(nums);
            cnt++;
        }
        return cnt;
    }
};