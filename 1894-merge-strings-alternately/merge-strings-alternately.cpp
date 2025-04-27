class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int i=0;
        int maxlen = max(word1.size(),word2.size());
        while(i<maxlen){
            if(i<word1.size())
                merged+=word1[i];
            if(i<word2.size())
                merged+=word2[i];
            i++;
        }
        return merged;
        
    }
};