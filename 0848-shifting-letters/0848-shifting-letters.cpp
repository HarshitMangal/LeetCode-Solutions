class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
          string temp="";
        vector<long long >suff(n);
        suff[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=(suff[i+1]+shifts[i]);
        }
        for(int i=0;i<suff.size();i++){
            int x=(s[i]-'a'+suff[i])%26;
            temp+=x+'a';
        }
          return temp;
    }
};