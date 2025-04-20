// Last updated: 4/20/2025, 12:07:01 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> s;

        for (int num : nums) {
            while (!s.empty() && s.top() > num) {
                int top = s.top();
                s.pop();
                num = max(top, num);
            }
            s.push(num);
        }

        return s.size();
    }
};
