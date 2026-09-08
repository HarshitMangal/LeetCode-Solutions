class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
           vector<int>ans;
           int n=arr.size();
           priority_queue<pair<int,int>>pq;
           for(auto it:arr){
            int val=abs(x-it);
            pq.push({val,it});
            if(pq.size()>k){
                pq.pop();
            }

        }
        while(!pq.empty()&&k!=0){
            pair<int,int>front=pq.top();
            pq.pop();
            ans.push_back(front.second);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};