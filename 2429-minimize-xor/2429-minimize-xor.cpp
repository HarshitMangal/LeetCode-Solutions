class Solution {
public:
     int countSetBits(int n) {
        int cnt = 0;

        while (n) {
            n = n & (n - 1);
            cnt++;
        }

        return cnt;
    }

    int minimizeXor(int num1, int num2) {
         
        int cnt = countSetBits(num2);

        int ans = 0;
        //mssb se lsb pe dekhn he num1 pe yar
        for(int i=31;i>=0;i--){
            int ithbit=(num1>>i)&1;
            if(ithbit==1&&cnt>0){
            ans|=1<<i;  //us position me 1 dal dibga me
            cnt--;
            }
        }
        for(int i=0;i<32&&cnt>0;i++){
           if (((ans >> i) & 1) == 0) {
                ans |= (1 << i);
                cnt--;
            }
        }
        return ans;

    }
};