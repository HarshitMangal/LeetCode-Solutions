class Solution {
public:
    vector<string> subdomainVisits(vector<string>& arr) {
        vector<string>ans;
        int n=arr.size();
        //using map 
        unordered_map<string ,int>mp;
        for(auto s:arr){
            int count=0;
            int i=0;
            while(s[i]!=' '){
                count=count*10+(s[i]-'0');
                i++;
            }
            i++;// skip space
            string domain="";
            while(i<s.length()){
                domain+=s[i];
                i++;
            }
            mp[domain]+=count;
            //ab is domain ke tukde karnge
            int j=0;
            while(j<domain.length()){
                if(domain[j]=='.'){
                    mp[domain.substr(j+1)]+=count;
                }
                j++;
            }
        }
        for(auto it:mp){
            ans.push_back(to_string(it.second)+" "+it.first);
        }
        return ans;
        
    }
};