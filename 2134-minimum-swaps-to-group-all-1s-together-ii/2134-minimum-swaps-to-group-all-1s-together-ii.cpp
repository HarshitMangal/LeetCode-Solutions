class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int onecount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) onecount++;
        }
        vector<int>temp(2*n);
        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }
        int mini=INT_MAX;
        int one=0;
        for(int i=0;i<onecount;i++){
            if(temp[i]==1) one++;
        }
        mini=min(mini,onecount-one);
        for(int i=onecount;i<n+onecount;i++){
              if(temp[i-onecount]==1) one--;
               if(temp[i]==1) one++;
               mini=min(mini,onecount-one);
        }
        return mini;
    }
};