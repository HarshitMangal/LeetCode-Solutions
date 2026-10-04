class WordDictionary {
public:
    struct TrieNode{
        TrieNode*children[26];
        bool isendofword;

    };
    TrieNode *getNode(){
        TrieNode *newNode=new TrieNode();
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
        int n=s.length();
        TrieNode*crawler=root;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isendofword=true;

        
    }
    bool solve(string &s,TrieNode*root,int idx){
        int n=s.length();
        TrieNode*crawler=root;
        for(int i=idx;i<n;i++){
            char ch=s[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    ch=j+'a';
                    if(crawler->children[ch-'a']!=NULL)
                    if(solve(s,crawler->children[ch-'a'],i+1)) return true;
                    // return false;


                }
            }
             if(crawler->children[ch-'a']==NULL) return false;
            crawler=crawler->children[ch-'a'];
        }
        if(crawler->isendofword==true) return true;
        return false;

    }
    
    bool search(string word) {
        int n=word.length();
        if(solve(word,root,0)) return true;
        return false;

        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */