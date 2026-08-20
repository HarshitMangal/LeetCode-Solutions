class CBTInserter {
public:
    TreeNode* root;

    CBTInserter(TreeNode* root) {
        this->root = root;
    }

    int insert(int v) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* temp = q.front();
            q.pop();

            // left empty hai -> yahin insert karo
            if(temp->left == NULL) {

                TreeNode* newNode = new TreeNode(v);
                temp->left = newNode;

                return temp->val;
            }
            else {
                q.push(temp->left);
            }

            // right empty hai -> yahin insert karo
            if(temp->right == NULL) {

                TreeNode* newNode = new TreeNode(v);
                temp->right = newNode;

                return temp->val;
            }
            else {
                q.push(temp->right);
            }
        }

        return -1;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */