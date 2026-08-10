class Solution {
public:
  int getsum(int r1,int c1,int r2,int c2,vector<vector<int>>&prefix){
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
      return sum;
  }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        //sabse phle 2d prefix banunga yar me
       vector<vector<int>>prefix(n,vector<int>(m,0));
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
       //for every max sid ekle liye tre marnge yar
       for(int k=min(n,m);k>=1;k--){

         for(int r=0;r+k<=n;r++){
            for(int c=0;c+k<=m;c++){
                int r2=r+k-1;
                int c2=c+k-1;
                int sum=getsum(r,c,r2,c2,prefix);
                if(sum<=threshold){
                    return k;
                }
            }
         }
       }
       return 0;

    }
};