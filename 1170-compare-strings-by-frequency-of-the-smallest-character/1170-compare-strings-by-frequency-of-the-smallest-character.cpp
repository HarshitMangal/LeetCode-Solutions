class Solution {
public:
   int findfre(string &s){
    int n=s.length();
    char mini='z';
    for(int i=0;i<n;i++){
        mini=min(mini,s[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(mini==s[i]){
            count++;
        }
    }
    return count;
   }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        int n=queries.size();
        map<int,int>mp;
        for(auto it:words){
            int fre=findfre(it);
               mp[fre]++;
        }
        for(auto it:queries){
        int fre=findfre(it);
        int count=0;
        for(auto it:mp){
            if(it.first>fre){
                count+=it.second;
            }
        }
        ans.push_back(count);
        } 
        return  ans;

    }
};