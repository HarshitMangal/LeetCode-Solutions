class Solution {
public:
    int findMinArrowShots(vector<vector<int>>&mat) {
        int n=mat.size();
        int m=mat[0].size();
        sort(mat.begin(),mat.end(),[](vector<int>&a,vector<int>&b){
           return a[1]<b[1];
        });
        int pre=mat[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            if(mat[i][0]<=pre){
               ans++;
            }
            else{
                pre=mat[i][1];
            }
        }
        return n-ans;


    }
};