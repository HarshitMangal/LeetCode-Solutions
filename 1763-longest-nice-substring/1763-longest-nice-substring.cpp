class Solution {
public:
   bool isnice(string &s){
    int n=s.length();
    unordered_set<char>st;
    for(char ch:s){
        st.insert(ch);
    }
    for(char ch:s){
        if(islower(ch)){
            if(st.find(toupper(ch))==st.end()) return false;
        }
        else{
            if(st.find(tolower(ch))==st.end()) return false;
        }
    }
    return true;

   }
    string longestNiceSubstring(string s) {
          int n=s.length();
           string ans="";
           for(int i=0;i<n;i++){
            string temp="";
              for(int j=i;j<n;j++){
                temp+=s[j];
                if(isnice(temp)){
                    if(temp.size()>ans.size()){
                        ans=temp;
                    }
                }

              }
           }
           return ans;

    }
};