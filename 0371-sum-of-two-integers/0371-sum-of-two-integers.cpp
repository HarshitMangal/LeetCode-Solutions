class Solution {
public:
  //simple tarike se karenge yar
    int getSum(int a, int b) {
    //isme yar 1,1 vale case me hinkarenge
    while(b!=0){
        int carry=(a&b)<<1;
        a=(a^b); //sum without carry;
        b=carry; // ab agle number per caarty de enge 
    }
    return a;
       

    }
};