class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxsum) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        // sort(nums.begin(),nums.end());
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                if(sum+i>maxsum) break;
                sum+=i;
                ans++;
            }

        }
        return ans;
        
    }
};