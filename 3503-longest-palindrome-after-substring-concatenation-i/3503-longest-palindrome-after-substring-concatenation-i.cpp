class Solution {
public:

    bool isPalindrome(string &str){
        int i = 0;
        int j = str.size() - 1;

        while(i < j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int longestPalindrome(string s, string t) {

        int ans = 0;

        vector<string> subsS;
        vector<string> subsT;

        // empty substring
        subsS.push_back("");
        subsT.push_back("");

        // all substrings of s
        for(int i=0;i<s.size();i++){
            string cur="";
            for(int j=i;j<s.size();j++){
                cur += s[j];
                subsS.push_back(cur);
            }
        }

        // all substrings of t
        for(int i=0;i<t.size();i++){
            string cur="";
            for(int j=i;j<t.size();j++){
                cur += t[j];
                subsT.push_back(cur);
            }
        }

        for(auto &a : subsS){
            for(auto &b : subsT){

                string temp = a + b;

                if(isPalindrome(temp)){
                    ans = max(ans,(int)temp.size());
                }
            }
        }

        return ans;
    }
};