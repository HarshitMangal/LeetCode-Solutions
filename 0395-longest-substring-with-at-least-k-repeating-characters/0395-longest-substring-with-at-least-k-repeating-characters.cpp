class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        //sabse phle btrute force se karnege
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                bool flag=true;
                for(auto it:mp){
                    if(it.second<k){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    ans=max(ans,j-i+1);
                }

            }
        }
        return ans;
        
        
    }
};