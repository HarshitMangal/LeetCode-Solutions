class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
           vector<vector<vector<int>>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int start = e[2];
            int end = e[3];

            adj[u].push_back({v, start, end});
        }

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
                  auto [currTime, u] = pq.top();
                   pq.pop();
                  if(currTime > dist[u]) continue;
                  for(auto &edge : adj[u]){

                int v = edge[0];
                int start = edge[1];
                int end = edge[2];

                long long depart = max(currTime, (long long)start);

                // edge available nahi hai
                if(depart > end) continue;

                long long arrival = depart + 1;
                   if(arrival < dist[v]){
                    dist[v] = arrival;
                    pq.push({arrival, v});
                }
        }
        }

         return dist[n-1] == LLONG_MAX ? -1 : dist[n-1];
    }
};