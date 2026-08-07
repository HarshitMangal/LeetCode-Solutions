class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        //very famous greedy solutions yar
      
        vector<int>maxend(n+1,0);
        for(int i=0;i<=n;i++){
            int left=max(0,i-nums[i]);
            int right=min(n,i+nums[i]);
            maxend[left]=max(maxend[left],right);
        }
        int maxi=0;
        int currend=0;
        int taps=0;
        for(int i=0;i<=n;i++){
            if(i>maxi) return -1;
            if(i>currend){
                taps++;
              currend=maxi;
            }
            maxi=max(maxi,maxend[i]);
        }
        return taps;
    }
};