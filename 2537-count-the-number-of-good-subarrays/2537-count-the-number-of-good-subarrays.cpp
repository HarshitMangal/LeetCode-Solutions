class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long  long  total=1LL*n*(n+1)/2;
        long long pair=0;
        long long ans=0;
        int i=0;
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            pair+=mp[nums[j]];
            mp[nums[j]]++;
            while(pair>=k){
                mp[nums[i]]--;
                pair-=mp[nums[i]];
                i++;
            }
            ans+=(j-i+1);
        }
        return total-ans;

    }
};