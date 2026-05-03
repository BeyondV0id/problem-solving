class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> seen(26, false);

        for (char c : s) freq[c - 'a']++;

        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;

            if (seen[c - 'a']) continue;

            while (!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};