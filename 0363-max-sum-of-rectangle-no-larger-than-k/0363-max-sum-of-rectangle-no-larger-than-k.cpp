class Solution {
public:
 int maxSubArraySum(vector<int>& arr, int k) {
    set<int> st;
    st.insert(0);

    int prefix = 0;
    int ans = INT_MIN;

    for(int x : arr) {
        prefix += x;

        auto it = st.lower_bound(prefix - k);

        if(it != st.end()) {
            ans = max(ans, prefix - *it);
        }

        st.insert(prefix);
    }

    return ans;
}
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        //isme 2d array jo ad me convert karnge
        int ans=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        for(int top=0;top<n;top++){
            vector<int>temp(m,0);
            for(int bottom=top;bottom<n;bottom++){
                for(int col=0;col<m;col++){
                    temp[col]+=mat[bottom][col];
                }
                ans=max(ans,maxSubArraySum(temp,k));

            }
        }
         return ans;
    }
};