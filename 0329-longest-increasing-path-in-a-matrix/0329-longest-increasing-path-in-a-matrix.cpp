class Solution {
public:
   vector<int>dx={1,-1,0,0};
   vector<int>dy={0,0,1,-1};
   int solve(vector<vector<int>>&mat,vector<vector<int>>&dp,int i,int j){
    int n=mat.size();
    int m=mat[0].size();
    if(i<0||i>=n||j<0||j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int count=1;
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]>mat[i][j]){
             count=max(count,1+solve(mat,dp,nx,ny));
        }
    }
    return dp[i][j]=count;
   }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int maxi=INT_MIN;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,solve(mat,dp,i,j));

            }
         }
         return maxi;
    }
};