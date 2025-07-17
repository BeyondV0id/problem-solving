/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<pair<int,int>>directions = {
        {-1,0},{0,1},{1,0},{0,-1}
    };
    bool found = false;
    void dfs(vector<vector<char>>& board, string word,int r,int c,int R,int C,int stepCnt){
        if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] != word[stepCnt])
            return;
        if(stepCnt == word.size()-1)
            found = true;
        char temp = board[r][c];
        board[r][c] = '*';
        for(auto[dr,dc] : directions){
            int newR = r + dr;
            int newC = c + dc;
            dfs(board,word,newR,newC,R,C,stepCnt+1);
        }
        board[r][c] = temp;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int R = board.size();
        const int C = board[0].size();
        int stepCnt = 0;
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++){
                if(board[r][c] == word[0]){
                    dfs(board,word,r,c,R,C,0);
                    if(found)return true;
                }
            }
        }
        return false;
        
    }
};
// @lc code=end

