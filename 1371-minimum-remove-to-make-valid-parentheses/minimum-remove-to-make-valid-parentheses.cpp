class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>stk;
        int n = s.size();

        unordered_set<int>add;

        for(int i = 0; i < n; i++){
            if (s[i] == '('){
                stk.push(i);
            }
            else if(s[i] == ')'){
                if(!stk.empty()){
                    stk.pop();
                }
                else{
                    add.insert(i);
                }
            }
        }

        while(!stk.empty()){
            add.insert(stk.top());
            stk.pop();
        }
        string ans;

        for(int i = 0; i < n; i++){
            if(!add.count(i)) ans += s[i];
        }


        return ans;     
    }
};