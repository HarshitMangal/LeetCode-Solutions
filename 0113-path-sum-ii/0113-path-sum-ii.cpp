/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int target, int sum,
               vector<vector<int>>& ans, vector<int>& v) {

        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {

            sum += root->val;
            v.push_back(root->val);

            if(target == sum) {
                ans.push_back(v);
            }

            sum -= root->val;   // optional
            v.pop_back();
            return;
        }

        sum += root->val;
        v.push_back(root->val);

        solve(root->left, target, sum, ans, v);
        solve(root->right, target, sum, ans, v);

        sum -= root->val;       // optional
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {

        vector<vector<int>> ans;
        vector<int> v;

        solve(root, target, 0, ans, v);

        return ans;
    }
};