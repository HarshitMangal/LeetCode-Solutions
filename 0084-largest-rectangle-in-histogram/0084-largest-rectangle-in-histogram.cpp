class Solution {
public:
    vector<int>nse(vector<int>&arr){
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
     vector<int> pse(vector<int>& arr) {
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
        vector<int>NSE=nse(arr);
        vector<int>PSE=pse(arr);
        int maxi=0;
        for(int i=0;i<n;i++){
            int left=PSE[i];
            int right=NSE[i]==-1?n:NSE[i];
            int width=right-left-1;
            int height=arr[i];
            maxi=max(maxi,height*width);

        }
        return maxi;
    }
};