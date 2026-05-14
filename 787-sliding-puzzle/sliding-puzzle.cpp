// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    unordered_map<int, vector<int>> movesMap = {{0, {1, 3}},    {1, {0, 2, 4}},
                                                {2, {1, 5}},    {3, {0, 4}},
                                                {4, {1, 3, 5}}, {5, {2, 4}}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string goal = "123450";

        string startState = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                startState += to_string(board[i][j]);
            }
        }

        queue<string> q;

        q.push(startState);
        unordered_set<string> visited;
        visited.insert(startState);

        int moves = 0;

        while (!q.empty()) {

            int n = q.size();
            while (n--) {
                string state = q.front();
                q.pop();


                if (state == goal)
                    return moves;

                int zeroIndx = state.find('0');

                for (int pos : movesMap[zeroIndx]) {
                    string nextState = state;
                    swap(nextState[zeroIndx], nextState[pos]);

                    if (!visited.count(nextState)) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
// @leet end
