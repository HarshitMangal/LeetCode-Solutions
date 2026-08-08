class Solution {
public:
int n,m;
  bool dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j){
    //grid 2 ko visited mark kar denge yar
    grid2[i][j]=0;
    bool valid=true;
    if(grid1[i][j]==0){
        valid=false;
    }
    

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid2[nx][ny]==1){
            if(!dfs(grid1,grid2,nx,ny)){
                valid=false;
            }

        }
    }
    return valid;

  }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(dfs(grid1,grid2,i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;

        
    }
};