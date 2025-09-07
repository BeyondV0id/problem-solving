class Solution {
public:
    vector<int> sumZero(int n) {
        int flag = 0;
        if (n % 2 != flag)
            flag = 1;
        vector<int> res;
        for (int i = 1; i <= n / 2; i++){
            res.push_back(i);
            res.push_back(-i);
        }
        if(flag)
            res.push_back(0);
        return res;
    }
};