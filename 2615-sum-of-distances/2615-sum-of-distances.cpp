class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
          int n=arr.size();
         unordered_map<int,vector<int>>mp;
         for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
         }
         //ab hum prefix sum se answer niklnge
         vector<long long>ans(n);
         for(auto it:mp){
            vector<int>&v=it.second;
            int m=v.size();
            vector<long long>prefix(m);
            prefix[0]=v[0];
            for(int i=1;i<m;i++){
                prefix[i]=prefix[i-1]+v[i];
            }
            long long totalsum=prefix[m-1];
            //calculate the answer for every occurance
            for(int i=0;i<m;i++){
                long long idx=v[i];

                //left side
                long long leftcount=i;
                long long leftsum=(i==0)?0:prefix[i-1];
                long long left=idx*leftcount-leftsum;

                //ab right side
                long long rightcount=m-1-i;
                long long rightsum=totalsum-prefix[i];
                long long right=rightsum-idx*rightcount;

                ans[idx]=left+right;

            }
         }
         return ans;
    }
};