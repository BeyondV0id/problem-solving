class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() || needle.empty()){return -1;}
        int l = 0;
        int k = needle.length();
        int r = needle.length()-1;
        while(r<haystack.length()){
            if(haystack.substr(l,k)== needle){
                return l;
            }
            else{
                r++;
                l++;
            }
        }
        return -1;
 }
};