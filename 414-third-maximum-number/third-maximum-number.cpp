
class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> seen;

public:
    int thirdMax(vector<int>& nums) {
        for (auto num : nums) {
            if (!seen.count(num)) {
                q.push(num);
                seen.insert(num);
                if (q.size() > 3)
                    q.pop();
            }
        }
        if (q.size() < 3) {
            int max_val = *max_element(seen.begin(), seen.end());
            return max_val;
        }
        return q.top();
    }
};