class Solution {
public:

    bool bfs(vector<vector<int>>& dist, int val) {

        int n = dist.size();

        if(dist[0][0] < val)
            return false;

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            int x = front.first;
            int y = front.second;

            if(x == n-1 && y == n-1)
                return true;

            for(int k=0;k<4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx<n &&
                   ny>=0 && ny<n &&
                   !visited[nx][ny] &&
                   dist[nx][ny] >= val){

                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        vector<vector<int>> dist(n, vector<int>(n,0));
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        queue<pair<int,int>> q;

        // Multi Source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }

            }
        }

        while(!q.empty()){

            auto front=q.front();
            q.pop();

            int x=front.first;
            int y=front.second;

            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<n &&
                   ny>=0 && ny<n &&
                   !visited[nx][ny]){

                    visited[nx][ny]=true;
                    dist[nx][ny]=dist[x][y]+1;

                    q.push({nx,ny});
                }
            }
        }

        int low=0;
        int high=400;
        int ans=0;

        while(low<=high){

            int mid=(low+high)/2;

            if(bfs(dist,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};
