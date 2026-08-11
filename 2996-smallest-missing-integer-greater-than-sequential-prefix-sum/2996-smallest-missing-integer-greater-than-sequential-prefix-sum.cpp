class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)){
                sum+=nums[i];
            }
            else break;
        }
        while(mp[sum]>0){
            sum++;
        }
        return sum;

        
    }
};