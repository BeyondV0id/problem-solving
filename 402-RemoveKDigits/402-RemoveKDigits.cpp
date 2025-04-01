// Last updated: 4/1/2025, 6:27:45 PM
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)return "0";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){
            int newNum = num[i] - '0';
            while(!st.empty() && ((st.top()-'0')>newNum) && k>0){
                st.pop();  
                k--; 
            }
            st.push(num[i]);
        }
        while(k--)
            st.pop();
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        if(res == "0" || res == "00")return "0";

        while(!res.empty() && res.back()=='0')
            res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};