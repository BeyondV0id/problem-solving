// Last updated: 5/2/2025, 11:16:50 AM
class Solution {
public:
    int myAtoi(string s) {
       int a=0;
       bool sign =false;
       int s1=1;
       bool space=false;
       long long num=0;
       for(int i=0; i<s.size(); i++){
            if(s[i]==' ' && space==false){
                continue;
            }
            if(s[i]>='0'&& s[i]<='9'){
                if(num>(INT_MAX -(s[i]-'0'))/10){
                   return s1==1?INT_MAX:INT_MIN;
                }
               
                num=num*10+(s[i]-'0');
                sign=true;
                space=true;
            }
           
           
            else if((s[i]=='+'|| s[i]=='-') &&  sign==false){
                if(s[i]=='-'){
                    s1=-1;
                }
                sign=true;
                space=true;
            }
            else{
               break;
            }
           
          
   
       }
      
       long long ans=s1*num;
       return ans;
      
    }
};