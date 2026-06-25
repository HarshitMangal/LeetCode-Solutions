class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n=s1.length();
        if(s1==s2) return 0;
        queue<pair<string ,int>>q; //isme string ,steps dalenge
        unordered_set<string>vis;
        q.push({s1,0});
        vis.insert(s1);
        while(!q.empty()){
            pair<string ,int>temp=q.front();
            q.pop();
            string ans=temp.first;
            int step=temp.second;
            if(ans==s2) return step;
            //pahle mismatch character nikalnege
            int i=0;
            while(ans[i]==s2[i]) i++;
            for(int j=i+1;j<n;j++){
                if(ans[j]==s2[i]&&ans[j]!=s2[j]){
                    string next=ans;
                    swap(next[i],next[j]);
                    if(!vis.count(next)){
                        vis.insert(next);
                        q.push({next,step+1});
                    }
                }
            }
        }
         return -1;
    }
};