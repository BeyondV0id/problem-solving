// Last updated: 4/20/2025, 1:48:44 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        //monotonic increasinng stack
        
        stack<int> s;

        for (int num : nums) {
            while (!s.empty() && s.top() > num) {
                int top = s.top();
                s.pop();
                num = top;
            }
            s.push(num);
        }

        return s.size();
    }
};
