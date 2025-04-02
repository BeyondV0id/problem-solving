// Last updated: 4/2/2025, 7:17:14 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deadpool; 

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of window bounds
            bool isOutOfBounds = !deadpool.empty() && deadpool.front() <= i - k;
            if (isOutOfBounds) {
                deadpool.pop_front();
            }

            // Remove smaller elements (they can't be max)
            while (!deadpool.empty() && nums[deadpool.back()] < nums[i]) {
                deadpool.pop_back();
            }

            deadpool.push_back(i);

            // If we have a full window, add the max to result
            bool isWindowFilled = i >= k - 1;
            if (isWindowFilled) {
                result.push_back(nums[deadpool.front()]);
            }
        }
        return result;
    }
};
