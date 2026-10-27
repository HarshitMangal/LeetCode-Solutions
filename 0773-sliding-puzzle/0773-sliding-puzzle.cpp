class Solution {
public:
    int slidingPuzzle(vector<vector<int>>&mat) {
        int n=mat.size();
        int m=mat[0].size();
        string start="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                start+=mat[i][j]+'0';
            }
        }
         string target="123450";
          vector<vector<int>> adj = {
            {1, 3},       // index 0
            {0, 2, 4},    // index 1
            {1, 5},       // index 2
            {0, 4},       // index 3
            {1, 3, 5},    // index 4
            {2, 4}        // index 5
        };
        unordered_set<string>visited;
        queue<pair<string,int>>q;
        q.push({start,0});
        visited.insert(start);
        while(!q.empty()){
            string temp=q.front().first;
            int moves=q.front().second;
            q.pop();
            if(temp==target) return moves;
            int zero=temp.find('0');
            for(auto it:adj[zero]){
                string temp1=temp;
                swap(temp1[zero],temp1[it]);
                if(visited.find(temp1)==visited.end()){
                    q.push({temp1,moves+1});
                    visited.insert(temp1);
                }
            }
        }
       return -1;

        
    }
};