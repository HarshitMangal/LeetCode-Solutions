class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        // Graph
        unordered_map<int, vector<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<double> dist(n, 0.0);

        // Max Heap
        priority_queue<pair<double, int>> pq;

        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {

            pair<double, int> front = pq.top();
            pq.pop();

            double prob = front.first;
            int node = front.second;

            if (prob < dist[node])
                continue;

            if (node == end)
                return prob;

            for (auto it : adj[node]) {

                int v = it.first;
                double pro = it.second;

                if (prob * pro > dist[v]) {

                    dist[v] = prob * pro;
                    pq.push({dist[v], v});
                }
            }
        }

        return 0.0;
    }
};