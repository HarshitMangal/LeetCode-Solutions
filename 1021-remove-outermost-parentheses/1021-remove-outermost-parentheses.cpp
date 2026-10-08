class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int count=0;
        string temp="";
        int index=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else count--;
            if(count==0){
                temp+=s.substr(index+1,i-index-1);
                index=i+1;
            }
        }
        return temp;
    }
};