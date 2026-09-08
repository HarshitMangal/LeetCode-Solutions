class Solution {
public:
     void solve(vector<int>&arr,set<vector<int>>&ans,int index){
    if(index==arr.size()){
        ans.insert(arr);
        return ;
    }
     for(int i=index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        solve(arr,ans,index+1);
        swap(arr[i],arr[index]);
     }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
           int n=nums.size();
           set<vector<int>>st;
        solve(nums,st,0);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};