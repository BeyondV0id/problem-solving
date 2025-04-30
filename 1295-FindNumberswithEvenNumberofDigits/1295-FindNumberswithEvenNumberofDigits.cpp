// Last updated: 4/30/2025, 1:28:08 PM
class Solution {
private:
    int numsDigit(int n){
        return floor(log10(n))+1;
    }
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int num:nums){
            if(numsDigit(num)%2==0)cnt++;

        }
        return cnt;

        
    }
};