class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int ans_len=0;
        string ans_str;
        for(int i=0;i<n;i++){
            int st=i,et=i;
            while(st>=0 && et<n){
                if(s[st]!=s[et]){
                    break;
                }
                
                st--;
                et++;
            }
            
            int m=et-st-1;
            if(m>ans_len){
                ans_len=m;
                ans_str=s.substr(st+1,m);
            }
            
        }
        
        if(n>1){
            for(int i=1;i<n;i++){
                int st=i-1,et=i;
                
                 while(st>=0 && et<n){
                if(s[st]!=s[et]){
                    break;
                }
                
                st--;
                et++;
            }
            
            int m=et-st-1;
            if(m>ans_len){
                ans_len=m;
                ans_str=s.substr(st+1,m);
            }
            
            }
        }
        
        return ans_str;
    }
};