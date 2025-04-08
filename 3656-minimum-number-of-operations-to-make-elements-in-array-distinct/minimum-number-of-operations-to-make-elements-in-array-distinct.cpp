class Solution {
private:
    void removeElements(vector <int>& nums) {
        int size = nums.size();
        int limit = min(3,size);
        for (int i = 0; i < limit; i++) {
            nums.erase(nums.begin());
        }
    }

    bool notUnique(vector<int>& nums) {
        unordered_set<int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i]))
                return true;
            freq.insert(nums[i]);
        }
        return false;
    }

public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (notUnique(nums)) {
            removeElements(nums);
            cnt++;
        }
        return cnt;
    }
};