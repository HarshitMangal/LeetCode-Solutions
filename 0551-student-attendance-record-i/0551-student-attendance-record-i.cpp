class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        bool flag=false;
        int a=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A') a++;
        }
        if(a>=2) return false;
        int count=1;
        for(int i=0;i<n-1;i++){
            if(s[i]=='L'&&s[i]==s[i+1]){
                count++;
            }
            if(count>=3) return false;
            else if(s[i]!='L') count=1;
        }
        return true;
    }
};