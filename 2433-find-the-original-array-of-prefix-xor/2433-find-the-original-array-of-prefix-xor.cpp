class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i-1]^arr[i];
        }
        return pre;

        
    }
};