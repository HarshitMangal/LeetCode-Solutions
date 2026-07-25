class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n!=0){
            ans.push_back(n%10);
            n/=10;
        }
        sort(ans.rbegin(),ans.rend());
        return ans[0]*ans[1];
    }
};