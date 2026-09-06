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
    bool isValidSudoku(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!='.'){
                int num=mat[i][j]-'0';
                mat[i][j]='.';
                if(canplace(mat,i,j,num)==false) return false;;
                mat[i][j]=num+'0';
            }
        }
    }
        return true;
    }
};