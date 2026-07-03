class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    bool dijkstra(vector<vector<pair<int,int>>> &graph, int mid, ll k, int n) {

        vector<ll> dist(n, INF);

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){

            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w] : graph[u]){

                if(w < mid) continue;

                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);

        int low = INT_MAX;
        int high = 0;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            low = min(low, w);
            high = max(high, w);

            if( !online[u]) continue;
            if( !online[v]) continue;

            graph[u].push_back({v,w});
        }

        int ans = -1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(dijkstra(graph, mid, k, n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};