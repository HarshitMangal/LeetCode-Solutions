class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int rowflips=0;
        for(int i=0;i<n;i++){
            int j=0;
            int k=m-1;
            while(j<k){
                if(mat[i][j]!=mat[i][k]){
                    rowflips++;
                }
                j++;
                k--;
            }
        }
        int colflips=0;
        for(int i=0;i<m;i++){
            int j=0;
            int k=n-1;
            while(j<k){
                if(mat[j][i]!=mat[k][i]){
                    colflips++;
                }
                j++;
                k--;
            }
        }
        return min(rowflips,colflips);

        
    }
};