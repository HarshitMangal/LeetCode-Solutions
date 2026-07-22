class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n=s.length();
       string temp="";
       vector<int>diff(n+1,0);
       for(auto &it:shifts){
         int l=it[0];
         int r=it[1];
         int dir=it[2];
         if(dir==1){
            diff[l]++;
            diff[r+1]--;
         }
         else{
            diff[l]--;
            diff[r+1]++;
         }
       }
       int curr=0;
        for(int i=0;i<n;i++){
           curr+=diff[i];
           int  x=(s[i]-'a'+curr)%26;
           if(x<0) x+=26;
           temp+=x+'a';
        }
        return temp;

    }
};