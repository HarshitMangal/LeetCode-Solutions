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
     void solve(TreeNode*root,int target,long long sum,unordered_map<long long ,int>&mp,int &count){
        if(root==NULL) return ;
        sum+=root->val;
        if(sum==target) count++;
       if(mp.find(sum-target)!=mp.end()) count+=mp[sum-target];
         mp[sum]++;
        solve(root->left,target,sum,mp,count);
        solve(root->right,target,sum,mp,count);
        mp[sum]--;//backtracking 
     }
    int pathSum(TreeNode* root, int target) {
        if(root==NULL) return 0;
        unordered_map<long long ,int>mp;
        int sum=0;
        int count=0;
        solve(root,target,sum,mp,count);
        return count;
        
    }
};