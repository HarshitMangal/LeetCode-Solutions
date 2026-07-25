class Solution {
public:
    int maximumLength(string s) {

        unordered_map<string,int> mp;
        int n=s.size();

        for(int i=0;i<n;i++){

            string temp="";

            for(int j=i;j<n;j++){

                if(s[j]!=s[i]) break;

                temp+=s[j];
                mp[temp]++;
            }
        }

        int ans=-1;

        for(auto &it:mp){
            if(it.second>=3){
                ans=max(ans,(int)it.first.size());
            }
        }

        return ans;
    }
};