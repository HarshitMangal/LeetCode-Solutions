class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& mat) {
             vector<vector<int>>ans;
          int n=mat.size();
          int m=mat[0].size();
          for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
          }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=mat[i][j];
                mat[i][j]=1-val;
            }
          }
          return mat;
    }
};