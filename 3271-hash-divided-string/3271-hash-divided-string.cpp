class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.length();
        string temp="";
         for(int i=0;i<n;i+=k){
             int sum=0;
             for(int j=i;j<i+k;j++){
                sum+=(s[j]-'a');
             }
             int rem=sum%26;
            temp.push_back(rem+'a');
         }
           return temp;
        
    }
};