class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n+1;
        vector<int> freq(size,0);
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                freq[grid[i][j]]++;
            }
        }
        int miss = -1,twice = -1;
        for(int i = 1;i<freq.size();i++){
            if(freq[i]==2){
                twice = i;
            }
            if(freq[i] == 0){
                miss = i;
            }
        }
        return {twice,miss};
        
    }
};