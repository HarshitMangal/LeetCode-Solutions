class Solution {
public:
    int  bfs(vector<vector<int>>&forest,int sr,int sc,int tr,int tc){
        int n=forest.size();
        int m=forest[0].size();
        //
         if(sr==tr&&sc==tc) return 0;
         queue<pair<int,int>>q;
         q.push({sr,sc});
         vector<vector<bool>>visited(n,vector<bool>(m,false));
         int  steps=0;
         vector<int>dx={1,-1,0,0};
         vector<int>dy={0,0,1,-1};
         while(!q.empty()){
             int size=q.size();
             while(size--){
                pair<int,int>front=q.front();
                q.pop();
                int x=front.first;
                int y=front.second;
                if(x==tr&&y==tc) return steps;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&forest[nx][ny]!=0){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }

             }
             steps++;
         }
         return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<vector<int>>trees;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(trees.begin(),trees.end());
        int ans=0;
        int sr=0;
        int sc=0;
        for(auto tree:trees){
            int tr=tree[1];
            int tc=tree[2];
            int dist=bfs(forest,sr,sc,tr,tc);
            if(dist==-1){
                return -1;
            }
            ans+=dist;
            sr=tr;
            sc=tc;

        }

        return ans;

    }
};