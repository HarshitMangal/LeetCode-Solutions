class Solution {
public:
    int findFreq(string s) {
        char ch = 'z';

        for(int i = 0; i < s.size(); i++) {
            ch = min(ch, s[i]);
        }

        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ch) {
                cnt++;
            }
        }

        return cnt;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        map<int,int> mp;

        // Store frequency of words
        for(int i = 0; i < words.size(); i++) {
            int freq = findFreq(words[i]);
            mp[freq]++;
        }

        vector<int> ans;

        // Process queries
        for(int i = 0; i < queries.size(); i++) {

            int qFreq = findFreq(queries[i]);

            int cnt = 0;

            for(auto it = mp.begin(); it != mp.end(); it++) {
                if(it->first > qFreq) {
                    cnt += it->second;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};