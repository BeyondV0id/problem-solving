
// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @leet imports end
class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    int countVowelSubstrings(string word) {

        int n = word.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = i; j < n; j++) {
                if (isVowel(word[j])) {
                    st.insert(word[j]);
                } else {
                    break;
                }
                if (st.size() == 5)
                    cnt++;
            }
        }
        return cnt;
    }
};
