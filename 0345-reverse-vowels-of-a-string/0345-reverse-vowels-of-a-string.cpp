class Solution {
public:
  bool isvowel(char s){
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U') return true;
    return false;
  }
    string reverseVowels(string s) {
        int n=s.length();
        vector<char>ans;
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                s[i]=ans[j];
                j++;
            }
        }
        return s;

    }
};