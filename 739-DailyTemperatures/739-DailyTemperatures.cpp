// Last updated: 3/27/2025, 6:22:38 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[st.top()]<temp[i]){
          int prev_index = st.top(); // Get previous day index
                st.pop();
                ans[prev_index] = i - prev_index;
            }
           st.push(i);
        }
        return ans;
    }
};