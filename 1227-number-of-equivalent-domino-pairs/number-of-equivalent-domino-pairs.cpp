class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        unordered_map<int,int>seen;
        int  cnt = 0;
        int m = dominoes.size();


        for(auto&it : dominoes){
            int a = min(it[0],it[1]);
            int b = max(it[0],it[1]);
            int key = b*10+a;
            if(seen.count(key))
                cnt+=seen[key];
            seen[key]++;
        }
        return cnt;


        
    }
};