class Solution {
public:
    string convertDateToBinary(string date) {
        auto toBinary = [&](int num) {
            string res = "";
            while (num > 0) {
                res = char((num % 2) + '0') + res;
                num /= 2;
            }
            return res;
        };

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string y = toBinary(year);
        string m = toBinary(month);
        string d = toBinary(day);

        return y + "-" + m + "-" + d;
    }
};