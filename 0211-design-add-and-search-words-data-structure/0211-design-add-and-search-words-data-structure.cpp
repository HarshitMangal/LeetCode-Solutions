class WordDictionary {
public:

     struct TrieNode{
    bool isendofword;
    TrieNode*children[26];
  };
  TrieNode *getNode(){
    TrieNode*newNode=new TrieNode();
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    newNode->isendofword=false;
    return newNode;
  }

    TrieNode*root;
    WordDictionary() {
     root=getNode();
    }
    
    void addWord(string s) {
         TrieNode*crawler=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isendofword=true; 
    }
    bool helper(string s,TrieNode*root){
           int n=s.length();
        TrieNode*crawler=root;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->children[j]!=NULL){
                        if(helper(s.substr(i+1),crawler->children[j])) return true;
                    }
                    
                }
                return false;
            }
             if(crawler->children[s[i]-'a']==NULL) return false;
             crawler=crawler->children[s[i]-'a'];
        }
        return crawler->isendofword;
    }
    
    bool search(string s) {
       return helper(s,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */