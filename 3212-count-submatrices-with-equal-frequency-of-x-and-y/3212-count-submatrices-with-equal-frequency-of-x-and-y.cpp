class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>currsumx(n,vector<int>(m,0));
        vector<vector<int>>currsumy(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              currsumx[i][j]=(mat[i][j]=='X');
              currsumy[i][j]=(mat[i][j]=='Y');
              if(i-1>=0){
                currsumx[i][j]+=currsumx[i-1][j];
                currsumy[i][j]+=currsumy[i-1][j];
              }
              if(j-1>=0){
                currsumx[i][j]+=currsumx[i][j-1];
                currsumy[i][j]+=currsumy[i][j-1];
              }
              if(i-1>=0&&j-1>=0){
                currsumx[i][j]-=currsumx[i-1][j-1];
                currsumy[i][j]-=currsumy[i-1][j-1];
              }
              if(currsumx[i][j]==currsumy[i][j]&&currsumx[i][j]>0){
                count++;
              }

        }
        }
        return count;
    }
};