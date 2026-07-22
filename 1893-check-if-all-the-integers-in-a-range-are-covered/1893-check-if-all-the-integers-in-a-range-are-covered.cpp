class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
         vector<int>diff(52,0);
        for(auto it:ranges){
           int l=it[0];
           int r=it[1];
           diff[l]++;
           if(r+1<=50){
             diff[r+1]--;
           }
        }
         // Prefix Sum
        for (int i = 1; i <= 50; i++) {
            diff[i] += diff[i - 1];
        }

        for(int i=left;i<=right;i++){
            if(diff[i]==0) return false;
        }
        return true;
    }
};