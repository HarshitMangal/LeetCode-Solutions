class Solution {
public:
    int maxSum(vector<vector<int>>&mat) {
            int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        //hum ab 2d prefix sum build karnege
        vector<vector<long long>>prefix(n,vector<long long>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j]=mat[i][j];
                if(i>0){
                    prefix[i][j]+=prefix[i-1][j];
                }
                if(j>0){
                    prefix[i][j]+=prefix[i][j-1];
                }
                if(i>0&&j>0){
                    prefix[i][j]-=prefix[i-1][j-1];
                }
            }
        }
        //ab  hum houglass sum niklnge
        int maxi=INT_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
               int r1=i;
               int c1=j;
               int r2=i+2;
               int c2=j+2;
               int sum=prefix[r2][c2];
               if(r1>0){
                sum-=prefix[r1-1][c2];
               }
               if(c1>0){
                sum-=prefix[r2][c1-1];
               }
               if(r1>0&&c1>0){
                sum+=prefix[r1-1][c1-1];
               }
               //middle row ke  2 elemnt hatunage
               int hourglass=sum-mat[i+1][j]-mat[i+1][j+2];
               maxi=max(maxi,hourglass);
            }
        }
        return maxi;
         
    }
};