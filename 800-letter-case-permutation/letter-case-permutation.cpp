class Solution {
private:
    vector<string> res;
    void solve(string& s, int indx) {
        if (s.size() == indx) {
            res.push_back(s);
            return;
        }
        if (isdigit(s[indx])) {
            solve(s, indx + 1);
        } else {
            //left branch
            solve(s, indx + 1);
            if (islower(s[indx]))
                s[indx] = toupper(s[indx]);
            else
                s[indx] = tolower(s[indx]);
            //right branch
            solve(s, indx + 1);
            if (islower(s[indx]))
               s[indx] =  toupper(s[indx]);
            else
               s[indx] =  tolower(s[indx]);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return res;
    }
};

