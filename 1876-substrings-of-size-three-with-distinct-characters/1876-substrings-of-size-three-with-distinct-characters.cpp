class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp[s[j]]>1) break;
                if(mp.size()==3) count++; 

            }
        }
        return count;


    }
};