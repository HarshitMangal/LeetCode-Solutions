class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
             int n=arr.size();
             vector<int>prefix(n,INT_MAX);
             vector<int>suffix(n,INT_MAX);
             int best=INT_MAX;
             int i=0;
             int sum=0;
             for(int j=0;j<n;j++){
                sum+=arr[j];
                while(sum>target){
                    sum-=arr[i];
                    i++;
                }
                if(sum==target){
                    best=min(best,j-i+1);
                }
                prefix[j]=best;
             }
             sum=0;
             i=n-1;
             best=INT_MAX;
             for(int j=n-1;j>=0;j--){
                sum+=arr[j];
                while(sum>target){
                    sum-=arr[i];
                    i--;
                }
                if(sum==target){
                    best=min(best,i-j+1);
                }
                suffix[j]=best;
             }
             int ans=INT_MAX;
             for(int i=0;i<n-1;i++){
                if(prefix[i]!=INT_MAX&&suffix[i+1]!=INT_MAX){
                    ans=min(ans,prefix[i]+suffix[i+1]);
                }
             }
             return ans==INT_MAX?-1:ans;
    }
};