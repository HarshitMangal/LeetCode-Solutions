class Solution {
public:
    string restoreString(string s, vector<int>& arr) {
            string temp="";
         int n=s.length();
         vector<char>ans(n);
         for(int i=0;i<n;i++){
            ans[arr[i]]=s[i];
         }
         for(int i=0;i<n;i++){
            temp+=ans[i];
         }
         return temp;
        
    }
};