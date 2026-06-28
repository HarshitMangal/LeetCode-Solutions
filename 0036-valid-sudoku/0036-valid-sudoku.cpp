class Solution {
public:
      bool canplace(vector<vector<char>>&mat,int r,int c,int num){
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<9;i++){
            if(mat[r][i]==(num+'0')) return false;
            if(mat[i][c]==(num+'0')) return false;
        }
        
     int x=(r/3)*3;
     int y=(c/3)*3;
     for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(mat[i][j]==(num+'0')) return false;
        }
     }
     return true;
    }
    bool isValidSudoku(vector<vector<char>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!='.'){
                    int temp=mat[i][j]-'0';
                    mat[i][j]='.';
                    if(canplace(mat,i,j,temp)==false) return false;
                    mat[i][j]=temp+'0';
                }


            }
         }
         return true;
    }
};