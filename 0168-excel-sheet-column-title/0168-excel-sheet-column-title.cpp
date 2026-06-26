class Solution {
public:
    string convertToTitle(int n) {
           string temp="";
        while(n!=0){
            int idx=(n%26);
            if(idx==0) {
                temp+='Z';
                n--;
            }
              else  temp+='A'+idx-1;
            n/=26;
        }
        reverse(temp.begin(),temp.end());

        return temp;
    }
};