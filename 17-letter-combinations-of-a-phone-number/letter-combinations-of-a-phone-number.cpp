class Solution {
private:
    unordered_map<char, string> keypad = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    vector<string> res;
    string a = "";

    void backtrack(string digits, int i) {
        if (i == digits.size()) {
            res.push_back(a);
            return;
        }

        for (auto ch : keypad[digits[i]]) {
            a += ch;
            backtrack(digits, i + 1);
            a.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0);

        return res;
    }
};