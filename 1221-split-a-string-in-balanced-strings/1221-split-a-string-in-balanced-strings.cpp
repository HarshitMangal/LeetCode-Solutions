class Solution {
public:
    int balancedStringSplit(string s) {
         int n=s.length();
         int count=0;
         int ans=0;
         for(int i=0;i<n;i++){
            if(s[i]=='R'){
                count++;
            }
            else {
                count--;
            }
            if(count==0){
                ans++;
            }
         }
         return ans;
    }
};