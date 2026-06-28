class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int>st;
        unordered_set<int>remove;
        for(int i=0;i<n;i++){
           if(s[i]=='('){
            st.push(i);
           }
           else if(s[i]==')'){
            if(st.empty()){
               remove.insert(i);
            } 
            else  st.pop();
           }
        }
        while(!st.empty()){
            remove.insert(st.top());
            st.pop();
        }
        string temp="";
        for(int i=0;i<n;i++){
            if(remove.find(i)==remove.end()){
                temp.push_back(s[i]);
            }
        }
        return temp;
    }
};