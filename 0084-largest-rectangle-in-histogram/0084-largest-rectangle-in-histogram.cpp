class Solution {
public:

    vector<int> nextSmallerEle(vector<int>& arr) {
         int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){
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

    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre=prevSmaller(arr);
        vector<int>next=nextSmallerEle(arr);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           int p=pre[i];
           int r=next[i]==-1?n:next[i];
           maxi=max(maxi,arr[i]*(r-p-1));
        }
        return maxi;


    }
};