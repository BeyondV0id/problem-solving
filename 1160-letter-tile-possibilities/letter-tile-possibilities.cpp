/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
private:
    int backtrack(string tiles,vector<bool>&visited,int n){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            if(i > 0 && tiles[i] == tiles[i-1] && visited[i-1] == false)continue;
            visited[i] = true;
            cnt += 1+backtrack(tiles,visited,n);
            visited[i] = false;
        }
        return cnt;


    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int len = tiles.size();
        vector<bool>visited(len);
        return backtrack(tiles,visited,len);
    }
};
// @lc code=end

