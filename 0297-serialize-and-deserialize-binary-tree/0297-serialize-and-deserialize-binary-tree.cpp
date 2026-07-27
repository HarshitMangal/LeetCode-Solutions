/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */class Codec {
public:
    // Preorder traversal for serialization
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) {
            ans.push_back(INT_MIN); // null marker (better than -1 for safety)
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        string temp;
        for (int i = 0; i < ans.size(); i++) {
            temp += to_string(ans[i]) + " "; // space separator
        }
        return temp;
    }

    int idx;

    TreeNode* build(const vector<int>& arr) {
        if (arr[idx] == INT_MIN) { // null marker
            idx++;
            return NULL;
        }
        TreeNode* node = new TreeNode(arr[idx++]);
        node->left = build(arr);
        node->right = build(arr);
        return node;
    }

    // Decodes string to tree
    TreeNode* deserialize(string temp) {
        vector<int> arr;
        string num = "";
        for (char c : temp) {
            if (c == ' ') { // space separator
                if (!num.empty()) {
                    arr.push_back(stoi(num));
                    num.clear();
                }
            } else {
                num += c;
            }
        }
        idx = 0;
        return build(arr);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));