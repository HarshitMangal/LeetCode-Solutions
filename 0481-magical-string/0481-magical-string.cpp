class Solution {
public:
    int magicalString(int n) {
           
           string s="122";
           int i=2;
           int num=1;
           while(s.length()<n){
            int cnt=s[i]-'0';
            for(int j=0;j<cnt;j++){
               s+=char(num+'0');
                }
                num=(3-num);
                i++;
           }
           int ans=0;
           for(int i=0;i<n;i++){
              if(s[i]=='1'){
                ans++;
              }
           }
           return ans;
    }
};