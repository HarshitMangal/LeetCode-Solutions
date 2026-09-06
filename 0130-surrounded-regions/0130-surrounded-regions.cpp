class Solution {
public:
   void dfs(vector<vector<char>>&mat,int i,int j){
    int n=mat.size();
    int m=mat[0].size();
    if(i<0||i>=n||j<0||j>=m||mat[i][j]=='X'||mat[i][j]=='s') return ;
      mat[i][j]='s';
     dfs(mat,i+1,j);
     dfs(mat,i,j+1);
     dfs(mat,i-1,j);
     dfs(mat,i,j-1);
   }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
          vector<vector<bool>>visited(n,vector<bool>(m,false));
          for(int i=0;i<n;i++){
            dfs(mat,i,0);
            dfs(mat,i,m-1);
          }
          for(int j=0;j<m;j++){
            dfs(mat,0,j);
            dfs(mat,n-1,j);

          }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                else if(mat[i][j]=='s'){
                    mat[i][j]='O';
                }
            }
          }


         
        
    }
};