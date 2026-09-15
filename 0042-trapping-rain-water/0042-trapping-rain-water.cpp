class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        //phle prefix  pre grtest element
        vector<int>pre(n,-1);
        int p=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=p;
            p=max(p,nums[i]);
        }
        //phir suffix
        vector<int>suff(n,-1);
        int s=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=s;
            s=max(s,nums[i]);
        }
        //mini array
        vector<int>mini(n,0);
        for(int i=0;i<n;i++){
            mini[i]=min(pre[i],suff[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]<mini[i]){
                ans+=(mini[i]-nums[i]);
            }
        }
        return ans;

        
    }
};