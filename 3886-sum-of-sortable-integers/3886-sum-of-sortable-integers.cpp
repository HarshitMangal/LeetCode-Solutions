class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
         vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;

            //generate subarray
            bool flag=true;
            for(int i=0;i<n;i+=k){
                int breaks=0;
                for(int j=i;j<i+k-1;j++){
                     if(nums[j]>nums[j+1]) breaks++;
                }
                if(nums[i+k-1]>nums[i]) breaks++;
                vector<int>subs(nums.begin()+i,nums.begin()+i+k);
                sort(subs.begin(),subs.end());
                vector<int>expected(sorted.begin()+i,sorted.begin()+i+k);

                 if( breaks>1||subs!=expected){
                    flag=false;
                    break;
                }
            }
            if(flag==true)ans+=k;
        }
        return ans;
        
    }
};