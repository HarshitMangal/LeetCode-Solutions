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
  int maxD=0;
unordered_map<int,int>mp;
    void depth(TreeNode*root,int d){
        if(root==NULL) return;
        maxD=max(maxD,d);
        mp[root->val]=d;
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
      TreeNode*lca(TreeNode*root){
        if(root==NULL||mp[root->val]==maxD) return root;
        TreeNode*left=lca(root->left);
        TreeNode*right=lca(root->right);
        if(left!=NULL&&right!=NULL) return root;
        if(left!=NULL) return left;
        return right;
      }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return lca(root);
        
    }
};