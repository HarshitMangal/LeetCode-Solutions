class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int groupSize) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%groupSize!=0) return false;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true) continue;
            int count=1;
            int pre=arr[i];
            visited[i]=true;
            for(int j=i+1;j<n&&count<groupSize;j++){
                if(visited[j]==true) continue;
                if(pre+1==arr[j]){
                     count++;
                     visited[j]=true;
                     pre=arr[j];
                }

            }
            if(count!=groupSize) return false;
        }
        return true;


        
        
    }
};