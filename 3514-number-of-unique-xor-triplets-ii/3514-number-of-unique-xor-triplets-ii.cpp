class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;

        // all possible (i,j), i<=j
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairXor.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int> ans;

        // pair xor with every k
        for(auto x : pairXor){
            for(int k=0;k<n;k++){
                ans.insert(x ^ nums[k]);
            }
        }

        return ans.size();
    }
};