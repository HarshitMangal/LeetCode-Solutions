class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
           string ans=s;
           queue<string>q;
           unordered_set<string>visited;
           visited.insert(s);
           q.push(s);
           while(!q.empty()){
            string curr=q.front();
            q.pop();
            ans=min(ans,curr);
            //ab 2 case 

            string add=curr;
            for(int i=1;i<add.length();i+=2){
                int num=add[i]-'0';
                num=(num+a)%10;
                add[i]=num+'0';
            }
            if(!visited.count(add)){
                visited.insert(add);
                q.push(add);
            }
            //case 2 rotate
             int n=curr.length();
            string rotate=curr.substr(n-b)+curr.substr(0,n-b);
            if(!visited.count(rotate)){
                q.push(rotate);
                visited.insert(rotate);
            }
            

           }
           return ans;

    }
};