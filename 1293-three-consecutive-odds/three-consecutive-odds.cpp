class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() == 1)
            return false;
        int size = 0;
        for (auto& num : arr) {
            if (num % 2 == 1)
                size++;
            else 
                size=0;
            if (size == 3)
                return true;
        }
        return false;
    }
};