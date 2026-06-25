class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=s.length();
         unordered_map<char,int>mp;
         for(auto it:p){
            mp[it]++;
         }
         int count=mp.size();
         int i=0;
         int j=0;
         while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                     count--;
                }
            }
            while(count==0){
                if(j-i+1==p.length()){
                    ans.push_back(i);

                }
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]==0) count++;
                    mp[s[i]]++;
                }
                i++;
            }
            j++;
         }
         return ans;
    }
};