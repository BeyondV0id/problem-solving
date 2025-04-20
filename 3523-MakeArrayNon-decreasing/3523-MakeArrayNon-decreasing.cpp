// Last updated: 4/20/2025, 11:56:20 AM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> stk;

        for (int num : nums) {
            while (!stk.empty() && stk.top() > num) {
                int top = stk.top();
                stk.pop();
                num = max(top, num);
            }
            stk.push(num);
        }

        return stk.size();
    }
};
