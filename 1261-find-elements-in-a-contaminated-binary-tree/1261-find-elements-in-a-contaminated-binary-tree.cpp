class FindElements {
public:

    unordered_set<int> st;

    void recover(TreeNode* root) {

        if (root == NULL)
            return;

        st.insert(root->val);

        if (root->left) {
            root->left->val = 2 * root->val + 1;
            recover(root->left);
        }

        if (root->right) {
            root->right->val = 2 * root->val + 2;
            recover(root->right);
        }
    }

    FindElements(TreeNode* root) {

        if (root == NULL)
            return;

        root->val = 0;
        recover(root);
    }

    bool find(int target) {

        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */