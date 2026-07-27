class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if(root == NULL) return ans;

        vector<vector<int>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q; // {node,{col,row}}
        q.push({root,{0,0}});

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            TreeNode* temp = front.first;
            int col = front.second.first;
            int row = front.second.second;

            nodes.push_back({col,row,temp->val});

            if(temp->left){
                q.push({temp->left,{col-1,row+1}});
            }

            if(temp->right){
                q.push({temp->right,{col+1,row+1}});
            }
        }

        // Sort by column, then row, then value
        sort(nodes.begin(), nodes.end());

        ans.push_back({nodes[0][2]});

        int n = nodes.size();

        for(int i = 1; i < n; i++){

            if(nodes[i][0] == nodes[i-1][0]){
                ans.back().push_back(nodes[i][2]);
            }
            else{
                ans.push_back({nodes[i][2]});
            }
        }

        return ans;
    }
};