class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>seenNumbers;
        int left = 0;
        //int left =0 : erase[left] ,since right-left=k then, erase[right-k]
        for(int right = 0;right<nums.size();right++){
            if(seenNumbers.count(nums[right])){
                return true;
            }
            seenNumbers.insert(nums[right]);
            if(seenNumbers.size()>k){
                seenNumbers.erase(nums[left]);
                left++;
                //or seenNumbers.erase(nums[right-k]);
            }
        }
        return false;
    }
};