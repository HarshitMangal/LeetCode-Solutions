class MapSum {
public:

    struct TrieNode {
        int value;
        TrieNode* children[26];
    };

    TrieNode* getNode() {

        TrieNode* newNode = new TrieNode();

        newNode->value = 0;

        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    TrieNode* root;

    MapSum() {
        root = getNode();
    }

    void insert(string key, int val) {

        TrieNode* crawler = root;

        for(int i = 0; i < key.length(); i++) {

            char ch = key[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->value = val;
    }

    int sum(string prefix) {

        TrieNode* crawler = root;

        // prefix tak jao
        for(int i = 0; i < prefix.length(); i++) {

            char ch = prefix[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL) {
                return 0;
            }

            crawler = crawler->children[idx];
        }

        // prefix ke neeche saari values ka sum
        return dfs(crawler);
    }

    int dfs(TrieNode* crawler) {

        int ans = crawler->value;

        for(int i = 0; i < 26; i++) {

            if(crawler->children[i] != NULL) {
                ans += dfs(crawler->children[i]);
            }
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */