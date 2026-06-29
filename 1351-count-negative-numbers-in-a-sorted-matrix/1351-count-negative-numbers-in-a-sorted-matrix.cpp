class Solution {
public:
    int countNegatives(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]<0){
                    ans++;
                }
            }
        }
        return ans;
    }
};