class Solution {
public:
    vector<string> createGrid(int m, int n) {
          vector<string>grid(m, string(n,'#'));
           grid[0][0]='.';
        int i=0;
        int j=0;
        while(i!=m-1||j!=n-1){
            if(j+1<n){
                j++;
                grid[i][j]='.';
            }
            if(i+1<m){
                i++;
                grid[i][j]='.';
            }
        }
        return grid;
        
    }
};