/*
RECURSIVE APPROCH
private:
    int helper(string text1,string text2,int i, int j){
        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }
        else if(text1[i] == text2[j]){
            return 1+helper(text1,text2,i+1,j+1);
        }
        else{
            return max(helper(text1, text2,i+1,j),helper( text1, text2,i,j+1));
        }
    }
};
*/
/*
    0 1 2 3 4 5
      a b c d e
    0 0 0 0 0 0
1 a 0 1 1 1 1 1
2 c 0 1 1 2 2 2
3 e 0 1 1 2 2 3
*/




class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        return dp[m][n];
        
    }
};