class Solution {
private:
  vector<int>prefixSum; 
  int res = 0;
public:
    int countPartitions(vector<int>& nums) {
      prefixSum.resize(nums.size() + 1);
      prefixSum[0] = nums[0];
      for(int i = 1; i < nums.size();i++){
        prefixSum[i] = nums[i] + prefixSum[i-1];
      }
      for(int i = 0; i < nums.size()-1;i++){
        int leftSub = prefixSum[i];
        int rightSub = prefixSum[nums.size()-1] - prefixSum[i];
        if((leftSub-rightSub)%2 == 0)
          res++;
        cout<<res<<endl;
      }
      return res;
    }
};