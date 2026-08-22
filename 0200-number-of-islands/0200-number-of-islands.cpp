class Solution {
public:
    void solve(vector<vector<char>>&mat,int i,int j){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0||i>=n||j<0||j>=m||mat[i][j]=='0') return ;
        mat[i][j]='0';
       solve(mat,i+1,j);
       solve(mat,i-1,j);
       solve(mat,i,j+1);
       solve(mat,i,j-1);

    }
    int numIslands(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    solve(mat,i,j);
                    ans++;
                }

            }
        }
         return ans;
    }
};