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
     map<int,int>cnt;
     void dfs(TreeNode*root){
        if(root==NULL) return ;
        cnt[root->val]++;
        dfs(root->left);
        dfs(root->right);
     }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        int x=0;
        for(auto u:cnt){
            x++;
            if(x==2) return u.first;
        }
         return -1;
    }

};