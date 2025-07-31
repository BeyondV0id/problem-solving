#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return true;

        int i = 1;
        while (i < n && nums[i] == nums[i - 1])
            i++;

        if (i == n)
            return true;

        bool isIncreasing = nums[i] > nums[i - 1];

        for (i=1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (isIncreasing && nums[i] < nums[i - 1])
                return false;
            if (!isIncreasing && nums[i] > nums[i - 1])
                return false;
        }

        return true;
    }
};
