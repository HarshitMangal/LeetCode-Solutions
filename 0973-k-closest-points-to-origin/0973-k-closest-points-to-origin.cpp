class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        //using min heap
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        priority_queue<pair<int,pair<int,int>>>pq;
         vector<vector<int>>ans;
         int n=arr.size();
         for(auto it:arr){
            int x=it[0];
            int y=it[1];
            int dis=x*x+y*y;
          pq.push({dis,{x,y}});
          if(pq.size()>k){
            pq.pop();
          }
         }
         while(k!=0&&!pq.empty()){
           pair<int,pair<int,int>>front=pq.top();
           pq.pop();
           int x=front.second.first;
           int y=front.second.second;
           ans.push_back({x,y});
           k--;
         }
         return ans;
    }
};