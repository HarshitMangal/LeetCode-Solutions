class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
        int n=routes.size();
        if(src==target) return 0;
        //using  adjkjacency list bana lenge yar
        unordered_map<int,vector<int>>adj;
       //isme hum stops or unke indices dalenge yar
       for(int i=0;i<n;i++){
        for(auto it:routes[i]){
            adj[it].push_back(i);
        }
       }
       //using bfs se kar lenge yar
       queue<int>q;
       vector<bool>visited(501,false);
       for(auto it:adj[src]){
         q.push(it);
         visited[it]=true;

       }
       int bus=1;
       while(!q.empty()){
        int size=q.size();
        while(size--){
            int route=q.front();
            q.pop();
            for(auto stop:routes[route]){
                if(stop==target){
                    return bus;
                }
            for(auto &next:adj[stop]){
                if(!visited[next]){
                    visited[next]=true;
                    q.push(next);
                }
            }
            }
        }
        bus++;
       }
       return -1;
    }
};