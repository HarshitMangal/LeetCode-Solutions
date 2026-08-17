class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>mp;
        //using brute force se karngfe yuar
        //subarray banyenge yar
          for(int i=0;i+k<=n;i++){
             set<int>st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(auto it:st){
                mp[it]++;
            }

          }
          for(auto it:mp){
            if(it.second==1){
                ans=max(ans,it.first);
            }
          }
          return ans;

    }
};