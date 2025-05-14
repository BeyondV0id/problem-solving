class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat[0].size();
        for(int i = 0;i<n;i++){
            int left = mat[i][i];
            int right = mat[i][n-i-1];
            sum += left;
            if(i!=n-i-1){
                sum+=right;
            }
        }
        return sum;
        


    }
};