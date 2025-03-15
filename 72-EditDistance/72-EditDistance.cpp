class Solution {
public:
    int minDistance(string word1, string word2) {
        /*define m*n matrix for dp tabulation
        m is the word2 length
        n is word1 length
        base case:
        if word 2 is 0 means we have to delete n words dp[0][n] = n
        if word 1 is 0 means we have to insert m words dp[m][0] = m
        if same words just check dp[m-1][n-1] car and ckr check ca adn ck
        if the letters are different :
        delete word1 word:example  word1 = cart, word2 = car , delete word1[n] so compare next [m][n-1]
        if we want to insert in word1: ex: word1 = car word2 =cart then it becomes cart and cart compare car and cart for next [m-1][n]
        if we want to replace , replace and compare [m-1][n-1]
        */

        int n = word1.length();//for word1
        int m = word2.length();//for word2
        //intialize dp[m][n]
        vector <vector<int>> dp(m+1,  vector<int>(n+1,0));

        //base cases:
        for(int i = 0;i<m+1;i++) dp[i][0] = i;//filling word2(if word1 is empty we have to insert i'letters to word1)
        for(int j = 0;j<n+1;j++)dp[0][j] = j;//filling word1(if word2 is empty we have to delete j'letters in word1)
        //filling dp table
        for(int i = 1;i<m+1;i++){
            for(int j = 1;j<n+1;j++){
                if(word1[j - 1]  ==  word2[i - 1]){//if (word1[j - 1] == word2[i - 1]) 
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i - 1][j],   // Insert (into word1)
                    dp[i - 1][j - 1], // Replace
                    dp[i][j - 1]});  // Delete (from word1)

                }
            }
        }

        return dp[m][n];
    }
};