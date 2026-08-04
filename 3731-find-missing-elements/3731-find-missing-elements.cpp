class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=mini;i<=maxi;i++){
            if((mp.find(i))==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};