class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //using bfs se karnge yar
           unordered_map<int,vector<pair<int,int>>>adj;
           for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
           }
         vector<int>dist(n,INT_MAX);
         dist[src]=0;
         queue<pair<int,int>>q;
         q.push({src,0});

        while(!q.empty()&&k>=0){
            int size=q.size();
            while(size--){
            pair<int,int>front=q.front();
            q.pop();
            int u=front.first;
            int w=front.second;
            for(auto v:adj[u]){
                int adjwt=v.second;
                if(w+adjwt<dist[v.first]){
                    dist[v.first]=w+adjwt;
                    q.push({v.first,w+adjwt});
                }
              

            }
            }
            k--;

        }
          return dist[dst]==INT_MAX?-1:dist[dst];
        
        
    }
};