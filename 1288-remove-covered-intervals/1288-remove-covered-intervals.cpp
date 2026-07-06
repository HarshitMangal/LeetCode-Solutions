class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        sort(mat.begin(),mat.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
        return a[0]<b[0];
        });
        int ans=1;
        int pre=mat[0][1];
        for(int i=1;i<n;i++){
            if(mat[i][1]>pre){
               ans++;
               pre=mat[i][1];
            }
        }
        return ans;
      
        
    }
};