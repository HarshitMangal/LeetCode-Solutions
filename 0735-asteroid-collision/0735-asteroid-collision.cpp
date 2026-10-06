class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool flag=false;
            while(!st.empty()&&st.top()>0&&nums[i]<0){
                if(st.top()==abs(nums[i])){
                    st.pop();
                    flag=true;
                    break;
                }
                else if(st.top()>abs(nums[i])){
                    flag=true;
                    break;
                }
                else if(st.top()<abs(nums[i])){
                    st.pop();
                }
            }
             if(flag==false)
             st.push(nums[i]);

        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};