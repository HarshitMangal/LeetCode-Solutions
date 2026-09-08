class Solution {
public:
    void solve(vector<vector<int>>&ans,int n,int k,vector<int>v,int idx){
      if(v.size()==k){
        ans.push_back(v);
        return;
      }
    unordered_set<int>visited;
      for(int i=idx;i<=n;i++){
        if(visited.count(i)) continue;
        visited.insert(i);
        v.push_back(i);
        solve(ans,n,k,v,i+1);
        v.pop_back();
      }
    } 
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>ans;
      vector<int>v;
      int idx=1;
      solve(ans,n,k,v,idx);
      return ans;


    }
};