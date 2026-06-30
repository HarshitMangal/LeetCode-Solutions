class Solution {
public:
 const int mod=1e9+7;
      vector<int> nextSmallerEle(vector<int>& arr) {
         int n=arr.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<=arr[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
vector<int> prevSmaller(vector<int>& arr) {
          int n=arr.size();
         vector<int>ans(n,-1);
         stack<int>st;
         for(int i=n-1;i>=0;i--){
              while(!st.empty()&&arr[i]<arr[st.top()]){
                  ans[st.top()]=i;
                  st.pop();
              }
              st.push(i);
         }
         return ans;
        
    }
    int sumSubarrayMins(vector<int>& arr) {
           int n=arr.size();
        vector<int>pre=prevSmaller(arr);
        vector<int>next=nextSmallerEle(arr);
        long long  ans=0;
        for(int i=0;i<n;i++){
          int left=(i-pre[i]);
          int right=(next[i]-i);
          ans=(ans+1LL*arr[i]*left*right)%mod;
        }
        return ans;
    }
};