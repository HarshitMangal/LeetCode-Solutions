class Solution {
public:

    bool isVowel(char ch){

        return ch=='a' || ch=='e' || 
               ch=='i' || ch=='o' || 
               ch=='u';
    }


    long long countOfSubstrings(string word, int k) {

        int n = word.size();
        long long ans = 0;


        for(int i=0; i<n; i++){

            unordered_map<char,int> mp;
            int consonant = 0;


            for(int j=i; j<n; j++){

                if(isVowel(word[j])){
                    mp[word[j]]++;
                }
                else{
                    consonant++;
                }


                if(mp.size()==5 && consonant==k){
                    ans++;
                }
            }
        }

        return ans;
    }
};