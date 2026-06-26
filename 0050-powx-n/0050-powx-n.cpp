class Solution {
public:
    double solve(double x,long long n){
        if(n==0) return 1;
        if(n<0) return solve(1/x,-n);
        double ans=solve(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};