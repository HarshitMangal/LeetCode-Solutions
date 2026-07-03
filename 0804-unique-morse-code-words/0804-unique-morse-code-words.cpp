class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };

        unordered_set<string> st;

        for (auto &word : words) {

            string temp = "";

            for (char ch : word) {
                temp += morse[ch - 'a'];
            }

            st.insert(temp);
        }

        return st.size();
    }
};