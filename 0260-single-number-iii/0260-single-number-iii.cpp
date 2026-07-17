class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
          vector<int>ans;
          int n=nums.size();
          int xr=0;
          for(int num:nums){
            xr^=num;
          }
          //mask banyemnge right most set bit ke liye
          long  long  mask=(long long )xr&(-(long long )xr);
          int a=0;
          int b=0;
          for(auto num:nums){
            if(mask&num){
                a^=num;
            }
            else{
                b^=num;
            }
          }
          return {a,b};
    }
};