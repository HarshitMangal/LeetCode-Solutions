class Solution {
public:
    long long gcdSum(vector<int>& nums) {
         int n = nums.size();

        vector<int> prefixGcd;

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            maxi = max(maxi, nums[i]);

            prefixGcd.push_back(__gcd(nums[i], maxi));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n - 1;

        long long sum = 0;

        while(i < j) {

            sum += __gcd(prefixGcd[i], prefixGcd[j]);

            i++;
            j--;
        }

        return sum;


    }
};