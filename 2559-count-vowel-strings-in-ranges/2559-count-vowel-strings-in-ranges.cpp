class Solution {
public:
     bool isvowel(string &s){
        int n=s.length();
         unordered_set<char>mp={'a','e','i','o','u'};
         bool flag1=false;
         bool flag2=false;
         if(mp.count(s[0])) flag1=true;
         if(mp.count(s[n-1])) flag2=true;
         return flag1==true&&flag2==true;
     }
  
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;

        int n = words.size();

        vector<int> prefix(n, 0);

        // Tera wala
        if(isvowel(words[0]))
            prefix[0] = 1;

        for(int i = 1; i < n; i++) {

            if(isvowel(words[i]))
                prefix[i] = prefix[i-1] + 1;
            else
                prefix[i] = prefix[i-1];
        }

        for(auto q : queries) {

            int l = q[0];
            int r = q[1];

            if(l == 0)
                ans.push_back(prefix[r]);
            else
                ans.push_back(prefix[r] - prefix[l-1]);
        }

        return ans;

    }
};