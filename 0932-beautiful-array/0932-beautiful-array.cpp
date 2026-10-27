class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) {
            return {1};
        }

        vector<int> left = beautifulArray((n + 1) / 2);
        vector<int> right = beautifulArray(n / 2);

        vector<int> ans;

        for (int x : left) {
            ans.push_back(2 * x - 1);
        }

        for (int x : right) {
            ans.push_back(2 * x);
        }

        return ans;
    }
};