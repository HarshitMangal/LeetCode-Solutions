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
    TreeNode* solve(vector<int>& pre, int prelo, int prehi,
                    vector<int>& in, int inlo, int inhi) {

        if(prelo > prehi) return NULL;

        TreeNode* root = new TreeNode(pre[prelo]);

        int idx = inlo;

        while(in[idx] != pre[prelo]) {
            idx++;
        }

        int leftsize = idx - inlo;

        root->left = solve(pre, prelo + 1,
                           prelo + leftsize,
                           in, inlo, idx - 1);

        root->right = solve(pre, prelo + leftsize + 1,
                            prehi,
                            in, idx + 1, inhi);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();

        return solve(pre, 0, n - 1, in, 0, n - 1);
    }
};