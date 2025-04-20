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
