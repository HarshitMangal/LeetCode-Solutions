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
    bool iscontain(TreeNode*root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        return iscontain(root->left)||iscontain(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
      
        if(iscontain(root->left)==false) root->left=NULL;
        if(iscontain(root->right)==false)   root->right=NULL;
          if(root->val==0&&root->left==NULL&&root->right==NULL) return NULL;
        pruneTree(root->left);
        pruneTree(root->right);
        return root;



    }
};