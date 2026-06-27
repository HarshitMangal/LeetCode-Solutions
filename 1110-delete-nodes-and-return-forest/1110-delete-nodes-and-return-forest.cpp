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
  TreeNode*deletenodehelper(TreeNode*root,vector<TreeNode*>&ans,unordered_set<int>&st){
    if(root==NULL) return NULL;
     root->left=deletenodehelper(root->left,ans,st);
     root->right=deletenodehelper(root->right,ans,st);
    if(st.find(root->val)!=st.end()){
        if(root->left!=NULL){
            ans.push_back(root->left);
        }
         if(root->right!=NULL){
            ans.push_back(root->right);
         }
          return NULL;

    }
    return root;
  }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>st;
        for(int num:to_delete){
            st.insert(num);
        }
        root=deletenodehelper(root,ans,st);
     if(root!=NULL&&st.find(root->val)==st.end()){
        ans.push_back(root);
     }
      return ans;
    }
};