class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                
                string a = words[i];
                string b = words[j];
                
                int len = a.size();
                int n = b.size();
                
                if(len > n) continue;
                
                // prefix
                bool prefix = true;
                for(int k = 0; k < len; k++) {
                    if(a[k] != b[k]) {
                        prefix = false;
                        break;
                    }
                }
                
                // suffix
                bool suffix = true;
                for(int k = 0; k < len; k++) {
                    if(a[k] != b[n - len + k]) {
                        suffix = false;
                        break;
                    }
                }
                
                if(prefix && suffix)
                    ans++;
            }
        }
        
        return ans;
    }
};