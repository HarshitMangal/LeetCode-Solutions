class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int ones=0;
            for(auto it:nums){
                int ithbit=(it>>i)&1;
                if(ithbit==1){
                    ones++;
                }
            }
            int zero=n-ones;
        //is bit ka contibution
        ans+=(ones*zero);
        }

        return ans;
        

    }
};