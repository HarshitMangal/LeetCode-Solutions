class Solution {
public:
      void dfs(vector<vector<int>>&mat,int i,int j,vector<vector<bool>>&visited){
       int n=mat.size();
       int m=mat[0].size();
       if(i<0||i>=n||j<0||j>=m||mat[i][j]==1||visited[i][j]==true)  return ;
       mat[i][j]=1;
       visited[i][j]=true;
       dfs(mat,i+1,j,visited);
       dfs(mat,i-1,j,visited);
       dfs(mat,i,j+1,visited);
       dfs(mat,i,j-1,visited);
   }
    int closedIsland(vector<vector<int>>& mat) {
          int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(mat[i][0]==0) dfs(mat,i,0,visited);
            if(mat[i][m-1]==0) dfs(mat,i,m-1,visited);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==0) dfs(mat,0,i,visited);
            if(mat[n-1][i]==0) dfs(mat,n-1,i,visited);
        }
          int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0&&!visited[i][j]){
                    count++;
                    dfs(mat,i,j,visited);
                }
            }
        }
        return count;



        
    }
};