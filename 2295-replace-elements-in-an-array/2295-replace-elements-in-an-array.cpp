class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
          for(int i=0;i<n;i++){
            mp[nums[i]]=i;
          }
          for(auto it:operations){
            int u=it[0];
            int v=it[1];
            if(mp.find(u)!=mp.end()){
                int temp=mp[u];
                nums[temp]=v;
                mp[v]=temp;
                mp.erase(u);


            }
          }
          return nums;

        
    }
};