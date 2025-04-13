
class Solution {
    public:
        string smallestPalindrome(string s) {
            int freq[26] = {0};
            for(int i=0;i<s.size();i++){
                char c = s[i];
                freq[c-'a']++;
                
            }
            string l = "",m = "",r = "";
            for(int i = 0;i<26;i++){
                if(freq[i]>0){
                if(freq[i]%2!=0){
                    char c ='a'+i;
                    m+=c;
                }
                for(int j = 0;j<freq[i]/2;j++){
                    l+='a'+i;
                }
            }

            }
            r = l;
            reverse(r.begin(),r.end());
            string result = l+m+r;
            return result;




        }
    };