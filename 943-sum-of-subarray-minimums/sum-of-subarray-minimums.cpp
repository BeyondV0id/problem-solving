class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        stack<int> s1, s2;
        
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            if (!s1.empty()) {
                prev[i] = s1.top();
            }
            s1.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                next[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans = (ans + (long long)arr[i] * left % MOD * right % MOD) % MOD;
        }
        
        return ans;
    }
};