class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        int n=s.length();
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
           for(int j=0;j<n;j++){
            if(s[j]==c){
                if(abs(i-j)<mini){
                    mini=abs(i-j);
                }
            }
           }
           ans.push_back(mini);
        }
        return ans;
    }

};