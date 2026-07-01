class Solution {
public:
   bool isvalid(string &s){
     if(s.length()>3||s.empty()) return false;
    int n=s.length();
        string temp="";
        int num=0;
    for(int i=0;i<n;i++){
      num=num*10+(s[i]-'0');
      temp+=s[i];
    }
     if(temp.length()>1&&temp[0]=='0') return false;
    if(!(num>=0&&num<=255)) return false;

    return true;
   }
    void solve(string &s,int idx,vector<string>&ans,int dots,string curr){
        int n=s.length();
        if(idx==n&&dots==4){
            curr.pop_back();
            ans.push_back(curr);
            return ;
        }
        if(dots>=4) return ;
          for(int i=1;i<=3&&i+idx<=n;i++){
            string temp=s.substr(idx,i);
            if(isvalid(temp)){
              solve(s,i+idx,ans,dots+1,curr+temp+'.');
            }
          }



    }
    vector<string> restoreIpAddresses(string s) {
           vector<string>ans;
           int n=s.length();
        //    if(n<3||n>12) return ans;
           solve(s,0,ans,0,"");
           return ans;

    }
};