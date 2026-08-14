class Solution {
public:

    void solve(TreeNode* root, map<int,int>& mp) {
        if(root == NULL)
            return;

        mp[root->val]++;

        solve(root->left, mp);
        solve(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {

        map<int,int> mp;

        solve(root, mp);

        int maxi = 0;

        // maximum frequency
        for(auto it : mp) {
            maxi = max(maxi, it.second);
        }

        vector<int> ans;

        // maximum frequency wale elements
        for(auto it : mp) {
            if(it.second == maxi) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};