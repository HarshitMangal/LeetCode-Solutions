class Solution {
public:
   string temp(int n){
    string s=to_string(n);
    sort(s.begin(),s.end());
    return s;
   }
    bool reorderedPowerOf2(int n) {
    string s=temp(n);
       //kul powe 31 he
       for(int i=0;i<=30;i++){
          int power=1<<i;
          if(temp(power)==s){
            return true;
          }

       }
       return false;
    }
};