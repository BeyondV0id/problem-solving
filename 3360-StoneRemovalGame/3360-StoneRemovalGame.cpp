class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceWin = false;
        int need = 10;

        while (n >= need)
        {
            n -= need;
            need--;
            aliceWin = !aliceWin;
        }

        return aliceWin;
    }
};
