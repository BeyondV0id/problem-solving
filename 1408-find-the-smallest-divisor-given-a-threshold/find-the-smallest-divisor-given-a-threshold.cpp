class Solution {
public:
    
    int getSum(vector<int>& nums, int d) {
        int sum = 0;

        for (int x : nums) {
            sum += (x + d - 1) / d;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = getSum(nums, mid);

            if (sum <= threshold) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};