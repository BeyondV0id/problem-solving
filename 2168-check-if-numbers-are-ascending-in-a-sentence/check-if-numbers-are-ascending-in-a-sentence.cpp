class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        string number = "";
        bool perfect = true;

        for (auto& c : s) {

            if (isdigit(c))
                number += c;
            else {
                if (!number.empty()) {
                    int cur = stoi(number);
                    if (prev >= cur){
                        perfect = false;
                        break;
                    }
                    number = "";
                    prev = cur;
                }
            }
        }
        if (!number.empty()) {
            int cur = stoi(number);
            if (prev >= cur)
                perfect = false;
        }
        return perfect;
    }
};