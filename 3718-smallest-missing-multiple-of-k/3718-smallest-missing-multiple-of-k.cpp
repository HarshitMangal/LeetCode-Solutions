class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            if(it%k==0){
                mp[it]++;
            }
        }
        for(int i=k;;i+=k){
            if(mp.find(i)==mp.end()) return i;
        }
        return -1;

    }
};