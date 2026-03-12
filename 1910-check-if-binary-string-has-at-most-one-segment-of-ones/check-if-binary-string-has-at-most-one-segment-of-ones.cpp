class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seen1 = false;
        bool seen0 = false;

        for (char& it : s) {
            if (it == '0') {
                seen0 = true;
            }
            if (it == '1') {
                if (seen0) {
                    return false;
                }
                seen1 = true;
            }
        }

        return true;
    }
};