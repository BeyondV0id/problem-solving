class Solution {
public:
    int reverseDegree(string s) {

        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            int num = s[i] - 'a';
            cnt += (i + 1) * (26 - num);
        }
        return cnt;
    }
};