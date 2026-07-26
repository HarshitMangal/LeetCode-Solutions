class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
         int n=mat.size();
         int m=mat[0].size();
         int count=0;
         for(int top=0;top<n;top++){
            vector<int>temp(m,0);
            for(int bottem=top;bottem<n;bottem++){
                for(int col=0;col<m;col++){
                    temp[col]+=mat[bottem][col];
                }
            // problem specific logic
            int sum=0;
            unordered_map<int,int>mp;
            for(int i=0;i<temp.size();i++){
                sum+=temp[i];
                if(sum==target) count++;
                if(mp.find(sum-target)!=mp.end()){
                    count+=mp[sum-target];
                }
                mp[sum]++;
            }

            }
         }
         return count;
    }
};