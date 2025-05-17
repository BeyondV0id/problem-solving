
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq; 


        for (int num : nums) {
            freq[num]++;
        }


        int i = 0;
        for (int j = 0; j < freq[0]; j++) nums[i++] = 0;
        for (int j = 0; j < freq[1]; j++) nums[i++] = 1;
        for (int j = 0; j < freq[2]; j++) nums[i++] = 2;
    }
};