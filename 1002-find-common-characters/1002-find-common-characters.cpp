class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        vector<int>fre(26,0);
        for(auto it:words[0]){
            fre[it-'a']++;
        }
        for(int i=1;i<n;i++){
            vector<int>fre1(26,0);
            for(auto it:words[i]){
                fre1[it-'a']++;
            }
            for(int j=0;j<26;j++){
                fre[j]=min(fre[j],fre1[j]);
            }
        }
       
         for(int i=0;i<26;i++){
           while(fre[i]--){
            ans.push_back(string(1,char(i+'a')));
           }
         }
         return ans;
    }
};