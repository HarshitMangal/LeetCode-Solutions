class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
          vector<vector<pair<int,int>>>adj(n);
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int w=it[2];
               adj[u].push_back({v,w});
           }
    //using min heap
        priority_queue<tuple<int,int,char,int>,vector<tuple<int,int,char,int>>,
        greater<>>pq;
        //wt,node,string ,consecutive count;
        
        pq.push({0,0,labels[0],1});
        //
        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(26,vector<bool>(k+1,false)));

                while(!pq.empty()){
                    auto[cost,node,last,count]=pq.top();
                    pq.pop();
                    if(node==n-1) return cost;
                    int ci=last-'a';
                    if(visited[node][ci][count]) continue;
                     visited[node][ci][count]=true;
                    for(auto [nbr,wt]:adj[node]){
                        char nc=labels[nbr];
                        int newcnt=(nc==last)?count+1:1;
                        if(newcnt>k) continue;
                        int nci=nc-'a';
                        if(!visited[nbr][nci][newcnt]){
                            pq.push({cost+wt,nbr,nc,newcnt});
                        }
                    }
                }
        return -1;
    }
};