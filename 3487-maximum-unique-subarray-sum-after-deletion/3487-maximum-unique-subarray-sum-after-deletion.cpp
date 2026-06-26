class Solution {
public:
    int maxSum(vector<int>& nums) {

        unordered_set<int> st;

        int sum = 0;
        int maxi = INT_MIN;

        for(int x : nums)
        {
            maxi = max(maxi, x);

            if(x > 0 && !st.count(x))
            {
                sum += x;
                st.insert(x);
            }
        }

        if(sum == 0)
            return maxi;

        return sum;
    }
};