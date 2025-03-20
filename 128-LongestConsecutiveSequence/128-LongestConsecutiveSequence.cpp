class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int sequence = 1;
        int maxSequence = 1;
        // 0 0 1 2 3 4 5 6 7 8
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])continue;
            if(nums[i]+1==nums[i+1]){
                sequence++;
            }
            else{
                maxSequence = max(maxSequence,sequence);
                sequence = 1;
            }

        }
        maxSequence = max(maxSequence,sequence);
        return maxSequence;

    }
};