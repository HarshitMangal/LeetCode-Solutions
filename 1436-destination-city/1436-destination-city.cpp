class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
            unordered_set<string> st;

        // Sabhi source cities store karo
        for (auto &it : paths) {
            st.insert(it[0]);
        }

        // Jo destination source me nahi hai wahi answer
        for (auto &it : paths) {
            if (st.find(it[1]) == st.end())
                return it[1];
        }

        return "";
    }
};