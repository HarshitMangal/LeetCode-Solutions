class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;

        int tr = 0;
        int br = n - 1;

        int tc = 0;
        int bc = m - 1;

        int count = 0;
        int total = n * m;

        while(tr <= br && tc <= bc){

            // left -> right
            for(int i = tc; i <= bc && count < total; i++){
                ans.push_back(mat[tr][i]);
                count++;
            }
            tr++;

            // top -> bottom
            for(int i = tr; i <= br && count < total; i++){
                ans.push_back(mat[i][bc]);
                count++;
            }
            bc--;

            // right -> left
            for(int i = bc; i >= tc && count < total; i--){
                ans.push_back(mat[br][i]);
                count++;
            }
            br--;

            // bottom -> top
            for(int i = br; i >= tr && count < total; i--){
                ans.push_back(mat[i][tc]);
                count++;
            }
            tc++;
        }

        return ans;
    }
};