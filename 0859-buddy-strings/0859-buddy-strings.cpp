class Solution {
public:

    bool buddyStrings(string s, string goal) {
     int n=s.length();
     if(s.length()!=goal.length()) return false;
     if(s==goal){
        vector<int>fre(26,0);
        for(int i=0;i<n;i++){
             fre[s[i]-'a']++;
            if(fre[s[i]-'a']>=2) return true;
        }
        return false;
     }
     //agar equal nahi he to
     vector<int>diff;
     for(int i=0;i<n;i++){
        if(s[i]!=goal[i]){
            diff.push_back(i);
        }
     }
     if(diff.size()!=2) return false;
     int i=diff[0];
     int j=diff[1];
     if(s[i]==goal[j]&&goal[i]==s[j]) return true;
     return false;
    }
};