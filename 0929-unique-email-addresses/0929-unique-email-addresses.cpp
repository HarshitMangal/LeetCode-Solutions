class Solution {
public:
    int numUniqueEmails(vector<string>& arr) {
        int n=arr.size();
        unordered_set<string>st;
        for(auto s:arr){
           string local="";
           string domain="";

           int i=0;
           while(s[i]!='@'){
            if(s[i]=='+') break;
            if(s[i]!='.'){
                 local+=s[i];
            }
           i++;
           }
           while(s[i]!='@') i++;
           i++;
           while(i<s.length()){
            domain+=s[i];
            i++;
           }
           string final=local+'@'+domain;
           st.insert(final);
        }
        return st.size();
    }
};