class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long >conver(n,0);
        vector<long long>maxi(n,0);
        maxi[0]=nums[0];
        for(int i=1;i<n;i++){
          maxi[i]=max(maxi[i-1],(long long )nums[i]);
        }
        conver[0]=maxi[0]+nums[0];
        for(int i=1;i<n;i++){
            conver[i]=conver[i-1]+maxi[i]+nums[i];
         
        }
        return conver;
    }
};