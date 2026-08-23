class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0;
        int start=-1;
        int j=0;
        int mini=INT_MAX;
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int count=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            while(count==0){
                if(mini>j-i+1){
                    mini=j-i+1;
                    start=i;
                }
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]==0){
                        count++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }
            j++;
        }
        return mini==INT_MAX?"":s.substr(start,mini);

    }
};