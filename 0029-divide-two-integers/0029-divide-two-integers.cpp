class Solution {
public:
    int divide(int a, int b) {
           if (a == 0) return 0;
            // Handle overflow
    if(a == INT_MIN && b == -1)
		return INT_MAX;

        int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

        long long dividend = llabs(a);   // ✅ safe absolute value
        long long divisor  = llabs(b);   // ✅ safe absolute value

        long long quotient = 0;

        while (dividend >= divisor) {
            long long temp = divisor;
            long long multiple = 1;

            while ((temp << 1) <= dividend) {
                temp <<= 1;
                multiple <<= 1;
            }

            dividend -= temp;
            quotient += multiple;
        }

        return quotient * sign;
        
        
    }
};