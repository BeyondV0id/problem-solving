class Solution {
private:
    stack<string> strbuild(string s) {
        stack<string> stk;
        if (s.empty())
            return stk;

        int n = s.size();
        int l = 0, r = 0;
        while (r < n) {
            if (s[r] != ' ') {
                r++;
                continue;
            }

            if (l != r) {
                string c = s.substr(l, r - l);
                stk.push(c);
            }
            do {
                r++;
            } while (r < n && s[r] == ' ');
            l = r;
        }

        if (l != r) {
            stk.push(s.substr(l, r - l));
        }

        return stk;
    }

    string stackTostr(stack<string>& stk) {
        string result;
        while (!stk.empty()) {
            result += stk.top() + " ";
            stk.pop();
        }
        if (!result.empty())
            result.pop_back();
        return result;
    }

public:
    string reverseWords(string s) {
        stack<string> builder = strbuild(s);
        return stackTostr(builder);
    }
};
