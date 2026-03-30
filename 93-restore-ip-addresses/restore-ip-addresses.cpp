class Solution {
    vector<string> res;
    string sub;

    bool isValid(int i, int len, const string& s) {
        string seg = s.substr(i, len);
        if (seg.size() > 1 && seg[0] == '0') return false;
        int val = stoi(seg);
        return val >= 0 && val <= 255;
    }

    void backtrack(const string& s, int indx, int parts) {
        if (parts == 4 && indx == (int)s.size()) {
            res.push_back(sub);
            return;
        }
        if (parts == 4 || indx == (int)s.size()) return;

        for (int len = 1; len <= 3; len++) {
            if (indx + len > (int)s.size()) break;
            if (isValid(indx, len, s)) {
                string seg = s.substr(indx, len);
                string prev = sub;
                sub += (parts == 0 ? "" : ".") + seg;
                backtrack(s, indx + len, parts + 1);
                sub = prev;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {};
        backtrack(s, 0, 0);
        return res;
    }
};