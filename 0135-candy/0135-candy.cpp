class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        //two pass me hoga ye 
        vector<int>ans(n,1);
        int count=0;
        //left pass me
        for(int i=1;i<n;i++){
          if(arr[i]>arr[i-1]){
            ans[i]=(ans[i-1]+1);
          }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        for(int i=0;i<n;i++){
            count+=ans[i];
        }
        return count;
        
    }
};