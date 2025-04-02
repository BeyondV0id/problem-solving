class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deadpool; 

        for (int i = 0; i < nums.size(); i++) {
            bool isOutOfBounds = !deadpool.empty() && k <= i - deadpool.front();
            if (isOutOfBounds) {
                deadpool.pop_front();
            }
            while (!deadpool.empty() && nums[deadpool.back()] < nums[i]) {
                deadpool.pop_back();
            }

            deadpool.push_back(i);
            bool isWindowFilled = i >= k - 1;
            if (isWindowFilled) {
                result.push_back(nums[deadpool.front()]);
            }
        }
        return result;
    }
};
