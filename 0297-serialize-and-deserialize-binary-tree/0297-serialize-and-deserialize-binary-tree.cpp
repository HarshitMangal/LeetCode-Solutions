/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
     void preorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            ans.push_back(INT_MIN);
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
     }

    string serialize(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
          string temp="";
          for(auto it:ans){
            temp+=to_string(it)+" ";
          }
          return temp;
    }
    int idx;
    TreeNode*build(vector<int>&arr){
     if(arr[idx]==INT_MIN){
        idx++;
        return NULL;
     }
     TreeNode*root=new TreeNode(arr[idx++]);
     root->left=build(arr);
     root->right=build(arr);
     return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string temp) {
         vector<int>arr;
         string curr="";
        for(auto it:temp){
            if(it==' '){
                if(!curr.empty()){
                    arr.push_back(stoi(curr));
                    curr.clear();
                }
            }
            else{
                curr+=it;
            }

        }
        idx=0;
        return build(arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));