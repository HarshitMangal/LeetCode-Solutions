class Solution {
public:
    string multiply(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(s1[0]-'0'==0||s2[0]-'0'==0) return "0";
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        vector<int>temp(n+m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               temp[i+j]+=(s1[i]-'0')*(s2[j]-'0');
               temp[i+j+1]+=temp[i+j]/10;
               temp[i+j]=temp[i+j]%10;
                
            }
        }
        string ans="";
        for(int i=0;i<temp.size();i++){
            ans+=(temp[i]+'0');
        }
        reverse(ans.begin(),ans.end());
        int j=0;
        while(j<ans.length()&&ans[j]=='0'){
            j++;
        }
        return ans.substr(j);
        
    }
};