class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    void dfs(vector<vector<int>>&mat,int i,int j,vector<vector<bool>>&visited){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0||i>=n||j<0||j>=m||visited[i][j]==true) return ;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]>=mat[i][j]){
                dfs(mat,nx,ny,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
           vector<vector<int>>ans;
           int n=mat.size();
           int m=mat[0].size();
           vector<vector<bool>>pacific(n,vector<bool>(m,false));
           vector<vector<bool>>atlantic(n,vector<bool>(m,false));
           //phle pacific ka
           for(int i=0;i<m;i++){
            dfs(mat,0,i,pacific);
            dfs(mat,n-1,i,atlantic);
           }
           for(int i=0;i<n;i++){
            dfs(mat,i,0,pacific);
            dfs(mat,i,m-1,atlantic);
           }
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==true&&atlantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
           }
           return ans;


           


           
    }
};