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
  void inorder(TreeNode*root,vector<TreeNode*>&ans){
    if(root==NULL) return ;
    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
  }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>ans;
        inorder(root,ans);
        int n=ans.size();
        TreeNode*root1=ans[0];
        TreeNode*curr=root1;
        for(int i=1;i<n;i++){
            curr->right=ans[i];
            curr->left=NULL;
            curr=curr->right;
        }
        curr->left = NULL;
        curr->right = NULL;
        return root1;
        
    }
};