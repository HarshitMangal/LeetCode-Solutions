class Solution {
public:
     int sum(int n){
        int s=0;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        return s;
     }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
          vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int num=sum(nums[i]);
              v.push_back({num,nums[i]});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){

            if(a.first == b.first)
                return a.second < b.second;

            return a.first < b.first;
        });
         vector<int> target;
         for(auto &p : v){
           target.push_back(p.second);
        }
        //ab compare karenge
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
         for(int i=0;i<n;i++){
            if(nums[i] == target[i]) continue;
             int val=target[i];
             int idx=mp[val];
             int x=nums[i];
             int y=nums[idx];
             swap(nums[i],nums[idx]);
             count++;
             mp[x]=idx;
             mp[y]=i;
         }
        return count;




    }
};