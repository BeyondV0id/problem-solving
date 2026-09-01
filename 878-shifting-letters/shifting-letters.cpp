class Solution {
private:
    char shiftChar(char c, int shift) { return (c - 'a' + shift) % 26 + 'a'; }

public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = shifts.size();
        for (int i = n - 1; i > 0; i--) {
            shifts[i - 1] = (shifts[i - 1] + shifts[i]) % 26;
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            res.push_back(shiftChar(s[i], shifts[i]));
        }
        return res;
    }
};