class Solution {
public:

    struct TrieNode {
        bool isendofword;
        TrieNode* children[26];
    };

    TrieNode* getNode() {

        TrieNode* newNode = new TrieNode();

        newNode->isendofword = false;

        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    TrieNode* root;

    void insert(string s) {

        TrieNode* crawler = root;

        for(int i = 0; i < s.length(); i++) {

            int idx = s[i] - 'a';

            if(crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->isendofword = true;
    }

    string findRoot(string word) {

        TrieNode* crawler = root;

        string ans = "";

        for(int i = 0; i < word.length(); i++) {

            int idx = word[i] - 'a';

            if(crawler->children[idx] == NULL) {
                return word;
            }

            crawler = crawler->children[idx];

            ans += word[i];

            if(crawler->isendofword) {
                return ans;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        root = getNode();

        // Dictionary ko Trie me insert karo
        for(string s : dictionary) {
            insert(s);
        }

        string result = "";
        string word = "";

        // Sentence ke words manually nikalenge
        for(int i = 0; i <= sentence.length(); i++) {

            if(i == sentence.length() || sentence[i] == ' ') {

                // current word ka root find karo
                string rootWord = findRoot(word);

                // result me add karo
                if(result != "") {
                    result += " ";
                }

                result += rootWord;

                // next word ke liye empty
                word = "";
            }
            else {
                word += sentence[i];
            }
        }

        return result;
    }
};