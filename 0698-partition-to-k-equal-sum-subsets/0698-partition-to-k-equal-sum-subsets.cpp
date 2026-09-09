class Solution {
public:
    bool solve(vector<int>&nums,int k,vector<bool>&visited,int count,int sum,int target,int idx){
      int n=nums.size();
      if(count==k){
          return true;
      } 
      if(sum==target){
      if(solve(nums,k,visited,count+1,0,target,0)) return true;
      }
      for(int i=idx;i<n;i++){
        if(sum+nums[i]>target) continue;
        if(visited[i]==true) continue;
        visited[i]=true;
        sum+=nums[i];
       if(solve(nums,k,visited,count,sum,target,i+1)) return true;
        visited[i]=false;
        sum-=nums[i];
      }

     return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
          int n=nums.size();
          vector<bool>visited(n,false);
          int total=accumulate(nums.begin(),nums.end(),0);
          if(total%k!=0) return false;
          int target=total/k;
           sort(nums.rbegin(),nums.rend());
          return solve(nums,k,visited,1,0,target,0);


    }
};