// Last updated: 3/30/2025, 9:29:29 AM
class Solution {
public:
    int maximum69Number(int num) {
        int numSize = 0;
        vector<int> nums;
        int temp = num;

        while (temp > 0) {
            int lastDigit = temp % 10;
            nums.push_back(lastDigit);
            temp /= 10;
            numSize++;
        }
        reverse(nums.begin(), nums.end());
        int maxNum = num;
        for (int i = 0; i < numSize; i++) {
            if (nums[i] == 6) {
                nums[i] = 9;
                break;
            }
        }
        temp = 0;
        for(int i=0;i<numSize;i++){
            temp = temp*10+nums[i];
        
        }
        return temp;
    }
};