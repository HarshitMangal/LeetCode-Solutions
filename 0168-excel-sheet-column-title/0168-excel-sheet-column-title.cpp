class Solution {
public:
    string convertToTitle(int col) {
        string temp="";
        int rem=0;
        while(col>0){
            col--;
             rem=col%26;
            temp+=(rem+'A');
            col/=26;

        }
        reverse(temp.begin(),temp.end());
        return temp;


        
    }
};