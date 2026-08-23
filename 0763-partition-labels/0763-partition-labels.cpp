class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int start=0;
        int maxi=0;
        for(int i=0;i<=n;i++){
           maxi=max(maxi,mp[s[i]]);
          if(i==maxi){
            ans.push_back(i-start+1);
            start=i+1;
          }
        }
        return ans;
    }
};