class Solution {
public:
    // bool isvowel(string temp){
    //     int n=temp.length();
    //     unordered_set<char>st;
    //     for(char ch:temp){
    //         st.insert(ch);
    //     }
    //     if(st.size()!=5) return false;
    //     for(int i=1;i<n;i++){
    //         if(temp[i]<temp[i-1]) return false;
    //     }
    //     return true;
      
    // }
    int longestBeautifulSubstring(string s) {
        int n=s.length();
        int ans=0;
        int count=0;
        int len=0;
        for(int i=0;i<n;i++){
          
                if(i>0&&s[i]<s[i-1]) {
                    count=0;
                    len=0;
                    
                 }
                 len++;
                 if(i==0||s[i]!=s[i-1]) count++;
                 if(count==5){
                    ans=max(ans,len);
                 }
        }
        return ans;
        
    }
};