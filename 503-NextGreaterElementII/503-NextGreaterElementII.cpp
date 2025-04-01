// Last updated: 4/1/2025, 6:25:57 PM
/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>result(n,-1);
        for(int i=0;i<2*n;i++){
            int index = i%n;
            while(!st.empty() && nums[st.top()]<nums[index]){
                result[st.top()] = nums[index];
                st.pop();
            }
            st.push(index);
        }
        
        return result;
        
    }
};
// @lc code=end

