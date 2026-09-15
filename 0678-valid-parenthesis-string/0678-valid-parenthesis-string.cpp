class Solution {
public:
    bool checkValidString(string s) {
         int n=s.length();
         stack<int>star;
         stack<int>st;
         for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                  if(st.empty()&&star.empty()) return false;  //isse ye vala handle ")"
                if(!st.empty()){
                    st.pop();
                }
                 else if(!star.empty()){
                    star.pop();
                }
               
               
            }
         }
         while(!st.empty()&&!star.empty()){
            if(star.top()<st.top()) return false;
            st.pop();
            star.pop();

         }
          return st.empty();
    }
};