class Graph {
public:
  vector<vector<pair<int,int>>>adj;
  int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.resize(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
    }
    
    int shortestPath(int node1, int node2) {
        //using min heap dijstars algorithm
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>dist(n,INT_MAX);
       dist[node1]=0; 
       pq.push({0,node1});  //dist,node
       while(!pq.empty()){
        pair<int,int>front=pq.top();
        pq.pop();
        int node=front.second;
        int w=front.first;
        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            if(w+wt<dist[adjnode]){
                dist[adjnode]=w+wt;
                pq.push({w+wt,adjnode});
            }
        }
       }
       return dist[node2]==INT_MAX?-1:dist[node2];
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */