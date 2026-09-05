class Solution {
public:
  bool canplace( int r,int c,vector<vector<char>>&ans){
        int n=ans.size();
        //he row check karenge phle
        for(int i=r-1;i>=0;i--){
            if(ans[i][c]=='Q') return false;
        }
        for(int i=c-1;i>=0;i--){
            if(ans[r][i]=='Q') return false;
        }
         for(int i=r-1, j=c-1;i>=0&&j>=0;i--,j--){
            if(ans[i][j]=='Q') return false;
         }
         for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++){
            if(ans[i][j]=='Q') return false;
         }
         return true;
     }
    void solve(vector<vector<char>>&ans,int n,int r,vector<vector<string>>&mat){
      if(r==n){
        vector<string>v;
         for(int i=0;i<n;i++){
             string temp="";
            for(int j=0;j<n;j++){
                temp+=ans[i][j];
            }
            v.push_back(temp);
         }
         mat.push_back(v);
         return ;
      }
      for(int j=0;j<n;j++){
         if(ans[r][j]=='.'){
            if(canplace(r,j,ans)){
                ans[r][j]='Q';
                solve(ans,n,r+1,mat);
                //backtrack 
                  ans[r][j]='.';
            }
         }
      }

    }
   
    int totalNQueens(int n) {
           vector<vector<string >>mat;
      vector<vector<char>>ans(n,vector<char>(n,'.'));
      vector<string>v;
      solve(ans,n,0,mat);
      return mat.size();
    }
};