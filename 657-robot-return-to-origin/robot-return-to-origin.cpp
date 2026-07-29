class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> dirs = {
            {'L', -1}, {'R', 1}, {'U', -2}, {'D', 2}};

        int x = 0;
        int y = 0;
        for (auto ch : moves) {
            int dir = dirs[ch];
            if(dir == -1 || dir == 1) x += dir;
            else y += dir;
        }

        if(x == 0 && y == 0)return true;

        return false;
    }
};