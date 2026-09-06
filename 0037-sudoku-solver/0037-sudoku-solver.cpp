class Solution {
public:
   bool canplace(vector<vector<char>>&mat,int r,int c,int num){
    int n=mat.size();
    int m=mat[0].size();
    //ab hum check karnege yar
    for(int i=0;i<n;i++){
        if(mat[r][i]==num+'0') return false;
    }
    for(int i=0;i<n;i++){
        if(mat[i][c]==num+'0') return false;
    }
    int x=(r/3)*3;
    int y=(c/3)*3;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(mat[i][j]==num+'0')return false;
        }
    }
    return true;


   }
   bool solve(vector<vector<char>>&mat,int r,int c){
    if(r==9) return true;
    if(c==9){
        return solve(mat,r+1,0);
    }
     if(mat[r][c]!='.') return solve(mat,r,c+1);
    if(mat[r][c]=='.'){
        for(int i=1;i<=9;i++){
            if(canplace(mat,r,c,i)){
                mat[r][c]=i+'0';
                if(solve(mat,r,c+1))return true;
                mat[r][c]='.' ;//for backtrack
            }
        }
    }
    return false;
   }
    void solveSudoku(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        solve(mat,0,0);

        
    }
};