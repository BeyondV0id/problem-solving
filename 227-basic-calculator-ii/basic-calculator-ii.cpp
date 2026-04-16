class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int num = 0;
        char op = '+';

        for (int indx = 0; indx < n; indx++) {
            if (isdigit(s[indx])) {
                num = num * 10 + (s[indx] - '0');
            }

            if ((!isdigit(s[indx]) && s[indx] != ' ') || indx == n - 1) {
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                op = s[indx];
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};