class Solution {
public:
    bool canAliceWin(int n) {
        bool isAliceTurn = false;
        int stonesToRemove = 10;

        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            isAliceTurn = !isAliceTurn;
        }

        return isAliceTurn; // Alice wins if it was her turn last
    }
};
