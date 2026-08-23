class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        int maxfre=0;
        while(j<n){
            mp[s[j]]++;
            maxfre=max(maxfre,mp[s[j]]);
            if(j-i+1-maxfre>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};