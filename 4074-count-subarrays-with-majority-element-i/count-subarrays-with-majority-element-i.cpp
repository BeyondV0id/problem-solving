class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();


        vector<int>map(n,-1);
        
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                map[i] = 1;
            }
        }


        int res = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += map[j];
                if(sum > 0){
                    res++;
                }
            }
        }

        return res;
    }
};