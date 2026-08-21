class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        unordered_map<string, int> mp;

        for(auto &row : matrix) {

            int first = row[0];
            string s = "";

            for(int x : row) {
                if(x == first)
                    s += '0';
                else
                    s += '1';
            }

            mp[s]++;
        }

        int ans = 0;

        for(auto it : mp) {
            ans = max(ans, it.second);
        }

        return ans;
    }
};