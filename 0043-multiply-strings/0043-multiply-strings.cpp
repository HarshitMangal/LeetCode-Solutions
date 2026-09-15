class Solution {
public:
    string multiply(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        //for negative check
        if(s1[0]=='0'||s2[0]=='0') return "0";
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string temp="";
        vector<int>ans(n+m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val1=s1[i]-'0';
                int val2=s2[j]-'0';
            ans[i+j]+=val1*val2;
            ans[i+j+1]+=ans[i+j]/10;
            ans[i+j]%=10;
            }
        }
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                temp+=(ans[i]+'0');
            }
          //leading zero hata
          int i=0;
          while(i<temp.length()&&temp[i]=='0'){
            i++;
          }
          return temp.substr(i);
    }
};