// Last updated: 5/2/2025, 11:21:04 AM
class Solution {
private:
    long result = 0;
    int sign = 1;
    bool seenSign = false;
    bool seenNum = false;

    void convert(char c) { result = result * 10 + (c - '0'); }

public:
    int myAtoi(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            while (i < n && s[i] == ' ' && !seenNum && !seenSign) {
                i++;
            }
            if (isdigit(s[i])) {
                convert(s[i]);
                seenNum = true;
                if (result > INT_MAX) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

            } else {

                if ((s[i] == '+' || s[i] == '-') && !seenNum && !seenSign) {
                    sign = (s[i] == '+') ? +1 : -1;
                    seenSign = true;
                }

                else {
                    break;
                }
            }
        }

        if (!seenNum)
            return 0;

        result = result * sign;

        if (result >= INT_MAX)
            return INT_MAX;
        if (result <= INT_MIN)
            return INT_MIN;
        return result;
    }
};
