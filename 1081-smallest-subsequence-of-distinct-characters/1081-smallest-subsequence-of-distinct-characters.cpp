class Solution {
public:
    string smallestSubsequence(string s) {
          int n=s.length();
         unordered_map<char,int>mp;
         for(auto it:s){
            mp[it]++;
         }
         unordered_map<char,bool>visited;
           stack<char>st;
        for(char c:s){
            mp[c]--;
             if(visited[c]==true) continue;
             while(!st.empty()&&st.top()>c&&mp[st.top()]>0){
                visited[st.top()]=false;
                st.pop();
             }
             st.push(c);
             visited[c]=true;
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};