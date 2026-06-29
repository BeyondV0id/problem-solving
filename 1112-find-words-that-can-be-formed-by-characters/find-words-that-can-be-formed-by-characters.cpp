class Solution {

private:
    bool check(vector<int>freq,string word){
        for(auto ch : word){
            freq[ch-'a']--;
            if(freq[ch-'a'] < 0)return false;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int>freq(26,0);

        for(auto ch : chars){
            freq[ch-'a']++;
            
        }
        int ans = 0;

        for(auto word : words){
            if(check(freq,word)){
                ans += word.length();
            }
        }
        return ans;
        
    }
};