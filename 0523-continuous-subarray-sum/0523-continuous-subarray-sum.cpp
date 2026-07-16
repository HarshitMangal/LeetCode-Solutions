class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
            int n=nums.size(); // {6,6}   first prefix sum ko hamdle akrne ke liye
            unordered_map<int,int>mp;
             mp[0]=-1;
            int sum=0;
            //using prefix sum +sliding window
            for(int i=0;i<n;i++){
                sum+=nums[i];
                // if(sum%k==0) return true;
                int rem=sum%k;
                if(mp.find(rem)!=mp.end()){
                    if((i-mp[rem])>=2){
                        return true;
                    }
                }
                else{
                    mp[rem]=i;
                }
            }
            return false;
        }
};