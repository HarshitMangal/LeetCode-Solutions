class Solution {
public:
    string largestEven(string s) {
        int n=s.length();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==0){
                ans=s.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};