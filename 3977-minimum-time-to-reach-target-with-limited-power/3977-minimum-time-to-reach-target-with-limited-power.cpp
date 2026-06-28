class Solution {
public:
    vector<long long> minTimeMaxPower(int n,
        vector<vector<int>>& edges,
        int power,
        vector<int>& cost,
        int source,
        int target) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<>
        > pq;

        pq.push({0, source, power});

        vector<vector<long long>> best(n, vector<long long>(power + 1, LLONG_MAX));

        best[source][power] = 0;

        long long minTime = LLONG_MAX;
        long long bestPower = -1;

        while (!pq.empty()) {

            auto [t, u, p] = pq.top();
            pq.pop();

            if (t > best[u][p]) continue;

            // if we reached target, just update answer
            if (u == target) {
                if (t < minTime) {
                    minTime = t;
                    bestPower = p;
                }
                else if (t == minTime) {
                    bestPower = max(bestPower, (long long)p);
                }
            }

            if (p < cost[u]) continue;

            int np = p - cost[u];

            for (auto [v, w] : adj[u]) {

                long long nt = t + w;

                if (nt < best[v][np]) {
                    best[v][np] = nt;
                    pq.push({nt, v, np});
                }
            }
        }

        if (minTime == LLONG_MAX) return {-1, -1};

        return {minTime, bestPower};
    }
};