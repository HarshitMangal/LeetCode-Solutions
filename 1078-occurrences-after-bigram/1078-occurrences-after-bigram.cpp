class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string temp = "";

        for (char ch : text) {
            if (ch == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        words.push_back(temp);

        vector<string> ans;

        for (int i = 0; i < words.size() - 2; i++) {

            if (words[i] == first && words[i + 1] == second) {
                ans.push_back(words[i + 2]);
            }

        }

        return ans;
    }
};