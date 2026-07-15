class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumodd=0;
        long long sumeven=0;
        for(int i=1;i<=n;i++){
            sumodd+=(2*i-1);
        }
        for(int i=1;i<=n;i++){
            sumeven+=(2*i);
        }
        return std::gcd(sumodd,sumeven);
    }
};