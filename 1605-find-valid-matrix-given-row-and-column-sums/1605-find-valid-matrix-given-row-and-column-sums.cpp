class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
           int n=row.size();
        int m=col.size();
         vector<vector<int>>ans(n,vector<int>(m,0));
         int index=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=min(row[i],col[j]);
                ans[i][j]=val;
                row[i]-=val;
                col[j]-=val;
            }
         }
         return ans;
    }
};