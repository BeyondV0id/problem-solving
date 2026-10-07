class Solution {
    unordered_set<string> st;
    string curr;
    int n;
    int maxLen;

    void solve(const string& s, int i, int count) {
        if (count < 0)
            return;

        if (i == n) {
            if (count == 0) {
                if (curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                    st.insert(curr);
                }
                else if (curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(s, i + 1, count);
            curr.pop_back();
        }
        else {
            curr.push_back(s[i]);

            solve(s, i + 1,
                  count + (s[i] == '(' ? 1 : -1));

            curr.pop_back();

            solve(s, i + 1, count);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        maxLen = 0;
        curr.clear();
        st.clear();

        solve(s, 0, 0);

        return vector<string>(st.begin(), st.end());
    }
};