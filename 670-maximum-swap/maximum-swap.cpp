class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        bool swapped = false;
        for (int i = 0; i < s.size() - 1 && !swapped; i++) {
            int max_indx = i;
            for (int j = i + 1; j < s.size(); j++) {
                bool foundGreater =  s[j] > s[i] && s[j] >= s[max_indx];
                if (foundGreater) {
                    max_indx = j;
                }
            }
            if (i != max_indx) {
            swap(s[i], s[max_indx]);
            swapped = true;
        }
        }
        int result = stoi(s);
        return result;
    }
};