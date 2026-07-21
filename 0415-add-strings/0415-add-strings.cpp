class Solution {
public:
    string addStrings(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int carry=0;
        int i=n-1;
        int j=m-1;
        string temp="";
        while(i>=0||j>=0||carry!=0){

          int val1=(i>=0)?s1[i]-'0':0;
          int val2=(j>=0)? s2[j]-'0':0;
          int sum=val1+val2+carry;
          temp+=to_string(sum%10);
          carry=(sum/10);
          i--;
          j--;
        }
        reverse(temp.begin(),temp.end());
        return temp;

        
    }
};