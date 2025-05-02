// Last updated: 5/2/2025, 11:11:09 AM
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
            if (isdigit(s[i])) {
                convert(s[i]);
                seenNum = true;

                if (sign == 1 && result > INT_MAX)
                    return INT_MAX;
                if (sign == -1 && -result < INT_MIN)
                    return INT_MIN;

            } else {
                if (s[i] == ' ' && !seenNum && !seenSign) {
                    continue;
                }

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

        return static_cast<int>(result);
    }
};
