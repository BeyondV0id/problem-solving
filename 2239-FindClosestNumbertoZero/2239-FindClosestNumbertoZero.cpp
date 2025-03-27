// Last updated: 3/27/2025, 3:40:56 PM
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int smol=100000;
        int smol_num=-100000;
        for (int& x: nums){
            if (abs(x)<smol){
                smol=abs(x);
                smol_num=x;
            }
            else if (abs(x)==smol){
                if (x>smol_num){
                    smol_num=x;
                }
            }
        }
        return smol_num;
    }
};