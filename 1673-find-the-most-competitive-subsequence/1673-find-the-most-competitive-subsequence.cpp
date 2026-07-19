class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
          vector<int>ans;
           stack<int>st;
           int ans1=n-k;
           for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()>nums[i]&&ans1!=0){
                  st.pop();
                  ans1--;
            }
                st.push(nums[i]);
           }
           while (ans1> 0) {
                st.pop();
                 ans1--;
            }
           while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
           }
           reverse(ans.begin(),ans.end());
           return ans;
    }
};