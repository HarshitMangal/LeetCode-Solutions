class Solution {
public:
   void  solve(vector<vector<char>>&mat,int i,int j,vector<vector<bool>>&visited){
       int n=mat.size();
       int m=mat[0].size();
       if(i<0||i>=n||j<0||j>=m||mat[i][j]=='0'||visited[i][j]==true) return ;

        visited[i][j]=true;
       solve(mat,i+1,j,visited);
       solve(mat,i,j+1,visited);
       solve(mat,i,j-1,visited);
       solve(mat,i-1,j,visited);
   }
    int numIslands(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
           vector<vector<bool>>visited(n,vector<bool>(m,false));
           int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(mat[i][j]=='1'&&!visited[i][j]){
                solve(mat,i,j,visited);
                count++;
               }
            }
        }
        return count;
    }
};