class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int maxi=INT_MIN;
        int odd=0;
        int even=INT_MAX;
        for(auto it:mp){
            if(it.second%2!=0){
                odd=max(odd,it.second);
            }
            else{
                even=min(even,it.second);
            }
        }
        return odd-even;
    }
};