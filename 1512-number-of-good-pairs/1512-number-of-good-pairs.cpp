class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>m;
        for(auto x:nums){
            ans+=m[x]++;
        }
        return ans;
        
    }
};