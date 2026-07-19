class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& arr) {
           int n=arr.size();
        
        int sum=0;
        for(int i=0;i<n-1;i++){
           int dx=abs(arr[i+1][0]-arr[i][0]);
           int dy=abs(arr[i+1][1]-arr[i][1]);
           sum+=max(dx,dy);
        }
        return sum;
    }
};