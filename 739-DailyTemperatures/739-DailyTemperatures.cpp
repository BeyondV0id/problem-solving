// Last updated: 3/27/2025, 6:19:50 PM
class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<int> s;
        for (int i = 0; i < size; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int nextWarmIdx = s.top();
                s.pop();
                result[nextWarmIdx] = i-nextWarmIdx;
            }
            s.push(i);
        }
        return result;
    }
};