class Solution {
public:
     void solve(vector<int>&nums,set<vector<int>>&st,vector<int>&v,int idx){
        int n=nums.size();
        if(idx>=n){
            st.insert(v);
            return ;
        }
        v.push_back(nums[idx]);
        int j=idx+1;
        // while(j<n&&nums[j]==nums[j-1]) j++;
        solve(nums,st,v,j);

        v.pop_back();
        
        solve(nums,st,v,idx+1);
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>v;
        solve(nums,st,v,0);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    
    }
};
