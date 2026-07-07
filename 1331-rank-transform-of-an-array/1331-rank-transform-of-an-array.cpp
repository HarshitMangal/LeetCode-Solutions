class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr1) {
         vector<int>ans;
         vector<int>arr=arr1;
         int n=arr.size();
         sort(arr.begin(),arr.end());
         int rank=1;
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=rank;
                rank++;
            }
         }
         for(auto it:arr1){
            ans.push_back(mp[it]);
         }
         return ans;
    }
};