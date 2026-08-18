class Solution {
public:
   struct TrieNode{
     int count;
     TrieNode*children[26];
   };
   TrieNode*getNode(){
    TrieNode*newNode=new TrieNode();
    newNode->count=0;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;

   }
   TrieNode*root;
   void insert(string&s){
    TrieNode*crawler=root;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int idx=ch-'a';
        if(crawler->children[idx]==NULL){
            crawler->children[idx]=getNode();
        }
        crawler=crawler->children[idx];
        crawler->count++;
    }

   }
    vector<int> sumPrefixScores(vector<string>& words) {
        root=getNode();
        for(auto it:words){
            insert(it);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int sum=0;
            TrieNode*crawler=root;
            for(int i=0;i<s.length();i++){
                char ch=s[i];
                int idx=ch-'a';
                crawler=crawler->children[idx];
                sum+=crawler->count;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};