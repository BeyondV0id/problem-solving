// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        vector<vector<char>> matrix(rows, vector<char>(cols));
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[k++];
            }
        }
        string decrypt;
        for (int col = 0; col < cols; col++) {
            int i = 0, j = col;
            while (i < rows && j < cols) {
                decrypt += matrix[i][j];
                i++;
                j++;
            }
        }
        while (!decrypt.empty() && decrypt.back() == ' ') {
            decrypt.pop_back();
        }
        return decrypt;
    }
};
// @leet end
