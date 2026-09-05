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
  TreeNode*solve(int prelo,int prehi,vector<int>&pre,int inlo,int inhi,vector<int>&in){
    if(prelo>prehi) return NULL;
     TreeNode*root=new TreeNode(pre[prelo]);
     int idx=0;
     while(idx<prehi&&pre[prelo]!=in[idx]){
        idx++;
     }
      int left=idx-inlo;
     root->left=solve(prelo+1,prelo+left, pre, inlo,inlo+left-1,in);
     root->right=solve(prelo+left+1, prehi,pre,inlo+left+1,inhi,in);
     return root;
  }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return solve(0,n-1,pre,0,n-1,in);
    }
};