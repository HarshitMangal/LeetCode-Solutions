class Solution {
public:
 int maxr,maxc;
    void dfs(vector<vector<int>>&mat,int i,int j){
        int n=mat.size();
        int m=mat[0].size();
        mat[i][j]=0;
        maxr=max(maxr,i);
        maxc=max(maxc,j);
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]==1){
               dfs(mat,nx,ny) ;

            }

        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int minr=i;
                    int minc=j;
                    maxr=i;
                    maxc=j;
                    dfs(mat,i,j);
                    ans.push_back({
                        minr,minc,maxr,maxc
                    });
                }
            }
        }
        return ans;

        
    }
};