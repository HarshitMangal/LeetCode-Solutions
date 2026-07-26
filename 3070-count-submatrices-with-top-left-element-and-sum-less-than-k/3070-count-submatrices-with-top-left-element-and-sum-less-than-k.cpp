class Solution {
public:
    int countSubmatrices(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
    //prefix sum per based he
    int count=0;
    vector<vector<int>>pref(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              pref[i][j]=mat[i][j];
              if(i>0) pref[i][j]+=pref[i-1][j];
              if(j>0) pref[i][j]+=pref[i][j-1];
              if(i>0&&j>0) pref[i][j]-=pref[i-1][j-1];
              if(pref[i][j]<=k) count++;
            }
        }
        return count;
    }
};