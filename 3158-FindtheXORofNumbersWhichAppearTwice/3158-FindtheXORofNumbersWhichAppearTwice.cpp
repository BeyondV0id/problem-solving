#include <vector>
#include <queue>

class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) {
        std::vector<int> freq(51, 0);
        std::queue<int> q;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int result = 0;

        for (int i = 1; i < freq.size(); i++) {
            if (freq[i] == 2) {
                result^=i;
                
            }
        }


        return result;
    }
};
