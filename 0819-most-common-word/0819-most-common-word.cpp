class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
         unordered_set<string>st(banned.begin(),banned.end());
         unordered_map<string ,int>mp;
         int i=0;
         int n=s.length();
         while(i<n){
            string temp="";
            while(i<n&&isalpha(s[i])){
               temp+=tolower(s[i]);
               i++;
            }
            if(!temp.empty()){
            mp[temp]++;
            }
            i++;
         }
         int maxi=INT_MIN;
         string ans="";
         for(auto it:mp){
            if(!st.count(it.first)){
                if(it.second>maxi){
                    maxi=it.second;
                    ans=it.first;
                }
            }
         }
         return ans;

    }
};