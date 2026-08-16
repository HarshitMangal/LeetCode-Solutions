class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans;

        for (string word : words) {

            unordered_map<char, char> mp1;
            unordered_map<char, char> mp2;

            bool ok = true;

            for (int i = 0; i < pattern.size(); i++) {

                if (mp1.find(pattern[i]) != mp1.end()) {

                    if (mp1[pattern[i]] != word[i]) {
                        ok = false;
                        break;
                    }
                }

                else if (mp2.find(word[i]) != mp2.end()) {

                    if (mp2[word[i]] != pattern[i]) {
                        ok = false;
                        break;
                    }
                }

                else {

                    mp1[pattern[i]] = word[i];
                    mp2[word[i]] = pattern[i];
                }
            }

            if (ok)
                ans.push_back(word);
        }

        return ans;
    }
};